#ifndef BACKWARDCHAIN_H
#define BACKWARDCHAIN_H
#include<string>
using namespace std;


class BackwardChain
{
    public:
        BackwardChain();
        virtual ~BackwardChain();
        const int CONCLUSION=10;
        const int VARIABLES=10;
        const int CLAUSE=40;
        string conclt[11];
        /*  variable list */
        string varlt[11];
        /*  clause vairable list */
        string clvarlt[40];
        string varble;
        string /* qualify */ qu, /* degree*/ de;
        string/* discovery */ di, /* position */ po;
        string buff;
        int instlt[11];
        /* statement stack */
        int statsk[11];
        int /* clause stack */ clausk[11], sn, f, i, j, s, k, /*stack pointer */ sp;

        float /* grade */ gr, /*experience */ ex;

        void determine_member_concl_list(void);
        void push_on_stack(void);
        void instantiate(void);
        void inferenceEngine();
        int KnowledgeBase(int,int);
        //void process();
        void process2();



    protected:

    private:
};

#endif // BACKWARDCHAIN_H
