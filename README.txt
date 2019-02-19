 
For Backward Chaining:
      BackwardChain.h
      BackwardChain.cpp
      KnowledgeBase.h
      KnowledgeBase.cpp
      conclusion1.txt
      variable1.txt
      ClauseVariable.txt
      
 For Backward Chaining:
      ForwardChain.cpp
      ForwardChain.h
      FKnowledgeBase.cpp
      FknowledgeBase.h
      FClauseVar.txt
      Fvar.txt
 
 Program compilation:
      compile main.cpp and run it
      
      
    1. INTRODUCTION 

. Problem

The motive of this project is to build an Intelligent Expert System to help the students in identifying the profession. The project was developed based on collecting knowledge from different sources, building decision trees, and creating rules for knowledge bases for both backward chaining and forward chaining. Backward chaining is used to identify fault on the vehicle, whereas forward chaining will give the solution to the fault.

 Solution

The knowledge was fed to the knowledge base and it is sent to the inference engine to make the decisions. The expert system uses forward chaining for treatment and backward chaining for choosing the profession. Questions are iteratively asked to the user to reach a conclusion. The forward and backward chaining processes used in this system will be discussed in a later section in the document.


3. EXPERT SYSTEMS IMPLEMENTATIONS:

An expert system is a computer program which behaves like a human to provide judgment like an expert and experienced in a field. It mainly consists of two parts namely,
 Knowledge base
 Inference Engine

3.1. Domain

The System domain: Career Advising 
The goal is to build an intelligent computer expert system to help the students to choose a profession.

3.2 . KNOWLEDGE BASE:

In an expert system, IF-Then rules are used to express the knowledge base. Every rule has an IF part, called the antecedent and a THEN part, called the consequent part. When a problem occurs, these rules are used as an evidence to derive a conclusion.

3.3 INFERENCE ENGINE:

Inference engine programs are designed to produce reasoning based on the rules and logics. Inference Engine is developed in two ways,
Forward Chaining
Backward Chaining

3.4. DECISION TREES:

We then transformed the data gathered into a decision tree. 

3.5 RULES FROM DECISION TREE

After developing the decision tree we traced out the IF and THEN clauses for the tree and
have written the rules for forward and backward chaining.






4. BACKWARD CHAINING METHODOLOGY

4.1. Backward Chaining:

Backward chaining is an inference method which works by searching for conclusions, instantiating causes, and see if these causes link to earlier conclusions. It starts with a list of goals and works backwards from the consequence to the antecedent to check whether the data is available that supports these consequents. Backward chaining tool will help us solve diagnostic problems in which the conclusion is known, and the causes are sought.

4.2. Backward Chaining Rules

Rule 10 : IF career == no THEN Career = no
Rule 20 : IF Career == no THEN Profession = no
Rule 30 : IF career == yes THEN Career = yes
Rule 40 : IF Career == yes AND engineering == yes THEN Engineering = yes
Rule 50 : IF Engineering == yes THEN Profession = Engineering
Rule 60 : IF Career == yes AND engineering == no THEN Engineering = no
Rule 70 : IF Engineering == no AND science == yes THEN Science = yes
Rule 80 : IF Science == yes THEN Profession = Science
Rule 90 : IF Engineering == no AND science == no THEN Science = no
Rule 100 : IF Science == no AND business == yes THEN Business == yes
Rule 110 : IF Business == yes THEN Profession = Business
Rule 120 : IF Science == no AND business == no THEN Business == no
Rule 130 : IF Business == no AND english == yes THEN English = yes
Rule 140 : IF English == yes THEN Profession = English
Rule 150 : IF Business == no AND english == no THEN English = no
Rule 160 : IF English == no AND geography == yes THEN Geography = yes
Rule 170 : IF Geography == yes THEN Profession = Geography
Rule 180 : IF English == no AND geography == no THEN Geography = no
Rule 190 : IF Geography == no AND psychology == yes THEN Psychology = yes
Rule 200 : IF Psychology == yes THEN Profession = Psychology
Rule 210 : IF Geography == no AND psychology == no THEN Psychology = no
Rule 220 : IF Psychology == no AND agriculture == yes THEN Agriculture = yes
Rule 230 : IF Agriculture == yes THEN Profession = Agriculture
Rule 240 : IF Psychology == no AND agriculture == no THEN Agriculture = no
Rule 250 : IF Agriculture == no AND medical == yes THEN Medical = yes
Rule 260 : IF Medical == yes THEN Profession = Medical
Rule 270 : IF Agriculture == no AND medical == no THEN Medical = no
Rule 280 : IF Medical == no AND health_care == yes THEN Health_care = yes
Rule 290 : IF Health_care == yes THEN Profession = Health_care
Rule 300 : IF Medical == no AND health_care == no THEN Health_care = no
Rule 310 : IF Health_care == no AND education == yes THEN Education = yes
Rule 320 : IF Education == yes THEN Profession = Education
Rule 340 : IF Health_care == no AND education == no THEN Education = no
Rule 320 : IF Education == no THEN Profession = No

5. FORWARD CHAINING METHODOLOGY

5.1. Forward Chaining

Forward Chaining starts with the available information and uses the rules to extract more data or information by asking questions from the user till a goal is reached. Inference engine using forward chaining searched the inference rules utile it finds a rule in which an IF clause is knowing to be true. After reaching such a rule, the inference engine can infer the THEN clause and add new information to its data.

5.2. Forward Chaining Rules

