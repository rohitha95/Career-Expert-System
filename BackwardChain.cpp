#include "BackwardChain.h"
#include<iostream>

BackwardChain::BackwardChain()
{
        cout<<"************Backward Chaining***********"<<endl;
        sp=11;
        for (int m=1; m<11; m++) {
            conclt[m]="";
            varlt[m]="";
            instlt[m]=0;
            statsk[m]=0;
            clausk[m]=0;
        }
        for (i=1; i<41; i++)
            clvarlt[i]="";


        /* enter conclusions which are the variables in the then part,
1 at
        a time.  enter the conclusions in exact order starting at the 1st
        if-then.  after last conclusion hit return key for rest of
        conclusions */

        /*** comment 305 *****/
        conclt[1]="PO";
        conclt[2]= "QU";
        conclt[3]="PO";
        conclt[4]="PO";
        conclt[5]= "PO";
        conclt[6]= "PO";

        varlt[1]="DE";
        varlt[2]="DI";
        varlt[3]= "EX";
        varlt[4]= "GR";

         clvarlt[1]= "DE";
        clvarlt[5]="DE";
        clvarlt[9]= "DE";
        clvarlt[10]= "DI";
        clvarlt[13]="QU";
        clvarlt[14]="GR";
        clvarlt[15]="EX";
        clvarlt[17]="QU";
        clvarlt[18]="GR";
        clvarlt[19]= "EX";
        clvarlt[21]= "QU";
        clvarlt[22]= "GR";
}

BackwardChain::~BackwardChain()
{
    //dtor
}
void BackwardChain::determine_member_concl_list() {
    /* routine to determine if a variable (varble) is a member of the
   conclusion list (conclt).  if yes return sn != 0.
   if not a member sn=0;
*/
        /* initially set to not a member */
        sn = 0;
        /* member of conclusion list to be searched is f */
        i = f;
        while((varble.compare(conclt[i]) != 0) && (i<8))
                /* test for membership */
                i=i+1;
        if (varble.compare(conclt[i]) == 0) sn = i;  /* a member */
}

void BackwardChain::push_on_stack()
/* routine to push statement number (sn) and a clause number of 1 onto the
conclusion stack which consists of the statement stack (statsk) and the
clause stack (clausk)..to push decrement stack pointer (sp) */
{
        sp=sp-1;
        statsk[sp] = sn;
        clausk[sp] = 1;
}

