#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Date.h"

using namespace std;

int main()
{
  Date date1;
  Date date2 = {12, Month::April, 2024};
  cout << date2 << endl;
  cout << "date1: " << date1 << endl;
  date1.setDay(5);
  cout << "date1 day update: " << date1 << endl;
  date1.setMonth(Month::July);
  cout << "date1 month update: " << date1 << endl;
  date1.setYear(1998);
  cout << "year update: " << date1 << endl;
  cout << "get day: " << date1.getDay() << endl;
  Month thisMonth = date1.getMonth();
  cout << "get month: " << static_cast<int>(thisMonth) << endl;
  cout << "get year: " << date1.getYear() << endl;
  date1.listAllDates(1970);
  cout << "is a leap year: " << date1.isALeapYear(1970) << endl;
  cout << "\nshow calender:" << endl
       << "-----------------------------" << endl;
  date1.showCalender(2024);
  return 0;
}