//Driver file
#include<iostream>
#include<BackwardChain.h>
#include<FKnowledgeBase.h>
#include "ForwardChain.h"
int main() {
        cout<<"Backward Chaining starts.............."<<endl;
        BackwardChain *b=new BackwardChain();
        b->inferenceEngine();

        cout<<endl;
        cout<<"Forward Chaining starts..............."<<endl;
        cout<<endl;
        ForwardChain fir;
        fir.start(b->getProfession());
        cout<<endl;
        if (fir.getArea()=="")
            cout<<"UnKnown Area"<<endl;
        else
            cout<<"Specific Area is "<<fir.getArea()<<endl;
}

