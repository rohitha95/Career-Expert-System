#include "FKnowledgeBase.h"
#include<fstream>



void FKnowledgeBase::startKB(){
    /* ************* INITIALIZATION SECTION ************ */
    for (i=1;i <= cvsize; i++)
        clvarlt[i] = "";
    for (i=1;i <= size; i++)
    {
        cndvar[i] = "";
        varlt[i] = "";
        instlt[i] = 0;
    }
    /* enter variables which are in the IF part, 1 at a time in
    the exact order that they occur. Up to 3 variables per
    IF statement. Do not duplicate any variable names. Any
    name is used only once. If no more variables left, just
    hit return key */

    ifstream fin;
    fin.open("Fvar.txt");
    for(int i=1;i<=size;i++)
    {
        fin>>varlt[i];
    }
    fin.close();
   /* cout<<"*** VARIABLE LIST ***"<<endl;
    for (i=1; i<=size; i++)
    {
        cout<<"VARIABLE "<<i<<" "<<varlt[i]<<endl;
    }
    cout<<endl;

    cout<<"HIT RETURN TO CONTINUE";
    gets(buff); */
    /* enter variables as they appear in the IF clauses, Up to 3
    variables per IF statement. If no more variables left, just
    hit return key */

    //Initializing clause variable list
    fin.open("FclauseVar.txt");
    for(int i = 1; i <= cvsize; i++)
    {
        string temp;
        fin>>temp;
        if(temp == "s")
        {
            clvarlt[i] = "";
        }
        else
            clvarlt[i] = temp;
    }


   /* printf("*** CLAUSE-VARIABLE LIST ***\n");
    for (i = 1; i <= nocases ; i++)
    {
        printf("** CLAUSE %d\n", i);
        for (j = 1; j < 4; j++)
        {
            k = 3 * (i - 1) + j;
            cout<<"VARIABLE "<<j<< " "<<clvarlt[k]<<endl;
        }

        if (i==10)
        {
            cout<<"HIT RETURN TO CONTINUE";
            gets(buff);
        }
    }
    cout<<endl; */


}

