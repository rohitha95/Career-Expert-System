#include "KnowledgeBase.h"
#include<fstream>

KnowledgeBase::KnowledgeBase()
{

}

KnowledgeBase::~KnowledgeBase()
{
    //dtor
}
void KnowledgeBase::initialization(){

	// Stack space is 10 we initially place stack space at 10+1
	cout<<"Knowledge base initilization"<<endl;
    sp = size;
	for (int i=1; i < size; i++)
        {
            conclt[i] = "";
            varlt[i] = "";
            instlt[i]=0;
            statsk[i]=0;
            clausk[i]=0;
        }
    for (int i=1; i < clauseSize; i++)
        clvarlt[i] = "";


	// conclusion list in the conclt array
	ifstream fin;

	fin.open("conclusion1.txt");
        for (int i =1;i<35;i++)
            fin>>conclt[i];

    fin.close();

    cout<<"Conclusion:"<<endl;
    for (int i =1;i<35;i++)
        cout<<"conclusion "<<i<<" "<<conclt[i]<<endl;

    cout<<"HIT RETURN TO CONTINUE";
    gets(buff);

	// variable list in the VARLT array

	fin.open("variable1.txt");
	for(int i=1;i<size;i++)
	{
		fin >> varlt[i];
	}
	fin.close();
    // Printing Variable List
    cout<<"*** VARIABLE LIST ***"<<endl;
    for(int i=1; i < size; i++)
    	cout<<"VARIABLE "<<i<<" "<<varlt[i]<<endl;

    cout<<"HIT RETURN TO CONTINUE";
    gets(buff);

	// clause variable list in clvarlt
	fin.open("clauseVariable.txt");

	for(int i=1;i<clauseSize;i++)
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
	fin.close();
    //Printing Clause Variable List
    cout<<"*** CLAUSE VARIABLE LIST ***"<<endl;

    for(int i=1; i < noofcases; i++)
        {
            cout<<"** CLAUSE "<<i<<" **"<<endl;
            for(int j=1; j<4; j++)
            {

                k = 3 * (i-1) + j;
                cout<<"VARIABLE "<<j<<" "<<clvarlt[k]<<endl;
            }
            if (i==3)
            {
    			cout<<"HIT RETURN TO CONTINUE";
                gets(buff);
            }
        }

        for (int i =0;i<35;i++)
        cout<<i<<" "<<conclt[i]<<endl;

}

