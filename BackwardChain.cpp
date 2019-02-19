#include "BackwardChain.h"
#include<iostream>
#include<fstream>
#include<string>

string BackwardChain::getProfession(){
    return kb.Profession;
}

void BackwardChain::determine_member_concl_list() {
    /* routine to determine if a variable (varble) is a member of the
   conclusion list (conclt).  if yes return sn != 0.
   if not a member sn=0;
*/
        /* initially set to not a member */
        kb.sn = 0;
        /* member of conclusion list to be searched is f */
        kb.i = kb.f;

        while((kb.varble!=kb.conclt[kb.i]) && (kb.i<kb.noofcases)) {

                //cout<<"no. of cases"<<kb.noofcases<<" varble "<<kb.varble<<endl;
                //cout<<" i value in con "<<kb.i<<" "<<kb.conclt[kb.i]<<endl;
                kb.i=kb.i+1;
        }

        if (kb.varble.compare(kb.conclt[kb.i]) == 0) kb.sn = kb.i;  /* a member */
}

void BackwardChain::push_on_stack()
/* routine to push statement number (sn) and a clause number of 1 onto the
conclusion stack which consists of the statement stack (statsk) and the
clause stack (clausk)..to push decrement stack pointer (sp) */
{
        kb.sp=kb.sp-1;
        kb.statsk[kb.sp] = kb.sn;
        kb.clausk[kb.sp] = 1;
}

void BackwardChain::instantiate()
/* routine to instantiate a variable (varble) if it isn't already.  the
instantiate indication (instlt) is a 0 if not, a 1 if it is.  the
variable list (varlt) contains the variable (varble). */
{
       kb.i=1;
        /* find variable in the list */
        while((kb.varble.compare(kb.varlt[kb.i]) != 0) && (kb.i<kb.size)) kb.i=kb.i+1;
        if((kb.varble.compare(kb.varlt[kb.i]) == 0) && (kb.instlt[kb.i] != 1))
                /*found variable and not already instantiated */
        {
                kb.instlt[kb.i]=1; /*mark instantiated */
                /* the designer of the
               knowledge base places the input statements to
               instantiate the variables below in the case statement */
              kb.initkbase();
        }
}


void BackwardChain::inferenceEngine() {
    kb.initialization();
    cout<<"Knowledge base initiated...."<<endl;
    cout<<"** ENTER CONCLUSION ? "<<endl;
    getline(cin,kb.varble);
    kb.f=1;
    determine_member_concl_list();
    if (kb.sn!=0) {
             /* if sn = 0 then no conclusion of that name */
                  /* push statement number (sn) and clause number=1 on
goal
                     stack which is composed of the statement stack
(statsk)
                     and clause stack (clausk) */

        push_on_stack();
        while(kb.sp<kb.size)  {
            do {
                     /* calculate clause location in clause-variable
                              list */
                 kb.i= (kb.statsk[kb.sp] -1) *3 + kb.clausk[kb.sp];

                kb.varble=kb.clvarlt[kb.i];


                if(kb.varble.compare("") != 0) {
                        /*is this clause variable a conclusion? */
                    kb.f = 1;
                    determine_member_concl_list();
                    if(kb.sn != 0 ) {
                         /* it is a conclusion push it */
                            push_on_stack();
                            continue;
                    }
                /* check instantiation of this clause */

                    instantiate();
                    kb.clausk[kb.sp] = kb.clausk[kb.sp] + 1;
                }
            } while(kb.varble.compare("") != 0);  /*do-while*/
            /*no more clauses check if part of statement */
            kb.sn = kb.statsk[kb.sp];
            kb.s = 0;

                          /*   Calling Knowledge Base IF part */
            kb.ifkbase();
             /* see if the then part should be invoked */
            if( kb.s != 1) {
                     /* failed..search rest of statements for
                                     same conclusion */
                                  /* get conclusion */
                kb.i = kb.statsk[kb.sp];
                kb.varble=kb.conclt[kb.i];
                /* search for conclusion starting at the
                                    	 next statement number */
                kb.f = kb.statsk[kb.sp] + 1;
                //kb.sp = kb.sp+1;

                determine_member_concl_list();
                 /* pop old conclusion and put on new one */
                kb.sp = kb.sp+1;

                if ( kb.sn!=0 && kb.s!=1) {
                    push_on_stack();
                    continue;
                }
            }
            if(kb.sn != 0){
                    /* THEN statements */
                kb.thenkbase();
                 /* pop old conclusion and put on new one */
                kb.sp=kb.sp+1;

            }
            /* get next clause then continue */
            kb.clausk[kb.sp] = kb.clausk[kb.sp]+1;
        }
    }
}
