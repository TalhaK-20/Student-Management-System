//BISMILLAH IRAHMAAN-I-RAHEEM 
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Credits;  // Forward Declaration
class portal;   // Forward Declaration
class unity;    // Forward Declaration

class Main_Screen{       // Parent Class 1
    public:
      
         Main_Screen(){      
           
           cout<<"\n\n    ---------WELCOME TO---------"<<endl;
           cout<<"---------UMT Management System---------"<<endl;  
            
           cout<<endl;  
           cout<<"1. ADMIN Portal";
           cout<<endl;
           cout<<"2. STUDENT Portal";
           cout<<endl;
           cout<<"3. Exit"<<endl;         
         }
    
}; 
   

class Credits{      // Parent Class 2
	public:
		virtual void Developer_of_program() = 0;    //Pure Virtual function
};


 

class portal:public Credits{     // Single Line Inheritance
  // Child     //Parent   
   
    private: 
    string password1,password2,password3,password4;
    string adminPass,adminUsername;
    
    public:
        
         portal(){               //Constructor
            password1="";
            password2="";
            password3=""; 
            password4="";
            adminPass="";
            adminUsername="";
         } 
        
      

         void Developer_of_program(){       //NUMBER 1 
	        cout << "\nThis program is made by :" << endl;
	        cout << "Talha_Khalid" << endl;
         }


        friend void AssignVariable(portal);     //Friend function
      

       
         void add_Student(){      //NUMBER 2
        
            char name_of_student1[300];
            char name_of_student2[300];
            int  age_of_student;
            string CNIC_of_student;
            string degree_of_student;

            cout <<"Enter the first name of student : "<<endl;
            cin >> name_of_student1;
            
            cout <<"Enter the last name of student : "<<endl;
            cin >> name_of_student2;
            

            cout<<"Enter the age of student :"<<endl;
            cin>>age_of_student;   
                        
            cout<<"Enter the CNIC of student :"<<endl;
            cin>>CNIC_of_student;   
             
            cout<<"Enter the Program/Degree of student :"<<endl;
            cin>>degree_of_student; 
              

            ofstream myfile("Student Database.txt",ios :: app);
            
            myfile<<"First name:"<<name_of_student1 <<" ";
            myfile<<"Last name:"<<name_of_student2 <<" ";
            myfile<<"Age:"<<age_of_student <<" ";
            myfile<<"CNIC:"<<CNIC_of_student <<" ";
            myfile<<"Degree:"<<degree_of_student <<" "<<endl; 
                               
           //Last endl will cause the cursor to jump to the next line.  
                                      
            myfile.close();
            
            cout<< endl << "Student and his/her details have been added Successfully."<<endl; 
         
            
            ifstream obj("Student Database.txt");
            
            obj.getline(name_of_student1,300);
            obj.getline(name_of_student2,300);
          

            cout << "Content of the file is:"<<endl;
            cout<< name_of_student1; 
           
         }
      
       


         void add_Teacher(){      //NUMBER 3
         
            char name_of_teacher1[300];
            char name_of_teacher2[300];          
            int  age_of_teacher;
            string CNIC_of_teacher;
            string degree_of_teacher;
            string status_teacher;

            cout <<"Enter the First name of teacher :"<<endl;
            cin >> name_of_teacher1;
            
            cout <<"Enter the Last name of teacher :"<<endl;
            cin >> name_of_teacher2;
            
            cout <<"Enter the age of teacher :"<<endl;
            cin >> age_of_teacher;
             
            cout <<"Enter the CNIC of teacher :"<<endl;
            cin >> CNIC_of_teacher;
             
            cout <<"Enter the Qualification/Degree of teacher :"<<endl;
            cin >> degree_of_teacher;

            cout <<"Completed or In Progress ? Enter C for completed or enter P for in progress."<<endl;
            cin >> status_teacher;  
             
            
            ofstream myFile("Teacher Database.txt",ios :: app);
       
            myFile<<"First Name: " << name_of_teacher1 <<"  ";
            myFile<<"Last Name: " << name_of_teacher2 <<"  ";
            myFile<<"Age: " << age_of_teacher <<"  ";
            myFile<<"CNIC: " << CNIC_of_teacher <<"  ";
            myFile<<"Qualification: " << degree_of_teacher <<"  ";
            myFile<<"Status: " << status_teacher <<"  "<<endl; 
            
            myFile.close();
  
            cout<<"Teacher has been added Successfully"<<endl; 
             
  
            ifstream obj("Teacher Database.txt");
       
            obj.getline(name_of_teacher1,300);
            obj.getline(name_of_teacher2,300);
          
            
            cout << "Content of the file is : " <<" " << name_of_teacher1;            
                       
         }   
   


