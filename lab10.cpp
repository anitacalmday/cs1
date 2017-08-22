//
//  main.cpp
//  lab9a
//
//  Created by Anita Calmday on 3/30/17.
//  Copyright © 2017 Anita Calmday. All rights reserved.
//
 
/*Your grandmother has just come back from the doctor's office and is confused about all the numbers that were used to evaluate her health. The nurse weighed her, took her blood pressure, noted her cholesterol levels from her lab work, and told her to sit down, because the doctor would be in to see her shortly. After half an hour the doctor came in, looked at your grandmother's chart, smiled, and said she was fine. In looking over the report she gave your grandmother, you realize that there could be a market for a program that explains this information to patients.  */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
void evaluate_cholesterol(int, int, string&, string&); //prototypes
void evaluate_blood_pressure(int, int, string&, string&);
int main(int argc, const char * argv[]) {
    string HDL_Evaluation, LDL_Evaluation, Systolic_Evaluation, Diastolic_Evaluation; //declare variables
    int no_patient_record;
    cout << "Enter the number of patient records: " ; //prompt the user  to enter the number of patient's recoreds to be read from the file.
    cin >> no_patient_record; //get user input
    cout << endl;
    //more variables
    int counter;
    float ratio;
    counter = 0; //counters
    int i;
    i = 0;
    ifstream myfile;
    myfile.open("infile.txt"); //open file
    string name;
    char status;
    int doc_visit;
    int HDL, LDL, SYS, DIA;
     
    for (counter = 0;  counter < no_patient_record; counter ++) //counter controlled loop that reads each patient's data
    {
        myfile >> name >> status >> doc_visit; //read in name and status and visits.
        cout << "Current Patient's Name- " << name << endl << endl; //output name
        for (i = 1; i <= doc_visit; i++) //counter controlled loop that reads each set of patients readings.
        {
            //loop calls the two void functions declared.
            cout << "DATA SET " << i << endl;
            myfile >> HDL >> LDL >> SYS >> DIA; //read in info.
            ratio = float(HDL)/float(LDL);
            cout << "Cholesterol Profile" << endl;
            evaluate_cholesterol(HDL, LDL, HDL_Evaluation, LDL_Evaluation);
            cout << "  HDL: " << HDL << " " << "LDL: " << LDL << endl;
            cout << "  Ratio: " << fixed << showpoint << setprecision(4) << ratio << endl;
            cout << "  HDL is " << HDL_Evaluation << endl;
            cout << "  LDL is " << LDL_Evaluation << endl;
            cout << "Blood Pressure Profile " << endl;
            evaluate_blood_pressure(SYS, DIA, Systolic_Evaluation, Diastolic_Evaluation);
            cout << "  Systolic: " << SYS << " " << "Diastolic: " << DIA << endl;
            cout << "  Systolic reading is " << Systolic_Evaluation << endl ;
            cout << "  Diastolic reading is " << Diastolic_Evaluation << endl ;
            cout << endl;
        }
    }
    myfile.close(); //close file
    return 0;
}
//this loop uses nested if statements to evaluate patient's cholestorol
void evaluate_cholesterol(int HDL_Reading, int LDL_Reading, string& HDL_Evaluation, string& LDL_Evaluation)
{
    if (HDL_Reading<40)
     
        HDL_Evaluation = "Too low";
         
    else
        if (HDL_Reading < 60 )
                HDL_Evaluation = "Is okay";
            else
                HDL_Evaluation = "Excellent";
         
    if (LDL_Reading<100)
         
        LDL_Evaluation = "Optimal";
    else
        if (LDL_Reading < 130)
            LDL_Evaluation = "Near Optimal";
        else
            if (LDL_Reading < 160)
                LDL_Evaluation = "Borderline high";
            else
                if (LDL_Reading < 190)
                    LDL_Evaluation = "High";
                else
                    LDL_Evaluation = "very high";
     
}
//this loop uses nested if statements to evaluate blood pressure.
void evaluate_blood_pressure(int Systolic_Reading, int Diastolic_Reading, string& Systolic_Evaluation, string& Diastolic_Evaluation)
{
    if (Systolic_Reading < 120)
        Systolic_Evaluation = "Optimal";
    else
        if (Systolic_Reading < 130 )
            Systolic_Evaluation = "Normal";
        else
            if (Systolic_Reading < 140)
                Systolic_Evaluation = "Normal high";
            else
                if (Systolic_Reading < 160)
                    Systolic_Evaluation = "Stage 1 hypertension";
                else
                    if (Systolic_Reading <  180)
                        Systolic_Evaluation = "Stage 2 hypertension";
                    else
                        Systolic_Evaluation = "Stage 3 hypertension";
     
    if (Diastolic_Reading < 80)
        Diastolic_Evaluation = "Optimal";
    else
        if (Diastolic_Reading < 85 )
            Diastolic_Evaluation = "Normal";
        else
            if (Diastolic_Reading < 90)
                Diastolic_Evaluation = "Normal high";
            else
                if (Diastolic_Reading < 100)
                    Diastolic_Evaluation = "Stage 1 hypertension";
                else
                    if (Diastolic_Reading <  110)
                        Diastolic_Evaluation = "Stage 2 hypertension";
                    else
                        Diastolic_Evaluation = "Stage 3 hypertension";
}
/*
 Enter the number of patient records: 4
  
 Current Patient's Name- Jones
  
 DATA SET 1
 Cholesterol Profile
 HDL: 60 LDL: 124
 Ratio: 0.4839
 HDL is Excellent
 LDL is Near Optimal
 Blood Pressure Profile
 Systolic: 130 Diastolic: 84
 Systolic reading is Normal high
 Diastolic reading is Normal
  
 DATA SET 2
 Cholesterol Profile
 HDL: 65 LDL: 121
 Ratio: 0.5372
 HDL is Excellent
 LDL is Near Optimal
 Blood Pressure Profile
 Systolic: 133 Diastolic: 80
 Systolic reading is Normal high
 Diastolic reading is Normal
  
 DATA SET 3
 Cholesterol Profile
 HDL: 70 LDL: 120
 Ratio: 0.5833
 HDL is Excellent
 LDL is Near Optimal
 Blood Pressure Profile
 Systolic: 130 Diastolic: 81
 Systolic reading is Normal high
 Diastolic reading is Normal
  
 Current Patient's Name- Smith
  
 DATA SET 1
 Cholesterol Profile
 HDL: 30 LDL: 195
 Ratio: 0.1538
 HDL is Too low
 LDL is very high
 Blood Pressure Profile
 Systolic: 120 Diastolic: 85
 Systolic reading is Normal
 Diastolic reading is Normal high
  
 Current Patient's Name- Williams
  
 DATA SET 1
 Cholesterol Profile
 HDL: 45 LDL: 185
 Ratio: 0.2432
 HDL is Is okay
 LDL is High
 Blood Pressure Profile
 Systolic: 190 Diastolic: 112
 Systolic reading is Stage 3 hypertension
 Diastolic reading is Stage 3 hypertension
  
 DATA SET 2
 Cholesterol Profile
 HDL: 50 LDL: 181
 Ratio: 0.2762
 HDL is Is okay
 LDL is High
 Blood Pressure Profile
 Systolic: 193 Diastolic: 115
 Systolic reading is Stage 3 hypertension
 Diastolic reading is Stage 3 hypertension
  
 Current Patient's Name- Foster
  
 DATA SET 1
 Cholesterol Profile
 HDL: 55 LDL: 165
 Ratio: 0.3333
 HDL is Is okay
 LDL is High
 Blood Pressure Profile
 Systolic: 163 Diastolic: 115
 Systolic reading is Stage 2 hypertension
 Diastolic reading is Stage 3 hypertension
  
 DATA SET 2
 Cholesterol Profile
 HDL: 65 LDL: 145
 Ratio: 0.4483
 HDL is Excellent
 LDL is Borderline high
 Blood Pressure Profile
 Systolic: 167 Diastolic: 95
 Systolic reading is Stage 2 hypertension
 Diastolic reading is Stage 1 hypertension
  
 DATA SET 3
 Cholesterol Profile
 HDL: 57 LDL: 165
 Ratio: 0.3455
 HDL is Is okay
 LDL is High
 Blood Pressure Profile
 Systolic: 163 Diastolic: 105
 Systolic reading is Stage 2 hypertension
 Diastolic reading is Stage 2 hypertension
  
 DATA SET 4
 Cholesterol Profile
 HDL: 59 LDL: 163
 Ratio: 0.3620
 HDL is Is okay
 LDL is High
 Blood Pressure Profile
 Systolic: 165 Diastolic: 108
 Systolic reading is Stage 2 hypertension
 Diastolic reading is Stage 2 hypertension
*/
