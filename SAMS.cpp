#include <iostream>
#include <cstring>
#include <sstream> 
#include <fstream> 
#include <ctime>
#include <stdio.h>

using namespace std;

void delay() {
	for(int i = 0; i<3; i ++)
	{
	cout<<"\nSaving Records...";
    for(int ii = 0; ii<20000; ii ++)
	{
    for(int iii = 0; iii<20000; iii ++)
    { }
    }
	}
	cout<<"\nExiting Now...";
	for(int i = 0; i<3; i ++) {
   	for(int ii = 0; ii<20000; ii ++) { 
    for(int iii = 0; iii<20000; iii ++) {
	}
    } 
	}
	}
	
int countMyAttendance(string username) {
	int total_lines = 0;
	string filename = username+".dat";
	ifstream read;
	read.open(filename.c_str(), ios::app);
	string line;
	while(getline(read,line)) {
	++ total_lines;
	}
	read.close();
	ifstream read1;
	read1.open(filename.c_str(), ios::app);
	if(read1)
	{	
	int line_no = 0;
	while (line_no != total_lines && getline(read1, line)) {
    ++line_no;
	}
	if (line_no == total_lines) {
		cout<<"\nTotal present: "<<line;
	}
	}
cout<<"\nPlease any key to continue..";
getchar();getchar();
delay();
return 0;	
}
	
void checkListOfStudentsRegistered() {
	cout<<"\n######## Check List of Student Registered by Username ########";	
	
	//check if record already exist..
	ifstream read;
	read.open("db.dat");
	if(read)
	{   
	int recordFound = 0; 
    string line;
    while(getline(read, line)) {
    char name[100];
    strcpy(name, line.c_str());
    string filename = name;
    cout<<"\n"<<filename;
    char onlyname[100];
    strncpy(onlyname, name, (strlen(name) - 4));
    cout<<"\n"<< onlyname[100];
    }
    read.close();        
	}
	else
	{
	cout<<"\nNo Record found...";
	}
	cout<<"\nPlease any key to continue..";
	getchar(); getchar();
}

void registerStudent() {
	system("cls");
    cout<<"\n ######## Form to Register a Student ######## \n";	
    string students_first_name, students_middle_name, students_last_name, mothers_first_name, mothers_middle_name, mothers_last_name, fathers_first_name, fathers_middle_name, fathers_last_name, username, password, rollno, address, father, mother;
    cout<<"\nEnter Name (First Name, Middle Name, Last Name): ";     
	cin>>students_first_name >>students_middle_name >>students_last_name ;
    cout<<"\nEnter Username (Use Letters Only): ";     
	cin>>username;
    cout<<"\nEnter Password: ";     
	cin>>password;
    cout<<"\nEnter Roll Number: ";     
	cin>>rollno;
    getchar();
    char add[150];
    cout<<"\nEnter Address: ";     
	cin.getline(add, 100);
    cout<<"\nEnter Father's Name (First Name, Middle Name, Last Name): ";     
	cin>>fathers_first_name>>fathers_middle_name>>fathers_last_name;
    cout<<"\n Enter Mother's Name (First Name, Middle Name, Last Name): ";     
	cin>>mothers_first_name>>mothers_middle_name>>mothers_last_name;
    
    //check if record already exist..
    ifstream read;
    read.open("db.dat");
    if(read)
    {   
	int recordFound = 0; 
	string line;
	while(getline(read, line)) {
    if(line == username+".dat" )
    {
    recordFound = 1 ;
    break;
	}
    }
    if(recordFound == 1)
    {
    cout<<"\n Username is already used. Please choose another username...";
    getchar(); getchar();
    delay();
    read.close();
	}
	}
    read.close();
    ofstream out;
	out.open("db.dat", ios::app);
	out<<username+".dat"<<"\n";
	out.close();
	ofstream out1;
	string temp = username+".dat";
	out1.open(temp.c_str());
	out1<<"Student name (First Name, Middle Name, Last Name): "<<students_first_name<<" "<<students_middle_name<<" "<<students_last_name<<"\n"; 	
	out1<<"Username (Use Letters Only): "<<username<<"\n"; 	
	out1<<"Password: "<<password<<"\n";
	out1<<"Roll Number: "<<rollno<<"\n"; 	
	out1<<"Address: "<<add<<"\n"; 	
	out1<<"Father's name (First Name, Middle Name, Last Name): "<<fathers_first_name<<" "<<fathers_middle_name<<" "<<fathers_last_name<<"\n";
	out1<<"Mother's name (First Name, Middle Name, Last Name): "<<mothers_first_name<<" "<<mothers_middle_name<<" "<<mothers_last_name <<"\n";
	out1<<"\n\n\nAttendance Records:\n";
	out1.close();
	cout<<"\n Student Registered Successfully !!";
    cout<<"\n Please any key to continue...";
	getchar(); getchar();	
}

