/*********************************************************************
** Program name: Lab 10 - Algorithm Complexity of Fibonacci Sequences
** Author: Sariah Bunnell 
** Date:  June 1 2019
** Description: Runtime base class header file 
*********************************************************************/
#ifndef RUNTIME_HPP
#define RUNTIME_HPP
#include <iostream>
#include <chrono>
//using namespace std::chrono;
using std::cout;
using std::endl;

class Runtime
{
private:
  int N;
public:
  Runtime(int);
  int fibonacciRec(int);
  int fibonacciIter();
  void calcRuntime();
};

#endif
