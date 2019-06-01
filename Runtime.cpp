/*********************************************************************
** Program name: Lab 10 - Algorithm Complexity of Fibonacci Sequences
** Author: Sariah Bunnell 
** Date:  June 1 2019
** Description: Runtime base class implementation file 
*********************************************************************/
#include "Runtime.hpp"
/*********************************************************************
** Function: Runtime constructor
** Description: initializes N to argument value
** Parameters: int num
** Returns: None
*********************************************************************/
Runtime::Runtime(int num)
{
  N = num;
}
/*********************************************************************
** Function: fibonacciRec
** Description: calculated Fibonacci sequence for given n by use of
** recursion
** Parameters: int n
** Returns: int Fibonacci number
*********************************************************************/
int Runtime::fibonacciRec(int n)
{
  if(n == 0)
  {
    return 0;
  }
  else if(n == 1)
  {
    return 1;
  }
  return Fibonacci(n - 1) + Fibonacci(n - 2);
}
/*********************************************************************
** Function: fibonacciIter
** Description: calculated Fibonacci sequence for N by use of 
** iteration
** Parameters: None
** Returns: int Fibonacci number
*********************************************************************/
int Runtime::fibonacciIter()
{
  int first = 0;
  int second = 1;
  int counter = 2;
  while(counter < N)
  {
    int temp=second;
    second=first+second;
    first=temp;
    ++counter;
  }
  if(N == 0)
  {
    return 0;
  }
  else
  {
    return first + second;
  }
}
/*********************************************************************
** Function: calcRuntime
** Description: determines whether high accuracy clock is not 
** synonomous with wall clock, then performs algorithm run time 
** analysis by counting microseconds between function performance
** Parameters: None
** Returns: None
*********************************************************************/
void Runtime::calcRuntime()
{
  if (high_resolution_clock::is_steady)
  {
    auto startRec = high_resolution_clock::now();
    fibonacciRec(N);
    auto stopRec = high_resolution_clock::now();
    auto durationR = durationR_cast<microseconds>(stopRec - startRec);
    auto startIter = high_resolution_clock::now();
    fibonacciIter();
    auto stopIter = high_resolution_clock::now();
    auto durationI = durationI_cast<microseconds>(stopIter - startIter);
  }
  else
  {
    auto startRec = steady_clock::now();
    fibonacciRec(N);
    auto stopRec = steady_clock::now();
    auto durationR = durationR_cast<microseconds>(stopRec - startRec);
    auto startIter = steady_clock::now();
    fibonacciIter();
    auto stopIter = steady_clock::now();
    auto durationI = durationI_cast<microseconds>(stopIter - startIter);
  } 
  cout << "Fibonacci by recursion: " << endl;
  cout << durationR.count() << " microseconds." << endl;
  cout << "Fibonacci by iteration: " << endl;
  cout << durationI.count() << " microseconds." << endl;
}
