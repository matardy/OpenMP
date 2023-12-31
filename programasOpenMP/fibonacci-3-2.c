// Listado 3.2 - Fibonacci

#include <stdio.h>
#include <omp.h>

long fib (int n) { return (n < 2 ? 1 : fib (n - 1) + fib (n - 2)); }

int main (int argc, char *argv[]) {
  int n = 40;
  #pragma omp parallel
  {
    int t = omp_get_thread_num ();
    printf ("%d: %ld\n", t, fib (n + t));
  }
  return 0;
}