         void SET_admin_login(){       //NUMBER 4  Admin Portal
            
            string a;
            string b;
            adminUsername="nomi";
     
            cout<<"Please enter the Username:"<<endl;
            cin>>a;

            while(a!=adminUsername){
                cout<<"Incorrect Username. Please enter a valid Username."<<endl;
                cin>>a;            
           
            }

            adminUsername=a;
            GET_admin_userName();

            ofstream admin_Pass_write("Teacher Password Database.txt",ios :: app);
          //admin_Pass_write<<"nauman"<<endl; 
            admin_Pass_write.close(); 
            
            string b2;
            string adminPass;

            ifstream  admin_Pass_read("Teacher Password Database.txt");

            while (getline (admin_Pass_read,b2)){
               adminPass=b2;
            }     

            cin>>b;

            string new_password_admin;    

            while(b!=adminPass){
               cout<<"Incorrect Password. Please enter correct Password."<<endl;
               cin>>b;
                
               if(b!=adminPass){
                  cout<<"Forget your Password ! Do you want to reset it ?"<<endl;
                  cout<<"Enter 'YES' if you want to reset the Password."<<endl;    
                  cout<<"Otherwise 'Press any key'"<<endl;
                 
                  string key_enter;
                  cin>>key_enter;
                 
                  if(key_enter=="YES" || key_enter=="yes" || key_enter=="Yes" || key_enter=="y" || key_enter=="Y"){
                      
                     cout<<"Enter the new password please...."<<endl;
                     cin>>new_password_admin; 
                   
                     ofstream admin_Pass_write("Teacher Password Database.txt",ios :: app);
                     admin_Pass_write<<new_password_admin<<endl; 

                     admin_Pass_write.close(); 
                     cout<<"Your Password has been reset."<<endl;

                     ifstream admin_Pass_read("Teacher Password Database.txt");
                     
                     while (getline (admin_Pass_read, b2)) {
                           adminPass=b2; 
                     }
                     
                     cout<<"Enter the new Passsword to login."<<endl;
                     cin>>b;
                    
                  }
                  
                  else{
                  cout<<"OK Then try again your old password."<<endl;
                  cin>>b;
                  } 
 
               }
            
            }   
             
            GET_admin_Password();
            Selection(); 
            ADMIN_portal_repeat();     
         }



         void GET_admin_userName(){             //NUMBER 5
               cout<<"Correct Username.";
               cout<< " Now please enter the Password:"<<endl;                   
         }     


         void GET_admin_Password(){             //NUMBER 6   
            cout<<"Correct Password."<<endl; 
            cout<<"Welcome to the Admin portal"<<endl;
       
         }



         void Selection(){       //NUMBER 7
           string a;
           cout<<"What do you want to add ?"<<endl;
           cout<<"1. Teacher"<<endl;
           cout<<"2. Student"<<endl;
           cin>>a; 

           if(a=="Teacher" || a=="teacher" || a=="1"){
               add_Teacher();   
            }

           else if(a=="Student" || a=="student"|| a=="2"){
               add_Student();
            } 
       
         }
 


