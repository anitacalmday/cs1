//
//  main.cpp
//  lab9
//
//  Created by Anita Calmday on 3/23/17.
//  Copyright © 2017 Anita Calmday. All rights reserved.
//
 
#include <iostream>
#include <iomanip>
using namespace std;
void GetData(int&, int&); //prototypes
void PrintData(int&, int&);
int main()
{
    //declare variables
    int hours;
    int miles;
    hours = 0;
    miles = 0;
    GetData(miles, hours); //call functions
    PrintData(miles,hours);
    return 0;
}
// Function GetData prompts the user for the appropriate values, reads them, and returns them to function main.
void GetData(int& miles, int& hours)
{
    cout << "Enter the number of miles: "; //prompts the user for the appropriate values
    cin >> miles;
    cout << "Enter the number of hours: ";
    cin >> hours;
}
// sends these value to the function PrintData where miles are divided by hours and these figures are printed with appropriate labels
void PrintData(int& miles, int& hours)
{
    float total;
    total = float(miles)/hours;
    cout << "The number of  miles is " << miles << endl;
    cout << "The number of hours is " << hours << endl;
    cout << "The number of miles per hour is " << setprecision(4) << total << endl;
    return ;
}
 
/*
 Enter the number of miles: 12340
 Enter the number of hours: 460
 The number of  miles is 12340
 The number of hours is 460
 The number of miles per hour is 26.83*/
 
 
 
 
 //
//  main.cpp
//  lab9b
//
//  Created by Anita Calmday on 3/23/17.
//
//
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
void get_user_input(char&, int&, int&, int&, int&); //prototypes
float compute_item_cost (char, int, int, int, int);
int main()
{
    //declare variables
    int no_pieces;
    int width;
    int length;
    int heigth;
    char wood_type;
    float price;
    float total;
    get_user_input(wood_type, no_pieces, width, heigth, length); //priming read
    while (wood_type != 'T')
    { //loop to run while user wants lumber.
        price=compute_item_cost(wood_type, no_pieces, width, heigth, length);
        total += price;
        cout << fixed << showpoint << setprecision(2);
        cout << " " << "cost: "  <<  price << endl;
        cout << "***************************************************" << endl ;
        get_user_input(wood_type, no_pieces, width, heigth, length);
    }
    cout << "Total Cost: " << total << endl;
    return 0;
}
//get user input needed to calculate pricea nd also output what the user enters.
void get_user_input(char& wood_type, int& no_pieces, int& width, int& height, int&length)
{
    cout << "Enter item (Wood Type -- No of pieces -- Width -- Height -- Length)" << endl; // ask user for input
    cin >> wood_type;
    //When the letter is T, there are no integers following it on the line.
    if (wood_type != 'T')
    {
        cin  >> no_pieces >> width >> height >> length; //receive input from user
    }
    if (wood_type == 'P')
    {
         cout << no_pieces << " " << width << "X" << height << "X" << length << " " << "Pine" << "," ;
    }
    else if (wood_type == 'M')
    {
         cout << no_pieces << " " << width << "X" << height << "X" << length << " " << "Maple" << "," ;
    }
    else if (wood_type == 'O')
    {
        cout << no_pieces << " " << width << "X" << height << "X" << length << " " << "Oak" << "," ;
    }
    else if (wood_type == 'F')
    {
        cout << no_pieces << " " << width << "X" << height << "X" << length << " " << "Fir" << "," ;
    }
    else if (wood_type == 'C')
    {
        cout << no_pieces << " " << width << "X" << height << "X" << length << " " << "Cedar" << "," ;
    }
    length = length * 12; // convert length from feet to inches
}
//compute price based on dimensions and type of wood
float compute_item_cost (char wood_type, int no_pieces, int width, int height, int length)
{
    float board_feet;
    float price;
    board_feet = (float(width)*float(height)*float(length))/144.0; //calculate board feet
    cout << fixed << showpoint << setprecision(2);
    if (wood_type == 'C')
    {
        price = board_feet * float(no_pieces) *2.26;
        return price;
    }
    else if (wood_type == 'M')
    {
        price = float(no_pieces)*board_feet*4.50;
        return price;
    }
    else if (wood_type == 'O')
    {
        price= board_feet * float(no_pieces )* 3.10;
        return price;
    }
    else if (wood_type == 'P')
    {
        price = board_feet * float(no_pieces) *0.89;
        return price;
    }
    else if (wood_type == 'F')
    {
        price = board_feet * float(no_pieces) *1.09;
        return price;
    }
     
    return price;
     
}
/*
 Enter item (Wood Type -- No of pieces -- Width -- Height -- Length)
 P 10 2 4 8
 10 2X4X8 Pine, cost: 47.47
 ***************************************************
 Enter item (Wood Type -- No of pieces -- Width -- Height -- Length)
 M 1 1 12 8
 1 1X12X8 Maple, cost: 36.00
 ***************************************************
 Enter item (Wood Type -- No of pieces -- Width -- Height -- Length)
 T
 Total Cost: 83.47*/