int checkStudentCredentials(string username, string password) {
	// read file line by line & check if username-password.dat exist?
	// if it exsist return 1 else 0
	ifstream read;
	read.open("db.dat");
	if (read) {
	// The file exists, and is open for input
	int recordFound = 0;
	string line;
	string temp = username + ".dat";
	cout<<"\nFile name is: "<<temp;
	while(getline(read, line)) {
	if(line == temp)
	{
	recordFound = 1;
	break;
	}
    }
	if(recordFound == 0)
    return 0;
    else
    return 1;
	}
	else
	{
    return 0;
	}		
}

void takeStudentAttendance()
{   ifstream read;
    read.open("db.dat");
    if(read)
    {       
	int recordFound =0; 
	string line;
    while(getline(read, line)) {	    	
    char name[100];
    strcpy(name, line.c_str());
    string filename = name;
    int total_lines = 0;
    ifstream read1;
	read1.open(filename.c_str(), ios::app);
	string line;
	while(getline(read1,line)){
	++ total_lines;
	}
    read1.close();
	ifstream read;
	read.open(filename.c_str(), ios::app);
	// ifstream read;
	// read.open("db.dat");
    cout<<"Name: "<<filename<<endl;
    int c;
    cout<<"1: Present:"<<"\t"<<"O : Absent:"<<endl;
    cout<<"Enter your choice:"<<endl;
    cin>>c;
    switch(c)
    {
        case 1: 
                { 
				string line;
                if(read)
                {	
                int line_no = 0;
                while (line_no != total_lines && getline(read, line)) {
                ++line_no;
                }
                if (line_no == total_lines) {
                int i;
                stringstream(line)>>i;
                i++;
            	ofstream out1;
                string temp = name;
                out1.open(temp.c_str(), ios::app);
                out1<<i<<"\n";
                }
                }	
                break;
                }
        case 0:
                break;
    }
    read.close();        
    }
    }
    read.close();

cout<<"\n Please any key to continue..";

getchar();getchar();
}

void studentLogin() {
	system("cls");
	cout<<"######## STUDENT LOGIN ########\n\n\n";
	string username, password;
	cout<<"\nEnter username: ";
	cin>>username;
	cout<<"\nEnter password: ";
	cin>>password;
	int res = checkStudentCredentials(username, password);
	if(res != 1) {	
    cout<<"\n Invalid Credentials !!";
    cout<<"\n Press any key for Main Menu..";
    getchar(); getchar();    
    return ;
	} 

    int goBack = 0;
    while(1) {
    system("cls");
    cout<<"\n1. Count my Attendance";
    cout<<"\n2. Send a leave application";
    cout<<"\n0. Go Back <- \n";
    int choice;
    cout<<"\nEnter your choice: ";
    cin>>choice;
    switch(choice) {
    	case 1: countMyAttendance(username);
				break;
        //case 2: sendLeaveApplication(username);
				break;
        case 0: goBack = 1;
				break;
        default: 
				cout<<"\n Invalid choice. Enter again ";
                getchar();              
        }   
        if(goBack == 1) {
        break;
        }     
   		}
}

void deleteStudentData() {
	// Delete student_user_name.dat file
	char studname[20];
	string studname1;
	string line;
	int status;
	cout<<"\nEnter the username of the student: ";
	cin>>studname;
	status = remove(studname);
	if (status == 0) {
	cout<<"File deleted successfully!\n";
	}
	else {
	cout<<"Student data failed to delete...\n";
	}		
	cout<<"\nPlease any key to continue...";
	getchar();getchar(); 
	
	// Delete "student_user_name.dat" line of data from db.dat file
	studname1 = studname;
	ifstream fin;
	fin.open("db.dat");
	ofstream temp;
	temp.open("temp.dat");
	while (getline(fin, line)) {
	if (line != studname1) {
	temp << line << endl;
	}
	}
	temp.close();
	fin.close();
	remove("db.dat");
	rename("temp.dat", "db.dat");
}

