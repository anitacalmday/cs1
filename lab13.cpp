//
//  main.cpp
//  lab_13
//
//  Created by Anita Calmday on 4/13/17.
//  Copyright © 2017 Anita Calmday. All rights reserved.
//
// Your program should read the data from the input file and store this data in the appropriate place in the array of structs called students.
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
//structs
struct Address_type //holds address from infile
{
    int street_no;
    string street_name;
    string city;
    string state;
    int zip;
};
struct student_type //holds all other student details
{
    string lname;
    string fname;
    int ID;
    float GPA;
    char classification;
    float account_balance;
    Address_type student_address;
};
void print_students(student_type[]); // prototype
int main()
{
    student_type student[5]; //declare array
    ifstream myfile;
    myfile.open("infile.txt"); //open file
    char dummy;
    for (int i = 0; i < 5; i++) //loop that adds info from myfile to arrays of structs
    {
        myfile >>  student[i].lname >> student[i].fname >> student[i].ID >> student[i].GPA >> student[i].classification >> student[i].account_balance;
        myfile >> student[i].student_address.street_no;
        myfile.get(dummy);
        getline(myfile, student[i].student_address.street_name);
        myfile >> student[i].student_address.city;
        myfile >> student[i].student_address.state;
        myfile >> student[i].student_address.zip;
    }
    print_students(student);
    myfile.close(); //close file
    return 0;
}
//A report of the data should be displayed using a function called print_students that has the array of structs (students) as its only parameter.
void print_students(student_type student[])
{
    cout << "STUDENT NAME" << setw(10)<< "ID" << setw(10)<< "GPA"<<setw(24) << "CLASSIFICATION"<<setw(20) << "ACCOUNT BALANCE" << setw(20) << "ADDRESS" << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << fixed << showpoint << setprecision(2);
        cout << student[i].lname << " " << student[i].fname <<  "\t" <<setw(12) <<student[i].ID << setw(12)<< student[i].GPA << setw(12)<< student[i].classification << setw(20)<< student[i].account_balance<<setw(12) << student[i].student_address.street_no<< " "<< student[i].student_address.street_name<<" " << student[i].student_address.city<<" " <<student[i].student_address.state<< " " <<student[i].student_address.zip<< endl;
        cout << " " << endl;
    }
}
/*
 STUDENT NAME        ID       GPA          CLASSIFICATION     ACCOUNT BALANCE             ADDRESS
 Smith John       123456        3.40           J             1750.40         302 Fairmont St NW Washington DC 20059
  
 James Frank           78910        2.70           F             1940.70         302 Sixth St SW Washington DC 20059
  
 Joe Kris          78910        2.70           F            23212.21         302 Sixth St SW Washington DC 20059
  
 Jana Landon           78910        3.70           F             1940.70         302 Fourth St SW Washington DC 20059
  
 Aiden Frank           78910        2.70           F             1940.70         302 Sixth St SW Washington DC 2005
 */
