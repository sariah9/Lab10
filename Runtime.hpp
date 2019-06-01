#ifndef RUNTIME_HPP
#define RUNTIME_HPP
#include <chrono>
using std::chrono;

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