         void ADMIN_portal_repeat(){      //NUMBER 8
    
           char a;
           cout<<"\nDo you want to go to previous screen of your PORTAL ?\nIF Yes press y.\n";
           cout<<"DO you want to LOG OUT from your PORTAL ? Press L to log out."<<endl;
           cin>>a;
           if (a=='L' || a=='l'){
               cout<<"You're successfully logout!";
               
            }
         
           else if(a=='Y' || a=='y') 
               Selection();
        
         }


      

    
         void student_Login(){     //NUMBER 9   Student Portal
            
            string enter;  
            password1="talhafallumt";
            password2="saadmazaidarumt";
            password3="alihassanumt";
            password4="javeriafallumt";
            cout<<"Enter the password to login:"<<endl;
            cin>>enter;
            
             
            
            while(password1!=enter && password2!=enter && password3!=enter && password4!=enter){
            cout<<"Incorrect Password!"<<endl;
            cout<<"Please enter again:"<<endl;
            cin>>enter;
            
            }

            cout<<"CORRECT PASSWORD"<<endl;
     
            if(password1==enter){
               portal_menu(); 
                  
            }
               
            if(password2==enter){
    
                int q;
                cout<<"1. Current Semester and courses"<<endl;
                cout<<"2. Transcript"<<endl;
                cout<<"3. Payments"<<endl;
                cout<<"Press the number you want to see your information:"<<endl; 
            
                cin>>q;
            
                if(q==1){
                  courses_semester(); 
                  Student_portal_repeat();
                }
       
                else if(q==2){
                   Transcript_Details_Saad();
                   Student_portal_repeat();
                }
       
                else if(q==3){
                   cout<<"ALHAMDULILLAH _ Your all dues are clear";
                   Student_portal_repeat();
                }
            }    


            if(password3==enter){

                int q;
                cout<<"1. Current Semester and courses"<<endl;
                cout<<"2. Transcript"<<endl;
                cout<<"3. Payments"<<endl;
                cout<<"Press the number you want to see your information:"<<endl; 
            
                cin>>q;
            
                if(q==1){
                  courses_semester(); 
                  Student_portal_repeat();
                }
       
                else if(q==2){
                   Transcript_Details_Ali();
                   Student_portal_repeat();
                }
       
                else if(q==3){
                   cout<<"ALHAMDULILLAH _ Your all dues are clear";
                   Student_portal_repeat();
                }
            
            }   

              
            if(password4==enter){
                
                int q;
                cout<<"1. Current Semester and courses"<<endl;
                cout<<"2. Transcript"<<endl;
                cout<<"3. Payments"<<endl;
                cout<<"Press the number you want to see your information:"<<endl; 
            
                cin>>q;
            
                if(q==1){
                  courses_semester(); 
                  Student_portal_repeat();
                }
       
                else if(q==2){
                   Transcript_Details_Javeria();
                   Student_portal_repeat();
                }
       
                else if(q==3){
                   cout<<"ALHAMDULILLAH _ Your all dues are clear";
                   Student_portal_repeat();
                }
            }           
                
             
        
         } 


    
         void portal_menu(){      //NUMBER 10
    
               int q;
               cout<<"1. Current Semester and courses"<<endl;
               cout<<"2. Transcript"<<endl;
               cout<<"3. Payments"<<endl;
               cout<<"Press the number you want to see your information:"<<endl; 
            
               cin>>q;
            
               if(q==1){
                   courses_semester(); 
                   Student_portal_repeat();
                }
  
               else if(q==2){
                   Transcript_Details_Talha();
                   Student_portal_repeat();
                }
  
               else if(q==3){
                   cout<<"ALHAMDULILLAH _ Your all dues are clear";
                   Student_portal_repeat();
                }
         }
  

       
    
         void courses_semester(){      //NUMBER 11
                   
                   cout<<"Current Semester is 2nd_SPRING 2022"<<endl;
                   cout<<"Your courses are:"<<endl;
                   cout<<"COURSES                           CREDIT HOURS"<<endl;
                   cout<<"Object Oriented Programming         3"<<endl;
                   cout<<"Object Oriented Programming LAB     1"<<endl;
                   cout<<"Discrete Structures                 3"<<endl;
                   cout<<"Islamic Studies                     3"<<endl;
                   cout<<"Calculus 2                          3"<<endl;
                   cout<<"English 2                           3"<<endl;
         } 



    
         void Student_portal_repeat(){     //NUMBER 12
    
           char a;
           cout<<"\nDo you want to go to previous screen of your PORTAL ?\nIF Yes press y.\n";
           cout<<"DO you want to LOG OUT from your PORTAL ? Press L to log out."<<endl;
           cin>>a;
           if (a=='L' || a=='l'){
               cout<<"You're successfully logout!";
               
            }
   
           else if(a=='Y' || a=='y') 
                 portal_menu();
         } 



    
         void Transcript_Details_Talha(){     //NUMBER 13   TALHA'S TRANSCRIPT
    
           cout<<"Your 1st Semester details are:"<<endl;
           cout<<"COURSES                        GRADES"<<endl;
            
           cout<<"Programming Fundamentals         B+"<<endl; 
           cout<<"Programming Fundamentals LAB     A"<<endl; 
           cout<<"ICT                              B"<<endl; 
           cout<<"ICT LAB                          A"<<endl; 
           cout<<"Applied Physics                  A"<<endl; 
           cout<<"Applied Physics LAB              A"<<endl;
           cout<<"Calculus 1                       A"<<endl;
           cout<<"English 1                        A"<<endl;
           cout<<"Your current CGPA is 3.74";
            

         }


       
         void Transcript_Details_Javeria(){    //NUMBER 14   JAVERIA'S TRANSCRIPT
    
           cout<<"Your 1st Semester details are:"<<endl;
           cout<<"COURSES                        GRADES"<<endl;
            
           cout<<"Programming Fundamentals         B"<<endl; 
           cout<<"Programming Fundamentals LAB     B+"<<endl; 
           cout<<"ICT                              B"<<endl; 
           cout<<"ICT LAB                          A-"<<endl; 
           cout<<"Applied Physics                  B-"<<endl; 
           cout<<"Applied Physics LAB              B-"<<endl;
           cout<<"Calculus 1                       A-"<<endl;
           cout<<"English 1                        B+"<<endl;
           cout<<"Your current CGPA is 3.00";
            

         }

 

