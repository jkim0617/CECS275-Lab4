#ifndef DATE_H
#define UTILS_H

#include <iostream>
#include <vector>
#include <string>

class Date
{
private:
  int month;
  int day;
  int year;

public:
  // Default Constructor
  Date();
  // Overload Constructor
  Date(int m, int d, int y);

  // Destructor
  ~Date();

  // getters
  int getMonth() const;
  int getDay() const;
  int getYear() const;
  // setters
  void setMonth(int m);
  void setDay(int d);
  void setYear(int y);

  void listAllDates(int y); // FIX ME: change return time to a list of dates
  std::string showCalender(int y);

  // inner class InvalidDateException
  // class InvalidDateException : public std::exception
  // {
  // public:
  //   const char *what() const noexcept override
  //   {
  //     return "Invalid Date";
  //   }
  // };

  class InvalidDateException;

  bool isALeapYear(int y);

  // enum class for month
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
  // toString member function that takes in format as parameter
  //  and display the date in the corresponding format "mm-dd-yyyy"
};

#endif

/*
  - (done) Date class has three private members
  - (done) two constructors:
    - default
    - overload w/ 3 param
  - (done) getter functions
  - (done) setter functions
  - listAllDates()
  - showCalender()
  - inner class InvalidDateException
  - isALeapYear()
  - enum class for Month
  - toString()
  - overload "<<"
  - overload ">>"
  - overload "++"
  - overload "--"
  - overload "+"
  - overload "-"
*/