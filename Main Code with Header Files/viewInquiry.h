#ifndef VIEWINQUIRY_H
#define VIEWINQUIRY_H


#include<iostream>
#include"AccountDetails.h"
using namespace std;
class viewInquiry : public AccountDetails//COMPLETEd
{
public:
    viewInquiry();
	void display();
	void checkPIN(char* PIN);
	void cardManagement();
    ~viewInquiry();
};

#endif