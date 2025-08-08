// header functions
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
// class
class temp{
    string username,Email,Password;
    string searchName, searchPass,searchEmail;
    fstream file;
    public:
    void login();
    void singup();
    void forgetpass();

}obj;
// my main function with switch case
int main(){
   char choice;
   cout<<"\n1- Login";
   cout<<"\n2- Sign-Up";
   cout<<"\n3- Forget Password";
   cout<<"\n4- Exit";
   cout<<"\nEnter Your Choice";
   cin>>choice;
   switch (choice)
   {
   case '1':
   obj.login();
    break;
   case '2':
    obj.singup();
    break;
   case '3':
   obj.forgetpass();
    break;
   case '4':
   return 0;
    break;
   
   default:
   cout<<"Invalid Selection...!";
   } 
}
// the void function terminalogy here to access those properly

void temp :: singup(){
    cout<<"Enter your user name:: ";
    getline(cin, username);
    cout<<"\nEnter your Email Address:: ";
    getline(cin,Email);
    cout<<"Enter your Password:: ";
    getline(cin,Password);

    file.open("loginData.txt", ios :: out | ios :: app);
    file<<username<<"*"<<Email<<"*"<<Password<<endl;
    file.close();
}
void temp :: login(){
    
    cout<<".........Login.........."<<endl;
    cout<<"\n Enter your User Name:: "<<endl;
    getline(cin,searchName);
    cout<<"Enter your password:: "<<endl;
    getline(cin,searchPass);

    file.open("loginData.txt", ios :: in);
    getline(file,username,'*');
    getline(file,Email,'*');
    getline(file,Password,'\n');
    while (!file.eof())
    {
        if (username == searchName)
        {
            if (Password == searchPass)
            {
                cout<<"\n Account Login is Sucessfull";
                cout<<"\n UserName:: "<<username<<endl;
                cout<<"\n Email:: "<<Email<<endl;
            }
            else{
                cout<<"password is incurrect";
            }
            
        }
    getline(file,username,'*');
    getline(file,Email,'*');
    getline(file,Password,'\n');
        
    }
    file.close();
}
void temp ::forgetpass(){
    cout<<"\n Enter your usename:: ";
    getline(cin,username);
    cout<<"\n Enter your Email Address:: ";
    getline(cin,Email);
    file.open("loginData.txt", ios :: in);
    getline(file,username,'*');
    getline(file,Email,'*');
    getline(file,Password,'\n');
    while (!file.eof())
    {
        if (username==searchName)
        {
            if (Email==searchEmail)
            {
                cout<<"\n Account Found "<<endl;
                cout<<"\n Your password:: "<<Password<<endl;
            }
            else{
                cout<<"Not Found please signup again\n";
            }
            
        }
        else{
            cout<<"\n Not found...\n";
        }
        
    }
    file.close();
    
}