#ifndef FORWARDCHAIN_H
#define FORWARDCHAIN_H
using namespace std;
#include "FKnowledgeBase.h"


class ForwardChain
{
    public:
        ForwardChain();
        virtual ~ForwardChain();
        FKnowledgeBase fk;
        void search();
		void check_instantiation();
		void instantiate();
		void inference(string);
		void process();
        void start(string);
        void display();
        string getArea();
    protected:
    private:
};

#endif // FORWARDCHAIN_H
