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
  fibonacciRec();
  fibonacciIter();
  calcRuntime();
};

#endif