void FKnowledgeBase::ifKB() {
    /* ********* IF part ******** */
        switch(sn) {

            case 1: if (profession=="Engineering" )
                    s = 1;
                    break;
            case 2: if (profession=="Science" )
                    s = 1;
                    break;
            case 3: if (profession=="Business" )
                    s = 1;
                    break;
            case 4: if (profession=="Medical" )
                    s = 1;
                    break;
            case 5: if (profession=="English" )
                    s = 1;
                    break;
            case 6: if (profession=="Geography" )
                    s = 1;
                    break;
            case 7: if (profession=="Psychology" )
                    s = 1;
                    break;
            case 8: if (profession=="Agriculture" )
                    s = 1;
                    break;
            case 9: if (profession=="Health_care" )
                    s = 1;
                    break;
            case 10: if (profession=="Education" )
                    s = 1;
                    break;

            case 11: if (engineering=="yes" && electrical=="yes")
                    s = 1;
                    break;
            case 12: if (engineering=="yes" && computer=="yes")
                    s = 1;
                    break;
            case 13: if (engineering=="yes" && civil=="yes")
                    s = 1;
                    break;
            case 14: if (engineering=="yes" && petrolium=="yes")
                    s = 1;
                    break;
            case 15: if (engineering=="yes" && aerospace=="yes")
                    s = 1;
                    break;
            case 16: if (science=="yes" && zoology=="yes")
                    s = 1;
                    break;
            case 17: if (science=="yes" && geology=="yes")
                    s = 1;
                    break;
            case 18: if (science=="yes" && physics=="yes")
                    s = 1;
                    break;
            case 19: if (science=="yes" && chemistry=="yes")
                    s = 1;
                    break;
            case 20: if (science=="yes" && botany=="yes")
                    s = 1;
                    break;
            case 21: if (business=="yes" && accounting=="yes")
                    s = 1;
                    break;
            case 22: if (business=="yes" && finance=="yes")
                    s = 1;
                    break;
            case 23: if (business=="yes" && marketing=="yes")
                    s = 1;
                    break;
            case 24: if (business=="yes" && real_estate=="yes")
                    s = 1;
                    break;
            case 25: if (business=="yes" && sales=="yes")
                    s = 1;
                    break;
            case 26: if (medical=="yes" && oncologist=="yes")
                    s = 1;
                    break;
            case 27: if (medical=="yes" && orthopedic=="yes")
                    s = 1;
                    break;
            case 28: if (medical=="yes" && cardiologist=="yes")
                    s = 1;
                    break;
            case 29: if (medical=="yes" && neurologist=="yes")
                    s = 1;
                    break;
            case 30: if (medical=="yes" && dentist=="yes")
                    s = 1;
                    break;
            case 31: if (english=="yes" && novel=="yes")
                    s = 1;
                    break;
            case 32: if (english=="yes" && composition=="yes")
                    s = 1;
                    break;
            case 33: if (english=="yes" && drama=="yes")
                    s = 1;
                    break;
            case 34: if (english=="yes" && poetry=="yes")
                    s = 1;
                    break;
            case 35: if (english=="yes" && writing=="yes")
                    s = 1;
                    break;
            case 36: if (geography=="yes" && human_geo=="yes")
                    s = 1;
                    break;
            case 37: if (geography=="yes" && physical_geo=="yes")
                    s = 1;
                    break;
            case 38: if (geography=="yes" && globalization=="yes")
                    s = 1;
                    break;
            case 39: if (geography=="yes" && gis=="yes")
                    s = 1;
                    break;
            case 40: if (geography=="yes" && geopolitics=="yes")
                    s = 1;
                    break;
            case 41: if (psychology=="yes" && cognitive=="yes")
                    s = 1;
                    break;
            case 42: if (psychology=="yes" && abnormal=="yes")
                    s = 1;
                    break;
            case 43: if (psychology=="yes" && social=="yes")
                    s = 1;
                    break;
            case 44: if (psychology=="yes" && personality=="yes")
                    s = 1;
                    break;
            case 45: if (psychology=="yes" && physiological=="yes")
                    s = 1;
                    break;
            case 46: if (agriculture=="yes" && agronomy=="yes")
                    s = 1;
                    break;
            case 47: if (agriculture=="yes" && horticulture=="yes")
                    s = 1;
                    break;
            case 48: if (agriculture=="yes" && agri_eng=="yes")
                    s = 1;
                    break;
            case 49: if (agriculture=="yes" && agri_eco=="yes")
                    s = 1;
                    break;
            case 50: if (agriculture=="yes" && animal_sci=="yes")
                    s = 1;
                    break;
            case 51: if (health_care=="yes" && nursing=="yes")
                    s = 1;
                    break;
            case 52: if (health_care=="yes" && h_service_man=="yes")
                    s = 1;
                    break;
            case 53: if (health_care=="yes" && h_admin=="yes")
                    s = 1;
                    break;
            case 54: if (health_care=="yes" && physician=="yes")
                    s = 1;
                    break;
            case 55: if (health_care=="yes" && public_h=="yes")
                    s = 1;
                    break;
            case 56: if (education=="yes" && teaching=="yes")
                    s = 1;
                    break;
            case 57: if (education=="yes" && counselling=="yes")
                    s = 1;
                    break;
            case 58: if (education=="yes" && admin=="yes")
                    s = 1;
                    break;
            case 59: if (education=="yes" && curriculum=="yes")
                    s = 1;
                    break;
            case 60: if (education=="yes" && recreation=="yes")
                    s = 1;
                    break;


        }

}

