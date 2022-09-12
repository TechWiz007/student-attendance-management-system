#include "user.h"
using namespace std; 

class student : public user {   
    string username,password;
    public:
    void studentView();
    int checkStudentCredentials(string username,string password);
    int Attendance(string username);
    int sendLeaveApplication(string username);
};