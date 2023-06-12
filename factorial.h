#ifndef __FACTORIAL_H__
#define __FACTORIAL_H__

int Factorial(int n) {
  if (n <= 0) return 0;
  int ans = 1;
  while (n > 0) {
    ans *= n;
    n--;
  }
  return ans;
}

#endif // __FACTORIAL_H__