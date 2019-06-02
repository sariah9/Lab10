/*********************************************************************
** Program name: Lab 10 - Algorithm Complexity of Fibonacci Sequences
** Author: Sariah Bunnell 
** Date:  June 1 2019
** Description: main function - program beginning and end 
*********************************************************************/
#include "Runtime.hpp"
#include <climits>
#include <sstream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

/*********************************************************************
** Function: inputValidation
** Description: validates user input 
** Parameters: int minimum int maximum
** Returns: validated integer
*********************************************************************/
int inputValidation(int min, int max)
{
  double input;
  bool repeatEntry = true;
  char errorTest;
  std::string inputLine;
  while (repeatEntry) {
      getline(cin, inputLine);
      std::stringstream lineStream(inputLine);
      if (!(lineStream >> input)) {
          cout << "Input was not a number. Please try again." << endl;
      } else if ((input < min) || (input > max)) {
          cout << "Input out of range. Please try again." << endl;
      } else if (input - static_cast<int>(input) != 0) {
          cout << "Input with decimals and not an integer. Please try again." << endl;
      } else if (lineStream >> errorTest) {
          cout << "Input with extra symbols and/or characters. Please try again." << endl;
      } else {
          repeatEntry = false;
      }
  }
  return input;  
}
/*********************************************************************
** Function: main
** Description: asks for user-given value and runs that number 
** through Runtime methods
** Parameters: None
** Returns: int 0 when finished
*********************************************************************/
int main()
{
  int value;
  cout << "What number would you like to measure? " << endl;
  value = inputValidation(INT_MIN, INT_MAX);
  Runtime complexity(value);
  complexity.calcRuntime();
  return 0;
}
