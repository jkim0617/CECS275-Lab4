#include "Date.h"

// commented monthToStr and toString and cout overload and monthToInt

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

Date::Date()
{
  day = 1;
  month = Month::January;
  year = 2000;
}
Date::Date(int d, Month m, int y)
{
  this->day = d;
  this->month = m;
  this->year = y;
}
// getters
int Date::getDay() const { return day; }
Month Date::getMonth() const { return month; }
int Date::getYear() const { return year; }
// setters
void Date::setDay(int d) { day = d; }
Month Date::setMonth(Month m) { month = m; }
void Date::setYear(int y) { year = y; }

void Date::listAllDates(int y)
{
  std::ofstream dateList("ListofDates.txt");
  for (int i = 0; i < 12; i++)
  {
    int numDays;
    if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)
    {
      numDays = 31;
    }
    else if (i == 1)
    {
      numDays = (y % 4 == 0) ? 29 : 28;
    }
    else
    {
      numDays = 30;
    }
    for (int j = 1; j <= numDays; j++)
    {
      dateList << y << "-";
      dateList << ((i < 11) ? "0" : "");
      dateList << i + 1 << "-";
      dateList << ((j < 10) ? "0" : "");
      dateList << j << std::endl;
    }
  }
}

void Date::showCalender(int y)
{
  std::string months[13] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  for (int i = 1; i < 12; i++)
  {
    std::cout << std::setw(14) << months[i] << " " << y << std::endl;
    std::cout << "Sun Mon Tue Wed Thu Fri Sat" << std::endl;
    int numDays;
    if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
    {
      numDays = 31;
    }
    else if (i == 2)
    {
      numDays = (y % 4 == 0) ? 29 : 28;
    }
    else
    {
      numDays = 30;
    }
  }
}

bool Date::isALeapYear(int y) { return (y % 4) == 0; }

// toString member function that takes in format as parameter
std::string Date::toString(std::string format)
{
  std::string yearStr = std::to_string(year); // convert year into string
  std::string monthStr = monthToInt(month);   // convert month into string
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

std::ostream &operator<<(std::ostream &os, const Date &dt)
{
  std::string date;
  std::string month = monthToStr(dt.getMonth());
  std::string days;
  std::string year = std::to_string(dt.getYear());

  if (dt.getDay() < 10)
  {
    days += "0";
  }
  days += std::to_string(dt.getDay());
  date = month + " " + days + ", " + year;
  os << date << std::endl;
  return os;
}

std::istream &operator>>(std::istream &is, Date &date)
{
  /*
    cin >> myDate; prompts user for new date
  */
  std::cout << "Enter a day: ";
  is >> date.day;
  std::cout << "Enter a month (1-12): ";
  int mm;
  is >> mm;
  date.setMonth(intToStr(mm));
  std::cout << "Enter a year: ";
  is >> date.year;
  // if (isValidDate(date))
  //   return is;
  // else
  //   throw Date::InvalidDate("Date invalid");
  return is;
}

Date &Date::operator++()
{
  Date temp(*this);
  int tempDay = temp.day + 1;
  int tempMonth = stoi(monthToInt(temp.month));
  int tempYear = temp.year;
  if (month == Month::April || month == Month::June || month == Month::September || month == Month::November)
  {
    if (tempDay > 30)
    {
      tempMonth++;
      tempDay = 1;
    }
  }
  // feb exception
  else if (month == Month::February)
  {
    if (isALeapYear(tempYear))
    {
      if (tempDay > 29)
      {
        tempMonth++;
        tempDay = 1;
      }
    }
    else
    {
      if (tempDay > 28)
      {
        tempMonth++;
        tempDay = 1;
      }
    }
  }
  // dec exception
  else if (month == Month::December)
  {
    if (tempDay > 31)
    {
      tempMonth = 1;
      tempDay = 1;
      tempYear++;
    }
  }
  else
  {
    if (tempDay > 31)
    {
      tempMonth++;
      tempDay = 1;
    }
  }
  day = tempDay;
  month = intToStr(tempMonth);
  year = tempYear;
  return *this;
}

Date Date::operator++(int)
{
  Date temp(*this);
  operator++();
  return temp;
}

Date &Date::operator--()
{
  Date temp(*this);
  int tempDay = temp.day - 1;
  int tempMonth = stoi(monthToInt(temp.month));
  int tempYear = temp.year;

  if (tempDay < 1)
  {
    if (temp.month == Month::April || temp.month == Month::June || temp.month == Month::September || temp.month == Month::November || temp.month == Month::February || temp.month == Month::August)
    {
      tempMonth--;
      tempDay = 31;
    }
    else if (temp.month == Month::March)
    {
      tempMonth--;
      day = isALeapYear(tempYear) ? 29 : 28;
    }
    else
    {
      tempMonth--;
      day = 30;
    }
  }
  day = tempDay;
  month = intToStr(tempMonth);
  year = tempYear;
  return *this;
}

Date Date::operator--(int)
{
  Date temp(*this);
  operator--();
  return temp;
}

// Overload addition operator (+). (E.g. Date(12, 1, 2001) + 1 --> Date(12, 2, 2001))
Date operator+(const Date &date, int days)
{
  Date temp = date;

  for (int i = 0; i < days; i++)
  {
    ++temp;
  }
  return temp;
}
// Overload addition operator (-). (E.g. Date(12, 1, 2001) - 1 --> Date(11, 30, 2001))
Date operator-(const Date &date, int days)
{
  Date temp = date;

  for (int i = 0; i < days; i++)
  {
    --temp;
  }
  return temp;
}