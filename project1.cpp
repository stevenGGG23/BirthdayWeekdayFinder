#include <iostream> 
#include <fstream>
#include <cassert> 
using namespace std;

int main()
{
        int day; // a person's day of birth from user input.
        int month; // a person's month of birth from user input.
        int year; // a person's year of birth from user input.
        int modifiedYear, D, C, m, f; 
        string result; 

        ifstream myIn("birthday.dat");
        assert(myIn); 

        while (myIn >> month >> day >> year)
        {   

            // birthday validity
            if (month < 1 || month > 12 || day < 1 || day > 31) {
                cout << "Incorrect Data" << endl;
                continue;
            }

            bool validDate = true;
            if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
                validDate = false;
            }
            if (month == 2) {
                if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && day > 29) {
                    validDate = false;
                } else if (day > 28 && !((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
                    validDate = false;
                }
            }

            if (!validDate) {
                cout << "Incorrect Data" << endl;
                continue;
            }

            //calculate m and modifiedYear based on month
            if (month == 1) {
                m = 11;
                modifiedYear = year - 1;
            }
            else if (month == 2) {
                m = 12;
                modifiedYear = year - 1;
            }
            else if (month == 3) {
                m = 1;
                modifiedYear = year;
            }
            else if (month == 4) {
                m = 2;
                modifiedYear = year;
            }
            else if (month == 5) {
                m = 3;
                modifiedYear = year;
            }
            else if (month == 6) {
                m = 4;
                modifiedYear = year;
            }
            else if (month == 7) {
                m = 5;
                modifiedYear = year;
            }
            else if (month == 8) {
                m = 6;
                modifiedYear = year;
            }
            else if (month == 9) {
                m = 7;
                modifiedYear = year;
            }
            else if (month == 10) {
                m = 8;
                modifiedYear = year;
            }
            else if (month == 11) {
                m = 9;
                modifiedYear = year;
            }
            else if (month == 12) {
                m = 10;
                modifiedYear = year;
            }

            // Calculating D and C
            D = modifiedYear % 100;
            C = modifiedYear / 100;

            //  Zeller's Rule
            f = day + ((13 * m - 1) / 5) + D + (D / 4) + (C / 4) - 2 * C;

            // Calculating the day of the week from f modulo 7
            int weekday = f % 7;

            // If the remainder is negative and add 7 
            if (weekday < 0) {
                weekday += 7;
            }

            // Multi-way if statement 
            if (weekday == 0) {
                result = "Sunday";
            } else if (weekday == 1) {
                result = "Monday";
            } else if (weekday == 2) {
                result = "Tuesday";
            } else if (weekday == 3) {
                result = "Wednesday";
            } else if (weekday == 4) {
                result = "Thursday";
            } else if (weekday == 5) {
                result = "Friday";
            } else if (weekday == 6) {
                result = "Saturday";
            }

        
            cout << result << endl;

        } // end while

        myIn.close();

        return 0;
}