void adminView() {
	int goBack = 0;
	while(1)
	{
	system("cls");
	cout<<"\n 1. Register a Student";
	cout<<"\n 2. Delete student data";
	cout<<"\n 3. Check List of registered students by username";
	cout<<"\n 0. Go Back <- \n";
	int choice;

	cout<<"\n Enter your choice: ";
	cin>>choice;

	switch(choice)
	{
	case 1: registerStudent();
			break;  
	case 2: deleteStudentData();
			break;
	case 3: checkListOfStudentsRegistered(); 
			break;
	case 0: goBack = 1;
	break;
    default: cout<<"\n Invalid choice. Enter again...";
    getchar();           	
	}   
	if(goBack == 1)
	{
	break; //break the loop
	}     
	}
	}	

void adminLogin() {
	system("cls");
	cout<<"\n ######## Admin Login ########\n\n\n";	
	string username;
	string password;
	cout<<"\n Enter username: ";
	cin>>username;
	cout<<"\n Enter password: ";
	cin>>password;
	if(username=="co.tpoly" && password=="co.tpoly@123") {
    adminView();
    getchar();	
    delay();
	}   
	else {
	cout<<"\n Error! Invalid Credintials...";	
	cout<<"\n Press any key for main menu...";
	getchar();getchar();
	}
}

void teacherView() {
	int goBack = 0;
    while(1)
    {
    system("cls");
    cout<<"\n1. Take Student Attendance";
    cout<<"\n0. Go Back <- \n";
    int choice;    
    cout<<"\nEnter your choice: ";
    cin>>choice;    
    switch(choice)
    {
    case 1: takeStudentAttendance();
			break;  
    case 0: goBack = 1;
			break;
    default: cout<<"\nInvalid choice. Enter again ";
    getchar();        
	delay();     
    }     
    if(goBack == 1) {
    break; 
	}    
    }
}

void teacherLogin() {
	system("cls");
    cout<<"\n######## Teacher Login ########\n\n\n";   
    string username;
    string password;
    cout<<"\nEnter username: ";
    cin>>username;
    cout<<"\nEnter password: ";
    cin>>password;
    if(username=="ks_co.tpoly" && password=="ks_co.tpoly@123") 
    {   
	teacherView();
    getchar();  
    }   
    else
    {
    cout<<"\nError! Invalid Credintials...";   
    cout<<"\nPress any key for main menu...";
    getchar();
    delay();
	}
}

// Main Function
int main (int argc, char** argv) {
	while(1) {
	system("cls");
	cout<<"########        STUDENT ATTENDANCE MANAGEMENT SYSTEM        ########\n\n\n"<<endl;
	cout<<"1. Student Login\n";
	cout<<"2. Admin Login\n";
	cout<<"3. Teacher Login\n";
	cout<<"0. Exit\n";
	int choice;
	cout<<"\n\n\nEnter your choice: ";
	cin>>choice;
	switch(choice)
	{
	case 1: studentLogin();
			break;
	case 2: adminLogin();
			break;
	case 3: teacherLogin();
			break;
	case 0: 
	        while(1)
	        {
		    system("cls");
        	cout<<"\nAre you sure, you want to exit? (yes | no)\n";
        	char ex;
        	cin>>ex;
        	if(ex == 'y' || ex == 'Y') {
			cout<<"Thank you for using Student Attendance Management System...\n\n\n\nDevelopers:\nBhargav Gajare\nOm Awadhoot\nSurabhi Mane\n";
        	exit(0);
        	}
        	else if(ex == 'n' || ex == 'N')
            {
            break;
            }
            else {
            cout<<"\nInvalid choice !!!";
           	getchar();
            }
     	    }
            break;	 
    default: cout<<"\nInvalid choice. Enter again...";
    getchar();
	return 0;
	}
}
}