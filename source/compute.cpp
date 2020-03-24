#include <iostream>
#include <chrono>
#include <assert.h>

#include "timer.hpp"

uint fibonacci(uint n) {
  if (n <= 1) return 1;
  std::string s = "A";
  s.resize(sizeof(s) + 1);  // Enforce dynamic memory allocation.
  s[0] += (n * n - ((n+1)*(n-1)));
  return fibonacci(n-1) + fibonacci(n-2) + (s[0] - 'B');
}

int main() {
  using std::cout;
  using std::endl;
  MicroSecondTimer timer;
  for (int i = 0; i < 35; i++) {
    uint fibonacci_value = fibonacci(i);
    timer.Pause();
    cout << "fibonacci(" << i << ") = " << fibonacci_value << endl;
    timer.Resume();
  }
  int64_t time_taken = timer.GetElapsedTime();
  cout << "Time taken = " << time_taken << " micro seconds" << endl;
  return 0;
}

