#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Date.h"

int main()
{
  Date date;
  std::cout << date;
  std::cin >> date;
  std::cout << date;
  date++;
  std::cout << date;
  std::cout << date.toString("yyyy-mm-dd") << std::endl;
  date.listAllDates(2000);
  return 0;
}

/*
  TODO:
  - invalid date exception
  - calender format using equation
  - comments
  - write full main function to implement functions
*/