void BackwardChain::instantiate()
/* routine to instantiate a variable (varble) if it isn't already.  the
instantiate indication (instlt) is a 0 if not, a 1 if it is.  the
variable list (varlt) contains the variable (varble). */
{
        i=1;
        /* find variable in the list */
        while((varble.compare(varlt[i]) != 0) && (i<10)) i=i+1;
        if((varble.compare(varlt[i]) == 0) && (instlt[i] != 1))
                /*found variable and not already instantiated */
        {
                instlt[i]=1; /*mark instantiated */
                /* the designer of the
               knowledge base places the input statements to
               instantiate the variables below in the case statement */
                switch (i)
                {
                        /***** input statement *****/
                        /* input statements for sample position knowledge
                           base */
                        /***** comment 1700 ******/
                case 1: cout<<"INPUT YES OR NOW FOR DE-? "<<endl;
                        getline(cin, de);
                        break;
                case 2: cout<<"INPUT YES OR NO FOR DI-? "<<endl;
                        getline(cin, di);
                        break;
                case 3: cout<<"INPUT A REAL NUMBER FOR EX-? "<<endl;
                        cin>>ex;
                        break;
                case 4: cout<<"INPUT A REAL NUMBER FOR GR-? "<<endl;
                        cin>>gr;
                        break;
                        /***** comment 1715 ****/
                }
                /* end of inputs statements for sample position knowledge
                   base */
        }
}
int BackwardChain::KnowledgeBase(int st,int p){
               if (p==1){
                        switch (st) {
                                  /* if part of statement 1 */
                                  /****** comment 1500 ****/
                          case 1: if(de.compare("NO") == 0)
                                return 1;
                                  break;
                                  /* if part of statement 2 */
                                  /***** comment 1510 ******/
                          case 2: if(de.compare("YES") == 0)
                                    return 1;
                                  break;
                                  /* if part of statement 3 */
                          case 3: if((de.compare("YES") == 0) &&
                                     (di.compare("YES") == 0))
                                     return 1;
                                  break;
                                  /* if part of statement 4 */
                                  /******** comment 1560 ******/
                          case 4: if((qu.compare("YES") == 0) &&
                                     (gr<3.5) && (ex >= 2))
                                     return 1;
                                  break;
                                  /******** comment 1570 ********/
                                  /* if part of statement 5 */
                          case 5: if((qu.compare("YES") == 0) &&
                                     (gr<3) && (ex<2))
                                     return 1;
                                  break;
                                  /* if part of statement 6 */
                          case 6: if((qu.compare("YES") == 0) &&
                                     (gr >=3.5))
                                     return 1;

                                  break;
                                  /********* comment 1680 ******/
                          }
               }else{
                           switch (sn) {
                                  /* then part of statement 1 */
                                  /******* comment 1500 *******/
                          case 1: po="NO";
                                  cout<<"PO=NO"<<endl;
                                  break;
                                  /* then part of statement 2 */
                                  /****** comment 1510 ******/
                          case 2: qu= "YES";
                                  cout<<"QU=YES"<<endl;
                                  break;
                                  /* then part of statement 3 */
                          case 3: po="YES";
                                  cout<<"PO=RESEARCH"<<endl;
                                  break;
                                  /* then part of statement 4 */
                                  /******** comment 1560 ******/
                          case 4: po= "YES";
                                  cout<<"PO=SERVICE ENGINEER"<<endl;
                                  break;
                                  /* then part of statement 5 */
                                  /****** comment 1570 *****/
                          case 5: po="NO";
                                  cout<<"PO=NO"<<endl;
                                  break;
                                  /* then part of statement 6 */
                          case 6: po="YES";
                                  cout<<"PO=PRODUCT ENGINEER"<<endl;
                                  break;
                                  /****** comment 1680 ********/
                          }
               }
                          return 0;
}
/*void BackwardChain::process2() {
    do {
                    b545: i= (statsk[sp] -1) *4 + clausk[sp];
          /* clause variable
                    varble=clvarlt[i];
                    if(varble.compare("") != 0) {
                  /*is this clause variable a conclusion?
                        f = 1;
                        determine_member_concl_list();
                        if(sn != 0) {
                                push_on_stack();
                                process2();
                        }
                  /* check instantiation of this clause
                  instantiate();
                  clausk[sp] = clausk[sp] + 1;
          }
          } while(varble.compare("") != 0);
}

void BackwardChain::inferenceEngine() {
    /****** inference section ****
    cout<<"** ENTER CONCLUSION ? "<<endl;
    getline(cin,varble);
        /* get conclusion statement number (sn) from the conclusion list
           (conclt) */
        /* first statement starts search
    b520: f=1;
    determine_member_concl_list();
    if (sn != 0){

        do {
                push_on_stack();
                //while (sp<11) {
                process2();
                          sn = statsk[sp];
                          s = 0;
                          s=KnowledgeBase(sn,1);
                          if( s != 1) {
                                  /* failed..search rest of statements for
                                     same conclusion */
                                  /* get conclusion
                                  i = statsk[sp];
                                  varble=conclt[i];
                                  /* search for conclusion starting at the
                                     next statement number
                                  f = statsk[sp] + 1;
                                  determine_member_concl_list();
                                  sp = sp+1;
                          }
                          /* pop old conclusion and put on new one //
                  } while((s != 1) && (sn !=0));
                  if(sn != 0){
                     int s1=KnowledgeBase(sn,2);
                     sp=sp+1;
                          if(sp >= 11)
                                  /* finished
                                  cout<<"*** SUCCESS\n";
                          else {
                                  /* stack is not empty */
                                  /* get next clause then continue
                                  clausk[sp] = clausk[sp]+1;
                                   process2();//goto b545;
                          }
                  }
        }



} */

void BackwardChain::inferenceEngine() {
    cout<<"** ENTER CONCLUSION ? "<<endl;
    getline(cin,varble);
    f=1;
    determine_member_concl_list();
    if (sn!=0) {
        push_on_stack();
        while(sp<11)  {
            do {
                b545: i= (statsk[sp] -1) *4 + clausk[sp];
                varble=clvarlt[i];

                if(varble.compare("") != 0) {
                    f = 1;
                    determine_member_concl_list();
                    if(sn != 0) {
                            push_on_stack();
                            continue;
                    }

                    instantiate();
                    clausk[sp] = clausk[sp] + 1;
                }
            } while(varble.compare("") != 0);
            sn = statsk[sp];
            s = 0;
            s=KnowledgeBase(sn,1);
            if( s != 1) {
                i = statsk[sp];
                varble=conclt[i];
                /* search for conclusion starting at the
                                    	 next statement number */
                f = statsk[sp] + 1;
                determine_member_concl_list();
                sp = sp+1;
                if ( sn!=0 && s!=1) {
                    push_on_stack();
                    continue;
                }
            }
            if(sn != 0){
                int s1=KnowledgeBase(sn,2);
                sp=sp+1;
            }
            clausk[sp] = clausk[sp]+1;
        }
    }
}

