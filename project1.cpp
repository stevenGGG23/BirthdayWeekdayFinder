/* A.I. Disclaimer: All work for this assignment was completed by myself and entirely without the use  
of artificial intelligence tools such as ChatGPT, MS Copilot, other LLMs, etc. 

/*
Assignment: CSCI 2170 Project 1
Class: CSCI 2170-D01
Name: Steven Gobran
Course Instructor: Dr. Li
Due Date: 2/16/2025
Description: This program determines the day of the week a person is born, using Zeller's formula. 
The program reads person's birth date (month, day, year) from a datafile and outputs the day of the week a person is
born. If birth date is invalid, the output is an error message.
*/

#include <iostream>  // for cin, cout, endl, etc
#include <fstream> // for ifstream
#include <cassert>  // for assert
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

        // This loop will read one birthday at a time till the end
        // of the data file is reached
        // For each birthday read:
        // (1) check whether the birthday is valid
        //     if it is not valid, display the message
        // (2) if it is valid compute and display the day of the week
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