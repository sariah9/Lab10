#include "Runtime.hpp"

Runtime::Runtime(int num)
{
  N = num;
}
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
