#ifndef DATE_H
#define UTILS_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#define YYYYMMDD "yyyy-mm-dd"
#define DDMMYYYY "dd-mm-yyyy"
#define MMDDYYYY "mm-dd--yyyy"

enum class Month
{
  January = 1,
  February,
  March,
  April,
  May,
  June,
  July,
  August,
  September,
  October,
  November,
  December
};

class Date
{
private:
  Month month;
  int day;
  int year;

public:
  // Constructors
  Date(); // Default Constructor
  /*
    Constructor that initializes month, day and year
    @param m month
    @param d day
    @param y year
  */
  Date(int d, Month m, int y); // Overload Constructor
  // Destructor
  // ~Date();

  // getters
  int getDay() const;
  /*
    Return the day of the date
    @return day of the date
  */
  Month getMonth() const;
  /*
    Return the month of the date
    @return month of the date
  */
  int getYear() const;
  /*
    Return the year of the date
    @return year of the date
  */

  // setters
  void setDay(int d);
  /*
    Sets the day of the date
    @param m day to change to
  */
  Month setMonth(Month m);
  /*
    Sets the month of the date
    @param m month to change to
  */
  void setYear(int y);
  /*
    Sets the year of the date
    @param m year to change to
  */

  void listAllDates(int y);
  /*
    Function that takes year as a parameter and returns list of all dates for that year
    @param y selected year
    @return string list of all dates for that year
  */

  void showCalender(int y);
  /*
    Function that displays the calender format of selected year
    @param y selected year
    @return string calender format for that year
  */

  // inner class InvalidDateException to throw error if a date is not valid
  class InvalidDate
  {
  };

  bool isALeapYear(int y);
  /*
    Function that returns true if it is a leap year
    @param y selected year
    @return bool, true if leap year, false if not
  */

  std::string toString(std::string format);
  /*
    function toString returns formatted string based on desired format
    @param format desired function format
    @return string of the date modified to selected format
  */

  Date &operator++();
  // ++Date
  Date operator++(int);
  // Date++
  Date &operator--();
  Date operator--(int);

  friend std::ostream &operator<<(std::ostream &os, const Date &date);
  friend std::istream &operator>>(std::istream &is, Date &date);
};

Date operator+(const Date &date, int days);
Date operator-(const Date &date, int days);

#endif