void KnowledgeBase::initkbase(){
    switch (i)
                {
                        /***** input statement *****/
                        /* input statements for sample position knowledge
                           base */
                        /***** comment 1700 ******/
                case 1: cout<<"Would you like to find career(INPUT YES OR NO)? "<<endl;
                        getline(cin, career);
                        break;
                case 2: cout<<"Do you like to design or build machines or structures(INPUT YES OR NO )? "<<endl;
                        getline(cin, engineering);
                        break;
                case 3: cout<<"Do you like experimenting things (YES OR NO)? "<<endl;
                        cin>>science;
                        break;
                case 4: cout<<"Do you like making money (YES OR NO)"<<endl;
                        cin>>business;
                        break;
                case 5: cout<<"Do you like literature or novels (YES OR NO)?"<<endl;
                        cin>>english;
                        break;
                case 6: cout<<"Do you want to know about the Earth surface (YES OR NO) ?"<<endl;
                        cin>>geography;
                        break;
                case 7: cout<<"Do you want to study about human mind and behavior (YES OR NO)?"<<endl;
                        cin>>psychology;
                        break;
                case 8: cout<<"Do you like to do farming (YES OR NO)?"<<endl;
                        cin>>agriculture;
                        break;
                case 9: cout<<"Do you want to study about treatment of diseases or curing it (YES OR NO) ?"<<endl;
                        cin>>medical;
                        break;
                case 10:cout<<"Do you want to study about health care services (YES OR NO)?"<<endl;
                        cin>>health_care;
                        break;
                case 11:cout<<"Do you like teaching or student or academics (YES OR NO)? "<<endl;
                        cin>>education;
                        break;

                        /***** comment 1715 ****/
                }


}
void KnowledgeBase::ifkbase() {
    switch (sn) {
                                  /* if part of statement 1 */
                                  /****** comment 1500 ****/
                          case 1: if(career.compare("NO") == 0)
                                    s = 1;
                                    break;
                                  /* if part of statement 2 */
                                  /***** comment 1510 ******/
                          case 2: if(Career.compare("NO") == 0 )
                                    s = 1;
                                    break;
                          case 3: if (career.compare("YES")==0)
                                    s = 1;
                                    break;
                                  /* if part of statement 3 */
                          case 4: if((Career.compare("YES") == 0) &&
                                     (engineering.compare("YES") == 0))
                                     s = 1;

                                  break;
                                  /* if part of statement 4 */
                                  /******** comment 1560 ******/
                          case 5: if(Engineering.compare("YES") == 0)

                                     s = 1;

                                  break;
                                  /******** comment 1570 ********/
                                  /* if part of statement 5 */
                          case 6: if((Career.compare("YES") == 0) &&
                                     (engineering=="NO"))
                                     s = 1;

                                  break;
                                  /* if part of statement 6 */
                          case 7: if((Engineering.compare("NO") == 0) &&
                                     (science=="YES"))
                                     s = 1;


                                  break;
                          case 8: if(Science=="YES")
                                    s = 1;

                                    break;
                          case 9:  if ((science=="NO") && (Engineering=="NO") )
                                    s = 1;


                                    break;
                          case 10: if ((Science=="NO") && (business=="YES"))

                                    s = 1;

                                    break;
                          case 11: if (Business=="YES")
                                    s = 1;


                                    break;
                          case 12: if ((business=="NO") && (Science=="NO"))
                                    s = 1;


                                    break;
                          case 13: if ((Business=="NO") && (english=="YES"))
                                    s = 1;


                                    break;
                          case 14: if (English=="YES")
                                    s = 1;


                                    break;
                          case 15: if((Business=="NO") && (english=="NO"))
                                    s = 1;


                                    break;
                          case 16: if ((English=="NO") && (geography=="YES"))
                                    s = 1;


                                    break;
                          case 17: if (Geography=="YES")
                                    s = 1;

                                    break;
                          case 18: if((English=="NO") && (geography=="NO"))
                                    s = 1;
                                    break;
                          case 19: if ((Geography=="NO") && (psychology=="YES"))
                                    s = 1;
                                    break;
                          case 20: if (Psychology=="YES")
                                    s = 1;
                                    break;
                          case 21: if ((Geography=="NO") && (psychology=="NO"))
                                    s = 1;
                                    break;
                          case 22: if ((Psychology=="NO") && (agriculture=="YES"))
                                    s = 1;
                                    break;
                          case 23: if (Agriculture=="YES")
                                    s = 1;
                                    break;
                          case 24: if ((Psychology=="NO") && (agriculture=="NO"))
                                    s = 1;
                                    break;
                          case 25: if ((Agriculture=="NO") && (medical=="YES"))
                                    s = 1;
                                    break;
                          case 26: if (Medical=="YES")
                                    s = 1;
                                    break;
                          case 27: if ((Agriculture=="NO") && (medical=="NO"))
                                    s = 1;
                                    break;
                          case 28: if ((Medical=="NO") && (health_care=="YES"))
                                    s = 1;
                                    break;
                          case 29: if (Health_care=="YES")
                                    s = 1;
                                    break;
                          case 30: if ((Medical=="NO") && (health_care=="NO"))
                                    s = 1;
                                    break;
                          case 31: if ((Health_care=="NO") && (education=="YES"))
                                    s = 1;
                                    break;
                          case 32: if (Education=="YES")
                                    s = 1;
                                    break;
                          case 33: if ((Health_care=="NO") && (education=="NO"))
                                    s = 1;
                                    break;
                          case 34: if (Education=="NO")
                                    s = 1;
                                    break;


                                  /********* comment 1680 ******/
                          }

}
void KnowledgeBase::thenkbase() {
    switch (sn) {
                                  /* then part of statement 1 */
                                  /******* comment 1500 *******/
                          case 1: Career="NO";
                                  cout<<"career=NO"<<endl;
                                  break;
                                  /* then part of statement 2 */
                                  /****** comment 1510 ******/
                          case 2: Profession= "NO";
                                  cout<<"PRO=NO"<<endl;
                                  break;
                                  /* then part of statement 3 */
                          case 3: Career="YES";
                                    cout<<"career=yes"<<endl;
                                    break;
                          case 4: Engineering="YES";
                                  cout<<"Eng=yes"<<endl;
                                  break;
                                  /* then part of statement 4 */
                                  /******** comment 1560 ******/
                          case 5: Profession= "Engineering";
                                  cout<<"ENGINEER"<<endl;
                                  break;
                                  /* then part of statement 5 */
                                  /****** comment 1570 *****/
                          case 6: Engineering="NO";
                                  cout<<"Eng=NO"<<endl;
                                  break;
                                  /* then part of statement 6 */
                          case 7: Science="YES";
                                  cout<<"Science=yes"<<endl;
                                  break;
                                  /****** comment 1680 ********/
                          case 8 : Profession="Science";
                                    cout<<Profession<<endl;
                                    break;
                          case 9: Science="NO";
                                    cout<<"science=no"<<endl;
                                    break;
                          case 10: Business="YES";
                                    cout<<"business=yes"<<endl;
                                    break;
                          case 11: Profession="Business";
                                    cout<<Profession<<endl;
                                    break;
                          case 12: Business="NO";
                                    cout<<"business=no"<<endl;
                                    break;
                          case 13: English="YES";
                                    cout<<"english=yes"<<endl;
                                    break;
                          case 14: Profession="English";
                                    cout<<Profession<<endl;
                                    break;
                          case 15: English="NO";
                                    cout<<"english=no"<<endl;
                                    break;
                          case 16: Geography="YES";
                                    cout<<"geography=yes"<<endl;
                                    break;
                          case 17: Profession="Geography";
                                    cout<<Profession<<endl;
                                    break;
                          case 18: Geography="NO";
                                    cout<<"geography=no"<<endl;
                                    break;
                          case 19: Psychology="YES";
                                    cout<<"Psychology=yes"<<endl;
                                    break;
                          case 20: Profession="Psychology";
                                    cout<<Profession<<endl;
                                    break;
                          case 21: Psychology="NO";
                                    cout<<"psychology=no"<<endl;
                                    break;
                          case 22: Agriculture="YES";
                                    cout<<"agriculture=yes"<<endl;
                                    break;
                          case 23: Profession="Agriculture";
                                    cout<<Profession<<endl;
                                    break;
                          case 24: Agriculture="NO";
                                    cout<<"agriculture=no"<<endl;
                                    break;
                          case 25: Medical="YES";
                                    cout<<"medical = yes"<<endl;
                                    break;
                          case 26: Profession="Medical";
                                    cout<<Profession<<endl;
                                    break;
                          case 27: Medical="NO";
                                    cout<<"medical=no"<<endl;
                                    break;
                          case 28: Health_care="YES";
                                    cout<<"health care=yes"<<endl;
                                    break;
                          case 29: Profession="Health_care";
                                    cout<<Profession<<endl;
                                    break;
                          case 30: Health_care="NO";
                                    cout<<"health_care=no"<<endl;
                                    break;
                          case 31:Education="YES";
                                    cout<<"education=yes"<<endl;
                                    break;
                          case 32:Profession="Education";
                                    cout<<Profession<<endl;
                                    break;
                          case 33: Education="NO";
                                    cout<<"education=no"<<endl;
                                    break;
                          case 34: Profession="NO";
                                    cout<<Profession<<endl;
                                    break;
                          }


}
