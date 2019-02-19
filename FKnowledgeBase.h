#ifndef FKNOWLEDGEBASE_H
#define FKNOWLEDGEBASE_H
#include<string>
#include<iostream>
using namespace std;


class FKnowledgeBase
{
    public:
        FKnowledgeBase();
        virtual ~FKnowledgeBase();
        bool inst=false;
        int flag;
        static const int size=61; /* variable size */
        static const int cvsize=182; /* clause variables size */
        static const int nocases=60; /* no of if cases */
        string cndvar[nocases];
        string varlt[size], /* variable list*/ clvarlt[cvsize]; /* clause var list */
        string c, vp, /* condition variable */  v; /*variable */
        //string fedint, interest[10], stock[10], dollar[10], fedmon[10];
       //string po[10], /* position */  qu[10]; /* qualify */
        string profession, interest, Area;
        int instlt[size];         /* instantiated list*/
        int f, i, j, k, s, fp   /* front pointer */;
        int  bp  /* back pointer */,  gr /* grade */,  sn; /* statement number */
        int cn;  /* clause number */
        char buff[256];

        string electrical, computer, civil, petrolium, aerospace, zoology, geology, physics,chemistry, botany, accounting;
        string finance, marketing, real_estate, sales, oncologist, orthopedic, cardiologist, neurologist, dentist, novel, composition;
        string drama, poetry,writing, human_geo, physical_geo, globalization, gis, geopolitics, cognitive, abnormal, social, personality, physiological;
        string agronomy, horticulture, agri_eng, agri_eco, animal_sci, nursing, h_service_man, h_admin, physician;
        string public_h, teaching, counselling, admin, curriculum, recreation;
        string engineering, science, business, medical, english, geography, psychology, agriculture, health_care, education;

        // Functions
        void startKB();
        void ifKB();
        void thenKB();
        void instantiateKB();

    protected:
    private:
};

#endif // FKNOWLEDGEBASE_H
