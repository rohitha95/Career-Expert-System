#include "ForwardChain.h"


void ForwardChain::display()
{
    cout<<endl<<"**************************"<<endl;
    cout<<"Printing Conclusion Variable Queue";
    cout<<endl<<"**************************"<<endl;
    bool flag = true;
    for(int i1 = 1; i1 < fk.size; i1++)
    {
        if(fk.cndvar[i1] != "")
        {
            cout<<"| "<<fk.cndvar[i1]<<" |";
            flag = false;
            cout<<endl;
        }
    }
    if(flag)
    {
        cout<<"No elements in Conclusion Variable Queue";
        cout<<endl<<"**************************"<<endl;
    }
    else
    {
        cout<<endl<<"**************************"<<endl;
    }
}

void ForwardChain::start(string t)
{
    fk.startKB();
    inference(t);

    //display();
    process();

}
void ForwardChain::check_instantiation()
{
    fk.i=1;

    /* find variable in the variable list */
    while ((fk.v != fk.varlt[fk.i]) && (fk.i < fk.size))
        fk.i = fk.i+1;
    /* check if already instantiated */

    if (fk.instlt[fk.i] != 1)
    {

        /* mark instantiated */
        fk.instlt[fk.i] = 1;
        /* the designer of this knowledge base places the input
        statements to instantiate the variables in this case
        statement */
        fk.instantiateKB();
    }
}

void ForwardChain::instantiate()
{
    fk.i=1;
   // cout<<"variable "<<fk.v<<endl;
    /* find varialbe in the varialbe list (varlt) */
    while ((fk.v != fk.varlt[fk.i]) && (fk.i < fk.size))
        fk.i=fk.i+1;
    //cout<<fk.i<<endl;
    /* instantiate it */
    fk.instlt[fk.i] = 1;


            fk.i = 1;
    /* determine if (v) is or already has been on the queue (cndvar) */
    while ((fk.v != fk.cndvar[fk.i]) && (fk.i < fk.size))
        fk.i=fk.i+1;

    /* variable has not been on the queue. Store it in the back of the queue */
    if (fk.v != fk.cndvar[fk.i])
    {
        fk.cndvar[fk.bp] = fk.v;
        fk.bp=fk.bp+1;
       // cout<<fk.i<<endl;
    }

}

void ForwardChain::inference(string ft)
{
    //cout<<"Inference called with value:"<<ft<<endl;
    cout<<endl;
    fk.fp=1;
    fk.bp=1;
    /****** INFERENCE SECTION *****************/
    /*
    printf("ENTER CONDITION VARIABLE? ");
    cin>>c;
    */
    fk.c = "profession";
    fk.profession = ft;
    //fk.instlt[1] = 1;
    /* place condition variable c on condition var queue cndvar */
    fk.cndvar[fk.bp] = fk.c;
    /* move backpointer (bp) to back */
    fk.bp = fk.bp + 1;
    /* set the condition variable pointer consisting of the
    statement number (sn) and the clause number (cn) */
    fk.sn = 1;
    fk.cn = 1;
    /* find the next statement number containing the condition variable
    which is in front of the queue (cndvar), this statement number
    is located in the clause variable list (clvarlt) */
    /* start at the beginning */
    fk.f=1;
}

void ForwardChain::process()
{

    search();

    /* point to first clause in statement */
    fk.cn=1;

    if (fk.sn != 0)/* more statements */
    {

        /* locate the clause */
        fk.i = 3 * (fk.sn-1) + fk.cn;
        /* clause variable */
        fk.v = fk.clvarlt[fk.i];
        /* are there any more clauses for this statement */

        while (fk.v != "")
            /* more clauses */
        {
            /* check instantiation of this clause */
            check_instantiation();
            fk.cn = fk.cn+1;
            /* check next clause */
            fk.i = 3 * (fk.sn-1) + fk.cn;
            fk.v = fk.clvarlt[fk.i];
            //cout<<fk.v<<endl;
        }


        /* no more clauses - check IF part of statement */
        fk.s = 0;
        fk.ifKB();


        /* see if the THEN part should be inovked, i.e., s=1 */
        if (fk.s != 1)
        {

            fk.f = fk.sn + 1;
            process();

        }


        fk.thenKB();
        if(fk.inst)
        {
            instantiate();
            fk.inst = false;
        }else {
            fk.fp=fk.fp+1;
        }
        fk.f = fk.sn + 1;
        process();
    }

    /* no more clauses in the clause variable list (clvarlt)
    containing the variable in front of the queue (cndvar(fp))
    then remove front variable (cndvar(fp)) and replace it by
    the next variable (cndvar(fp+1)). If no more variables are
    at the front of the queue, stop. */
    /* next queue variable */
    fk.fp=fk.fp+1;
    if (fk.fp < fk.bp)
    {
        /* check out the condition variable */
        fk.f = 1;
        process();
    }
    /* no more conclusion variables on queue */
    //cout<<"*** Success ***"<<endl;

   // exit(0);
}

void ForwardChain::search()
{

    fk.flag = 0;
    fk.sn = fk.f;
    //while ((fk.flag == 0) && (fk.sn <= (fk.csize-1)/4))

    while ((fk.flag == 0) && (fk.sn < fk.nocases))
    {

        fk.cn=1;
        fk.k = (fk.sn-1)*3+fk.cn;
        //cout<<"condition var"<<fk.cndvar[fk.fp]<<endl;
        while ((fk.clvarlt[fk.k] != fk.cndvar[fk.fp]) && (fk.cn < 3) )
        {
            //cout<<"clause "<<fk.k<<fk.clvarlt[fk.k]<<endl;
            fk.cn = fk.cn+1;
            fk.k = (fk.sn-1)*3+fk.cn;
        }

        if ((fk.clvarlt[fk.k] == fk.cndvar[fk.fp]) && (fk.cndvar[fk.fp]!=""))
            fk.flag = 1;
        if (fk.flag == 0)
            fk.sn = fk.sn+1;
    }
    if ( fk.flag == 0)
        fk.sn=0;
    //cout<<"stat in search"<<fk.sn<<endl;

}
string ForwardChain::getArea() {
return fk.Area;
}
