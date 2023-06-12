#ifndef __FIB_H__
#define __FIB_H__

#include <vector>

std::vector<int> fibs = {0, 1, 1};

int Fib(int n) { // Fib(n) == Fib(n-1) + Fib(n-2) && Fib(1) == 1 && Fib(2) == 1
  if (n <= 0) return 0;
  int i = fibs.size();
  if (n < i) return fibs[n];
  while (i <= n) {
    fibs.push_back(fibs[i-1] + fibs[i-2]);
    i++;
  }
  return fibs[n];
}

#endif // __FIB_H__