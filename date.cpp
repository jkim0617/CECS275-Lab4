#include "Date.h"

//------------------ MONTH TYPE CONVERSION HELPER FUNCTIONS ------------------
std::string monthToStr(Month mm)
{
  switch (mm)
  {
  case Month::January:
    return "Jan";
  case Month::February:
    return "Feb";
  case Month::March:
    return "Mar";
  case Month::April:
    return "Apr";
  case Month::May:
    return "May";
  case Month::June:
    return "Jun";
  case Month::July:
    return "Jul";
  case Month::August:
    return "Aug";
  case Month::September:
    return "Sep";
  case Month::October:
    return "Oct";
  case Month::November:
    return "Nov";
  case Month::December:
    return "Dec";
  }
}
std::string monthToInt(Month mm)
{
  switch (mm)
  {
  case Month::January:
    return "01";
  case Month::February:
    return "02";
  case Month::March:
    return "03";
  case Month::April:
    return "04";
  case Month::May:
    return "05";
  case Month::June:
    return "06";
  case Month::July:
    return "07";
  case Month::August:
    return "08";
  case Month::September:
    return "09";
  case Month::October:
    return "10";
  case Month::November:
    return "11";
  case Month::December:
    return "12";
  }
}
Month intToStr(int mm)
{
  switch (mm)
  {
  case 1:
    return Month::January;
  case 2:
    return Month::February;
  case 3:
    return Month::March;
  case 4:
    return Month::April;
  case 5:
    return Month::May;
  case 6:
    return Month::June;
  case 7:
    return Month::July;
  case 8:
    return Month::August;
  case 9:
    return Month::September;
  case 10:
    return Month::October;
  case 11:
    return Month::November;
  case 12:
    return Month::December;
  }
}
//----------------------------------------------------------------------------
// getters
Month Date::getMonth() const { return month; }
int Date::getDay() const { return day; }
int Date::getYear() const { return year; }
// setters
Month Date::setMonth(Month m) { month = m; }
void Date::setDay(int d) { day = d; }
void Date::setYear(int y) { year = y; }
//----------------------------------------------------------------------------
// constructors & deconstructors

std::ostream &operator<<(std::ostream &os, const Date &dt)
{
  std::string date;
  std::string month = monthToStr(dt.getMonth());
  std::string days;
  std::string year = std::to_string(dt.year());

  if (dt.day() < 10)
  {
    days += "0";
  }
  days += std::to_string(dt.day());
  date = month + " " + days + ", " + year;

  os << date;
  return os;
}

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
//----------------------------------------------------------------------------
std::string Date::listAllDates(int y) // FIX ME: add function definition
{};

std::string showCalender(int y) // FIX ME: add function definition
{
  std::string final;
  return final;
};

// inner class InvalidDateException

bool Date::isALeapYear(int y) { return (y % 4 == 0); }

// toString member function that takes in format as parameter
std::string Date::toString(std::string format)
{
  std::string yearStr = std::to_string(year); // convert year into string
  std::string monthStr = monthToStr(month);   // convert month into string
  std::string dayStr = (day < 10) ? "0" : "";
  if (format == YYYYMMDD)
  {
    std::string dateFormat = yearStr + "-" + monthStr + "-";
    dayStr += std::to_string(day);
    dateFormat += dayStr;
    return dateFormat;
  }
  else if (format == DDMMYYYY)
  {
    dayStr += std::to_string(day);
    std::string dateFormat = dayStr + "-" + monthStr + "-" + yearStr;
    return dateFormat;
  }
  else if (format == MMDDYYYY)
  {
    std::string dateFormat = monthStr;
    dayStr += std::to_string(day);
    dateFormat = monthStr + "-" + dayStr + "-" + yearStr;
    return dateFormat;
  }
  else
  {
    std::cout << "Format is wrong\n";
    return "";
  }
}

// and display the date in the corresponding format "mm-dd-yyyy"