Rule 1: IF profession==Engineering THEN engineering = yes
Rule 2: IF (profession=="Science" ) THEN science = yes
Rule 3: IF (profession=="Business" ) THEN business = "yes"
Rule 4: IF (profession=="Medical" ) THEN medical = "yes"
Rule 5: IF (profession=="English" ) THEN english = "yes"
Rule 6: IF (profession=="Geography" ) THEN geography = "yes"
Rule 7: IF (profession=="Psychology" ) THEN psychology = "yes"
Rule 8: IF (profession=="Agriculture" ) THEN agriculture = "yes"
Rule 9: IF (profession=="Health_care" ) THEN health_care = "yes"
Rule 10: IF (profession=="Education" ) THEN education = "yes"
Rule 11: IF (engineering=="yes" && electrical=="yes")THEN Area = "electrical"
Rule 12: IF (engineering=="yes" && computer=="yes") THEN Area = "computer"
Rule 13: IF (engineering=="yes" && civil=="yes") THEN Area = "civil"
Rule 14: IF (engineering=="yes" && petrolium=="yes")THEN Area = "petrolium"
Rule 15: IF (engineering=="yes" && aerospace=="yes") THEN Area = "aerospace"
Rule 16: IF (science=="yes" && zoology=="yes") THEN Area = "zoology"
Rule 17: IF (science=="yes" && geology=="yes") THEN Area = "geology"        
Rule 18: IF (science=="yes" && physics=="yes") THEN Area = "physics"
Rule 19: IF (science=="yes" && chemistry=="yes") THEN Area = "chemistry"        
Rule 20: IF (science=="yes" && botany=="yes") THEN Area = "botany"
Rule 21: IF (business=="yes" && accounting=="yes") THEN Area = "accounting"
Rule 22: IF (business=="yes" && finance=="yes") THEN Area = "finance"
Rule 23: IF (business=="yes" && marketing=="yes") THEN Area = "marketing"
Rule 24: IF (business=="yes" && real_estate=="yes") THEN Area = "real estate"
Rule 25: IF (business=="yes" && sales=="yes") THEN Area = "sales"
Rule 26: IF (medical=="yes" && oncologist=="yes") THEN Area = "oncologist"
Rule 27: IF (medical=="yes" && orthopedic=="yes") THEN Area = "orthopedist"
Rule 28: IF (medical=="yes" && cardiologist=="yes") THEN Area = "cardiologist"
Rule 29: IF (medical=="yes" && neurologist=="yes") THEN Area = "neurologist"
Rule 30: IF (medical=="yes" && dentist=="yes") THEN Area = "dentist"
Rule 31: IF (english=="yes" && novel=="yes") THEN Area = "novel"
Rule 32: IF (english=="yes" && composition=="yes") THEN Area = "composition"
Rule 33: IF (english=="yes" && drama=="yes") THEN Area = "drama"           
Rule 34: IF (english=="yes" && poetry=="yes") THEN Area = "poetry"
Rule 35: IF (english=="yes" && writing=="yes") THEN Area = "writing"
Rule 36: IF (geography=="yes" && human_geo=="yes") THEN Area = "Human     Geography"
Rule 37: IF (geography=="yes" && physical_geo=="yes") THEN Area ="Physical Geography"
Rule 38: IF (geography=="yes" && globalization=="yes")THEN Area = "Globalization"
Rule 39: IF (geography=="yes" && gis=="yes") THEN Area = "GIS"
Rule 40: IF (geography=="yes" && geopolitics=="yes") THEN Area = "Geopolitics"
Rule 41: IF (psychology=="yes" && cognitive=="yes") THEN Area = "Cognitive"
Rule 42: IF (psychology=="yes" && abnormal=="yes")THEN Area = "Abnormal"
Rule 43: IF (psychology=="yes" && social=="yes") THEN Area = "Social"
Rule 44: IF (psychology=="yes" && personality=="yes")THEN Area = "Personality"
Rule 45: IF (psychology=="yes" && physiological=="yes") THEN Area = "Physiological"
Rule 46: IF (agriculture=="yes" && agronomy=="yes") THEN Area = "Agronomy"
Rule 47: IF (agriculture=="yes" && horticulture=="yes") THEN Area = "Horticulture"
Rule 48: IF (agriculture=="yes" && agri_eng=="yes") THEN Area = "Agriculture Engineering"
Rule 49: IF (agriculture=="yes" && agri_eco=="yes") THEN Area = "Agriculture Ecosystem"
Rule 50: IF (agriculture=="yes" && animal_sci=="yes") THEN Area = "Animal Sciences"
Rule 51: IF (health_care=="yes" && nursing=="yes") THEN Area = "Nursing"
Rule 52: IF (health_care=="yes" && h_service_man=="yes") THEN Area = "Health Service Management"
Rule 53: IF (health_care=="yes" && h_admin=="yes") THEN Area = "Health Administration"
Rule 54: IF (health_care=="yes" && physician=="yes") THEN Area = "Physician"
Rule 55: IF (health_care=="yes" && public_h=="yes") THEN Area = "Public Health"
Rule 56: IF (education=="yes" && teaching=="yes")THEN Area = "Teaching"
Rule 57: IF (education=="yes" && counselling=="yes") THEN  Area = "Student Counselling"
Rule 58: IF (education=="yes" && admin=="yes") THEN Area = "Administration"
Rule 59: IF (education=="yes" && curriculum=="yes") THEN Area = "Curriculum"
Rule 60: IF (education=="yes" && recreation=="yes") THEN Area = "Recreational coach"

      

      
