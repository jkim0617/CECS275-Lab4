#include "Date.h"

Date::Date()
{
  month = Month::January;
  day = 0;
  year = 0;
}

Date::Date(Month m, int d, int y)
{
  this->month = m;
  this->day = d;
  this->year = y;
}
Date::~Date() {}
// getters
Month Date::getMonth() const { return month; }
int Date::getDay() const { return day; }
int Date::getYear() const { return year; }
// setters
Month Date::setMonth(Month m) { month = m; }
void Date::setDay(int d) { day = d; }
void Date::setYear(int y) { year = y; }

std::string Date::listAllDates(int y) // FIX ME: change return time to a list of dates
{};
std::string showCalender(int y)
{
  std::string final;
  return final;
};

// inner class InvalidDateException

bool Date::isALeapYear(int y) { return (y % 4 == 0); }

// toString member function that takes in format as parameter
// and display the date in the corresponding format "mm-dd-yyyy"