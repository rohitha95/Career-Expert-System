#ifndef KNOWLEDGEBASE_H
#define KNOWLEDGEBASE_H
#include<string>
#include<iostream>
using namespace std;

class KnowledgeBase
{
    public:
        KnowledgeBase();
        ~KnowledgeBase();
		//Variables declaration
        static const int size = 24;//variable count
        static const int clauseSize = 103;//clause size
        int noofcases = 35;
        string conclt[35], varlt[size], clvarlt[clauseSize];
        string /* qualify */ qu, /* degree*/ de;
        string/* discovery */ di, /* position */ po;
        string career, Profession, engineering, Engineering, science, Science, business, Business, english, English, geography;
        string Geography, psychology, Psychology, agriculture, Agriculture, medical, Medical, health_care, Health_care, education;
        string Education, Career;
        float ex,gr;

		string varble;
        char buff[256];
        int instlt[size];
        int statsk[size], clausk[size], sn, f, i, j, s, k, sp;
		//int noofcases = 35;  //no of cases in ifkbase() + 1
        //Functions
        void initialization();
    	void initkbase();
    	void ifkbase();
    	void thenkbase();

};

#endif // KNOWLEDGEBASE_H
