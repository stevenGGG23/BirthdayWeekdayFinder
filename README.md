# BirthdayWeekdayFinder 

This C++ program reads a person's birth date (month, day, year) from a data file named birthday.dat and calculates the day of the week they were born using Zeller's congruence formula. The program performs several key operations: first, it validates the birth date by checking the month, day, and leap year rules. If the date is invalid, it outputs an error message, "Incorrect Data." For valid dates, the program adjusts the month and year according to Zeller's formula, then calculates the day of the week by applying the formula. The program outputs the corresponding weekday (e.g., Sunday, Monday, etc.) for each valid birth date. This process repeats for all records in the input file, handling multiple birthdays until the file is exhausted. The code employs a simple error handling mechanism to ensure that invalid dates are caught and skipped, ensuring the program runs smoothly and accurately identifies the day of the week for each valid birth date provided in the data file. The use of assertions ensures that the input file is successfully opened, and the program terminates correctly once all data has been processed.
