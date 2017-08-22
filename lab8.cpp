#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
int Get_Year();
int Get_Starting_Day();
void Print_Heading(int);
string Read_Month_Name();
int Read_Num_Days();
int Print_Month(int, int, string);
ifstream myfile;
int main() {
     
    int year = Get_Year();
    int start_date = Get_Starting_Day();
    string month_name ;
    int num_day;
    int last_day;
    myfile.open("infile.txt");
    month_name = Read_Month_Name();
    num_day = Read_Num_Days();
    Print_Heading(year);
    //a loop in main that calls the read_month, read_num_days and the print_month functions 12 times.
    while (myfile) {
        last_day = Print_Month(num_day, start_date, month_name);
        //Print_Month(num_day, start_date, month_name);
        month_name = Read_Month_Name();
        num_day = Read_Num_Days();
        start_date = last_day;
    }
    return 0;
}
int Get_Year()
{
    int year;
    cout << "Enter the year: " ;
    cin >> year;
    return year;
}
 
int Get_Starting_Day() //gets starting day of the week
{
    int start_date;
    cout << "Enter the start date <0 - Sun, 1 = Mon, 2 = Tues 3 = Wed, 4 = Thurs, 5 = Fri, 6 = Sat>: ";
    cin >> start_date;
    if ((start_date < 0) || (start_date > 6)){
        cout << "Invalid Starting Day";
    }
    return start_date;
}
 
void Print_Heading(int year)
{
   // year = Get_Year();
    cout << "\t\t " << "YEAR -- " << year << endl;
}
//The read_month_data function should read the name of each month and the number of days from a file called "infile.txt"
string Read_Month_Name()
{
    string month_name;
    myfile >> month_name;
    return month_name;
}
int Read_Num_Days()
{
    int num_day;
    myfile >> num_day;
    return num_day;
}
int Print_Month(int num_day, int start_date, string month_name)
{
    //keep track of the day of the week (Sun. - Sat.) and perform an endl at the end of the week.
    int temp=start_date;
    int last_day;
    cout << endl << " \t\t" << month_name << endl;
    cout << "Sun: Mon: Tue: Wed: Thu: Fri: Sat: " << endl;
    while (start_date>0) {
        cout << setw(5) << " ";
        start_date --;
    }
    for (int counter = 1; counter <= num_day; counter ++) {
        cout << left << setw(5)<< counter;
        temp ++;
        if (temp > 6){
            cout << endl;
            temp = 0;
        }
    }
    last_day = temp; //the last_day parameter (from the previous month) to determine first day of the next month.
    cout << endl;
    return last_day;
}
/*
 Enter the year: 2009
 Enter the start date <0 - Sun, 1 = Mon, 2 = Tues 3 = Wed, 4 = Thurs, 5 = Fri, 6 = Sat>: 1
 YEAR -- 2009
  
 January
 Sun: Mon: Tue: Wed: Thu: Fri: Sat:
 1    2    3    4    5    6
 7    8    9    10   11   12   13
 14   15   16   17   18   19   20
 21   22   23   24   25   26   27
 28   29   30   31
  
 February
 Sun: Mon: Tue: Wed: Thu: Fri: Sat:
 1    2    3
 4    5    6    7    8    9    10
 11   12   13   14   15   16   17
 18   19   20   21   22   23   24
 25   26   27   28
  
 March
 Sun: Mon: Tue: Wed: Thu: Fri: Sat:
 1    2    3
 4    5    6    7    8    9    10
 11   12   13   14   15   16   17
 18   19   20   21   22   23   24
 25   26   27   28   29   30   31
  
  
 April
 Sun: Mon: Tue: Wed: Thu: Fri: Sat:
 1    2    3    4    5    6    7
 8    9    10   11   12   13   14
 15   16   17   18   19   20   21
 22   23   24   25   26   27   28
 29   30
  
 May
 Sun: Mon: Tue: Wed: Thu: Fri: Sat:
 1    2    3    4    5
 6    7    8    9    10   11   12
 13   14   15   16   17   18   19
 20   21   22   23   24   25   26
 27   28   29   30   31
  
 June
 Sun: Mon: Tue: Wed: Thu: Fri: Sat:
 1    2
 3    4    5    6    7    8    9
 10   11   12   13   14   15   16
 17   18   19   20   21   22   23
 24   25   26   27   28   29   30
  
  
 July
 Sun: Mon: Tue: Wed: Thu: Fri: Sat:
 1    2    3    4    5    6    7
 8    9    10   11   12   13   14
 15   16   17   18   19   20   21
 22   23   24   25   26   27   28
 29   30   31
  
 August
 Sun: Mon: Tue: Wed: Thu: Fri: Sat:
 1    2    3    4
 5    6    7    8    9    10   11
 12   13   14   15   16   17   18
 19   20   21   22   23   24   25
 26   27   28   29   30   31
  
 September
 Sun: Mon: Tue: Wed: Thu: Fri: Sat:
 1
 2    3    4    5    6    7    8
 9    10   11   12   13   14   15
 16   17   18   19   20   21   22
 23   24   25   26   27   28   29
 30
  
 October
 Sun: Mon: Tue: Wed: Thu: Fri: Sat:
 1    2    3    4    5    6
 7    8    9    10   11   12   13
 14   15   16   17   18   19   20
 21   22   23   24   25   26   27
 28   29   30   31
  
 November
 Sun: Mon: Tue: Wed: Thu: Fri: Sat:
 1    2    3
 4    5    6    7    8    9    10
 11   12   13   14   15   16   17
 18   19   20   21   22   23   24
 25   26   27   28   29   30
  
 December
 Sun: Mon: Tue: Wed: Thu: Fri: Sat:
 1
 2    3    4    5    6    7    8
 9    10   11   12   13   14   15
 16   17   18   19   20   21   22
 23   24   25   26   27   28   29
 30   31
 
*/