void FKnowledgeBase::thenKB() {
    /* ********* THEN part ******** */
        switch(sn) {

            case 1: engineering = "yes";
                    cout<<" Engineering==yes"<<endl;
                    v = "engineering";
                    inst=true;
                    break;
            case 2: science = "yes";
                    cout<<" science = yes"<<endl;
                    v = "science";
                    inst=true;
                    break;
            case 3: business = "yes";
                    cout<<"business=yes"<<endl;
                    v = "business";
                    inst=true;
                    break;
            case 4: medical = "yes";
                    cout<<"medical = yes"<<endl;
                    v = "medical";
                    inst=true;
                    break;
            case 5: english = "yes";
                    cout<<"english=yes"<<endl;
                    v = "english";
                    inst=true;
                    break;

            case 6: geography = "yes";
                    cout<<"geography=yes"<<endl;
                    v = "geography";
                    inst=true;
                    break;
            case 7: psychology = "yes";
                    cout<<"psychology = yes"<<endl;
                    v = "psychology";
                    inst=false;
                    break;
            case 8: agriculture = "yes";
                    cout<<"agriculture=yes"<<endl;
                    v = "agriculture";
                    inst=false;
                    break;
            case 9: health_care = "yes";
                    cout<<"health_care=yes"<<endl;
                    v = "health_care";
                    inst=true;
                    break;
            case 10: education = "yes";
                    cout<<"education=yes"<<endl;
                    v = "education";
                    inst=true;
                    break;
            case 11: Area = "electrical";
                    cout<<Area<<" Engineering"<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 12: Area = "computer";
                    cout<<Area<<" Engineering"<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 13: Area = "civil";
                    cout<<Area<<" Engineering"<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 14: Area = "petrolium";
                    cout<<Area<<" Engineering"<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 15: Area = "aerospace";
                    cout<<Area<<" Engineering"<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 16: Area = "zoology";
                    cout<<Area<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 17: Area = "geology";
                    cout<<Area<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 18: Area = "physics";
                    cout<<Area<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 19: Area = "chemistry";
                    cout<<Area<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 20: Area = "botany";
                    cout<<Area<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 21: Area = "accounting";
                    cout<<Area<<" in Business"<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 22: Area = "finance";
                    cout<<Area<<" in business"<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 23: Area = "marketing";
                    cout<<Area<<" in business"<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 24: Area = "real estate";
                    cout<<Area<<" in business"<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 25: Area = "sales";
                    cout<<Area<<" in business"<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 26: Area = "oncologist";
                    cout<<Area<<" in medical"<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 27: Area = "orthopedist";
                    cout<<Area<<" in medical"<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 28: Area = "cardiologist";
                    cout<<Area<<" in medical"<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 29: Area = "neurologist";
                    cout<<Area<<" in medical"<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 30: Area = "dentist";
                    cout<<Area<<" in medical"<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 31: Area = "novel";
                    cout<<Area<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 32: Area = "composition";
                    cout<<Area<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 33: Area = "drama";
                    cout<<Area<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 34: Area = "poetry";
                    cout<<Area<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 35: Area = "writing";
                    cout<<Area<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 36: Area = "Human Geography";
                    cout<<Area<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 37: Area = "Physical Geography";
                    cout<<Area<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 38: Area = "Globalization";
                    cout<<Area<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 39: Area = "GIS";
                    cout<<Area<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 40: Area = "Geopolitics";
                    cout<<Area<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 41: Area = "Cognitive";
                    cout<<Area<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 42: Area = "Abnormal";
                    cout<<Area<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 43: Area = "Social";
                    cout<<Area<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 44: Area = "Personality";
                    cout<<Area<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 45: Area = "Physiological";
                    cout<<Area<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 46: Area = "Agronomy";
                    cout<<Area<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 47: Area = "Horticulture";
                    cout<<Area<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 48: Area = "Agriculture Engineering";
                    cout<<Area<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 49: Area = "Agriculture Ecosystem";
                    cout<<Area<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 50: Area = "Animal Sciences";
                    cout<<Area<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 51: Area = "Nursing";
                    cout<<Area<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 52: Area = "Health Service Management";
                    cout<<Area<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 53: Area = "Health Administration";
                    cout<<Area<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 54: Area = "Physician";
                    cout<<Area<<endl;
                    v = "Area";
                    inst=false;
                    break;
           case 55: Area = "Public Health";
                    cout<<Area<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 56: Area = "Teaching";
                    cout<<Area<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 57: Area = "Student Counselling";
                    cout<<Area<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 58: Area = "Administration";
                    cout<<Area<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 59: Area = "Curriculum";
                    cout<<Area<<endl;
                    v = "Area";
                    inst=false;
                    break;
            case 60: Area = "Recreational coach";
                    cout<<Area<<endl;
                    v = "Area";
                    inst=false;
                    break;



        }

}

