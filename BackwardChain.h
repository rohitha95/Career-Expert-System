#ifndef BACKWARDCHAIN_H
#define BACKWARDCHAIN_H
#include<string>
using namespace std;
#include<KnowledgeBase.h>


class BackwardChain
{
    public:
        BackwardChain();
        virtual ~BackwardChain();
        void determine_member_concl_list(void);
        void push_on_stack(void);
        void instantiate();
        string getProfession();

        void inferenceEngine();

        //void process();

        KnowledgeBase kb;


    protected:

    private:
};

#endif // BACKWARDCHAIN_H
