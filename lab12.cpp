//
//  main.cpp
//  lab_12
//
//  Created by Anita Calmday on 4/11/17.
//  Copyright © 2017 Anita Calmday. All rights reserved.
//
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
/* prototypes */
void Get_store_data(string[], float[][5], ifstream&);
float Compute_store_total(int, float[][5]);
void Display_store_data(string[], float[][5], float[]);
int main()
{
    /* array declarations */
    string store_names[7];
    float store_sales[7][5];
    float store_totals[7];
    /* define infile */
    ifstream myfile;
    /* open file */
    myfile.open("infile.txt");
    /* call get store function */
    Get_store_data(store_names, store_sales, myfile);
    /* using a for loop, the main function should call the Compute_sales_total function sending it each of the seven indices for the rows of the sales array. */
    for (int i  = 0; i < 7; i++)
    {
       Compute_store_total(i, store_sales);
       store_totals[i] = Compute_store_total(i, store_sales);
    }
    Display_store_data(store_names, store_sales, store_totals);
    return 0;
}
/*
 In the Get_store_data function, you must use a nested loop to read and store the data into the array of store names and into the two-dimensional store sales array.
 */
void Get_store_data(string store_names[], float store_sales[][5], ifstream& myfile)
{
    string store_name;
    for (int i = 0; i < 7; i++)
    {
        myfile >> store_name;
        store_names[i] = store_name;
        for (int j = 0; j < 5; j++)
        {
            myfile >> store_sales[i][j];
        }
    }
}
/*In the Compute_sales_total function, the store index is used to read the sales figures in the indicated row of the sales array. Using a for statement, this function should total the sales amounts and return this total to main. */
float Compute_store_total(int store_index, float store_sales[][5])
{
    float total=0;
    for (int i = 0; i < 5; i ++ )
    {
        total += store_sales[store_index][i];
    }
    return total;
}
// the Display_Store_Data function send it the store sales array, the store names array, and the store totals array. This function simply prints a heading and then, using a counter-controlled loop, print the corresponding data from each array
void Display_store_data(string store_names[], float store_sales[][5], float store_totals[])
{
    cout << "Store Name" << setw(15) << "JAN" << setw(15)<<"FEB"<<setw(12)<< "MAR"<<setw(12) << "APR" <<setw(12)<< "MAY" <<setw(12)<< "TOTAL" <<setw(12)<< endl;
    cout << " " << endl;
    cout << fixed  << showpoint << setprecision(2);
    for (int i = 0; i < 7; i++)
    {
        cout << store_names[i];
        if (store_names[i].length() < 10)
        {
            cout << "\t\t" ;
        }
        else
        {
            cout << "\t";
        }
        for (int j  = 0; j < 5; j++ )
        {
            cout  << setw(12) << store_sales[i][j];
        }
        cout << setw(12) << store_totals[i] << endl;
    }
}
/*
 Store Name            JAN            FEB         MAR         APR         MAY       TOTAL
  
 Takoma_store           2.70       71.30       14.70       23.90       51.20      163.80
 Bethesda_store        12.70        8.90       17.80        7.90       18.30       65.60
 PG_store               2.30       32.30       43.40       23.40        1.20      102.60
 Bethesda_store        12.70        8.90       17.80        7.90       18.30       65.60
 Jersey_store           1.70       18.90        7.80       71.90       13.30      113.60
 NY_store               5.70       87.90        9.80       76.90       28.30      208.60
 SilverSpr_store        3.70       18.80        7.10        8.90       12.30       50.80
*/