void FKnowledgeBase::instantiateKB() {
        switch(i) {

            case 1: cout<<"Are you interested in electronics?"<<endl;
                    cin>>electrical;
                    break;
            case 2: cout<<"Are you interested in computers?"<<endl;
                    cin>>computer;
                    break;
            case 3: cout<<"Are you interested in architechture of buildings?"<<endl;
                    cin>>civil;
                    break;
            case 4: cout<<"Are you interested in oil or natural gas?"<<endl;
                    cin>>petrolium;
                    break;
            case 5: cout<<"Are you interested in aircraft or spacecraft?"<<endl;
                    cin>>aerospace;
                    break;
            case 6: cout<<"Are you interested in behavior of animals?"<<endl;
                    cin>>zoology;
                    break;
            case 7: cout<<"Are you interested in earth's physical structure "<<endl;
                    cin>>geology;
                    break;
            case 8: cout<<"Are you interested in physics"<<endl;
                    cin>>physics;
                    break;
            case 9: cout<<"Are you interested in chemistry"<<endl;
                    cin>>chemistry;
                    break;
            case 10: cout<<"Are you interested in study of plants"<<endl;
                    cin>>botany;
                    break;
            case 11: cout<<"Are you interested in analyzing financial information of a company "<<endl;
                    cin>>accounting;
                    break;
            case 12: cout<<"Are you interested in investing ?"<<endl;
                    cin>>finance;
                    break;
            case 13: cout<<"Are you interested in selling goods to customers?"<<endl;
                    cin>>marketing;
                    break;
            case 14: cout<<"Are you interested in real estate"<<endl;
                    cin>>real_estate;
                    break;
            case 15: cout<<"Are you interested in revenue?"<<endl;
                    cin>>sales;
                    break;
            case 16: cout<<"Are you interested in treatment of tumors?"<<endl;
                    cin>>oncologist;
                    break;
            case 17: cout<<"Are you interested in learning about bones and muscles?"<<endl;
                    cin>>orthopedic;
                    break;
            case 18: cout<<"Are you interested in abnormalities of heart?"<<endl;
                    cin>>cardiologist;
                    break;
            case 19: cout<<"Are you interested in nerve system?"<<endl;
                    cin>>neurologist;
                    break;
            case 20: cout<<"Are you interested in teeth and gums?"<<endl;
                    cin>>dentist;
                    break;
            case 21: cout<<"Are you interested in novels?"<<endl;
                    cin>>novel;
                    break;
            case 22: cout<<"Are you interested in composition?"<<endl;
                    cin>>composition;
                    break;
            case 23: cout<<"Are you interested in drama?"<<endl;
                    cin>>drama;
                    break;
            case 24: cout<<"Are you interested in poetry?"<<endl;
                    cin>>poetry;
                    break;
            case 25: cout<<"Are you interested in writing blogs?"<<endl;
                    cin>>writing;
                    break;
            case 26: cout<<"Are you interested in about how human activity affects earth surface? "<<endl;
                    cin>>human_geo;
                    break;
            case 27: cout<<"Are you interested in natural earth features?"<<endl;
                    cin>>physical_geo;
                    break;
            case 28: cout<<"Are you interested in interaction and integration across the world?"<<endl;
                    cin>>globalization;
                    break;
            case 29: cout<<"Are you interested in tracking locations on earth surface?"<<endl;
                    cin>>gis;
                    break;
            case 30: cout<<"Are you interested in political power in related to geographic space?"<<endl;
                    cin>>geopolitics;
                    break;
            case 31: cout<<"Are you interested in learning about mental process of human brain?"<<endl;
                    cin>>cognitive;
                    break;
            case 32: cout<<"Are you interested in learning about unacceptable behavior?"<<endl;
                    cin>>abnormal;
                    break;
            case 33: cout<<"Are you interested in learning about acceptable behavior?"<<endl;
                    cin>>social;
                    break;
            case 34: cout<<"Are you interested in overall behavior?"<<endl;
                    cin>>personality;
                    break;

            case 35: cout<<"Are you interested in neural mechanisms of human perception? "<<endl;
                    cin>>physiological;
                    break;

            case 36: cout<<"Are you interested in field-crop production?"<<endl;
                    cin>>agronomy;
                    break;

            case 37: cout<<"Are you interested in small-scale gardening?"<<endl;
                    cin>>horticulture;
                    break;

            case 38: cout<<"Are you interested in overall process in farming?"<<endl;
                    cin>>agri_eng;
                    break;

            case 39: cout<<"Are you interested in dealing with land usage?"<<endl;
                    cin>>agri_eco;
                    break;

            case 40: cout<<"Are you interested in biology of animals?"<<endl;
                    cin>>animal_sci;
                    break;

            case 41: cout<<"Are you interested in taking care of sick people? "<<endl;
                    cin>>nursing;
                    break;

            case 42: cout<<"Are you interested in managing health activities?"<<endl;
                    cin>>h_service_man;
                    break;

            case 43: cout<<"Are you interested in administrating health related activities?"<<endl;
                    cin>>h_admin;
                    break;

            case 44: cout<<"Are you interested in general practitioner?"<<endl;
                    cin>>physician;
                    break;

            case 45: cout<<"Are you interested in monitoring health population?"<<endl;
                    cin>>public_h;
                    break;

            case 46: cout<<"Are you interested in students, academics?"<<endl;
                    cin>>teaching;
                    break;

            case 47: cout<<"Are you interested in giving advice to students?"<<endl;
                    cin>>counselling;
                    break;
            case 48: cout<<"Are you interested in administrating the school?"<<endl;
                    cin>>admin;
                    break;
            case 49: cout<<"Are you interested in academic content taught in school? "<<endl;
                    cin>>curriculum;
                    break;
            case 50: cout<<"Are you interested about students engaging sports activities?"<<endl;
                    cin>>recreation;
                    break;
            case 51:break;


        }


}