         void Transcript_Details_Ali(){    //NUMBER 15   ALI'S TRANSCRIPT
    
           cout<<"Your 1st Semester details are:"<<endl;
           cout<<"COURSES                        GRADES"<<endl;
            
           cout<<"Programming Fundamentals         A"<<endl; 
           cout<<"Programming Fundamentals LAB     B"<<endl; 
           cout<<"ICT                              C"<<endl; 
           cout<<"ICT LAB                          A-"<<endl; 
           cout<<"Applied Physics                  B-"<<endl; 
           cout<<"Applied Physics LAB              B"<<endl;
           cout<<"Calculus 1                       A-"<<endl;
           cout<<"English 1                        B+"<<endl;
           cout<<"Your current CGPA is 3.41";
            

         }




         void Transcript_Details_Saad(){    //NUMBER 16   SAAD'S TRANSCRIPT
    
           cout<<"Your 1st Semester details are:"<<endl;
           cout<<"COURSES                        GRADES"<<endl;
            
           cout<<"Programming Fundamentals         A-"<<endl; 
           cout<<"Programming Fundamentals LAB     A"<<endl; 
           cout<<"ICT                              A"<<endl; 
           cout<<"ICT LAB                          A"<<endl; 
           cout<<"Applied Physics                  A-"<<endl; 
           cout<<"Applied Physics LAB              B"<<endl;
           cout<<"PRE Calculus                     A"<<endl;
           cout<<"English 1                        B+"<<endl;
           cout<<"Your current CGPA is 3.71";
            

         }


    
         void repeat_SoftwareScreen(){     //NUMBER 17
    
           int t;
           cout<<"Enter the number:"<<endl;
           cin>>t;

           if (t==1){
              SET_admin_login();
            } 

           else if(t==2){
               student_Login();
            }
     
           else if(t==3){
               cout<<"AS YOU WISH! Have a NICE DAY.";
            }
      
         }
       



         void again(){     //NUMBER 18
    
           char tal;

           cout<<"\nDo you want to use the SOFTWARE again or want to EXIT:\n Press any key to Exit\n Press Y to use it again."<<endl;
           cin>>tal;
           if(tal=='y' || tal=='Y'){
                 
           cout<<"\n\n   ---------WELCOME TO---------"<<endl;
           cout<<"---------UMT Management System---------"<<endl;  
            
           cout<<endl;  
           cout<<"1. ADMIN Portal";
           cout<<endl;
           cout<<"2. STUDENT Portal";
           cout<<endl;
           cout<<"3. Exit"<<endl;         
           
           repeat_SoftwareScreen();
      
           } 

           else 
           cout<<"THANKS FOR USING! Have a NICE DAY."<<endl;
         }      


      ~portal(){     //Destructor

      }     
        
        
};


void AssignVariable(portal a){
	a.password1 = "Null";
	a.password2 = "Null";
	a.password3 = "Null";
	a.password4 = "Null";
	a.adminPass = "Null";
	a.adminUsername = "Null";
}


class unity:public Main_Screen,public portal{     // Multiple Inheritance    
//Child      // Parent 1        // Parent 2  

}; 


int main(){
 
    portal obj1;  // Parent class Object
    
    unity obj2;  // Child classs Object 
    
    AssignVariable(obj1); //obj2 can also come so don't worry bro! 
      
    obj2.repeat_SoftwareScreen();  //ALHAMDULLILAH Successfully Inherited!
    obj2.again();  
    obj2.Developer_of_program(); // Pure virtual function calling 

    
    
    
    // Shallow Copy 
    // unity obj3 = obj2;
    // obj3.repeat_SoftwareScreen();  //ALHAMDULLILAH Successfully Inherited!
    // obj3.again();  
    // obj3.Developer_of_program(); // Pure virtual function calling 
 

    return 0;
}