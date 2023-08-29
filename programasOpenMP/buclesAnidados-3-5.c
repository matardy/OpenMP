// listado 3.5 del libro - bucles anidados
// set OMP_NESTED=true para habilitar anidamiento de bucles

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main (int argc , char *argv []) {
  if (argc!=2) { printf ("USO: %s <max-hilos>\n", argv[0]); exit (1);}
  int max = atoi(argv[1]);
  #pragma omp parallel for schedule(runtime)
  for (int i = 1; i <= max; i++)
    #pragma omp parallel for schedule(runtime)
    for (int j = 1; j <= max; j++)
      printf ("%d: (%d,%d)\n", omp_get_thread_num (), i, j);
  return 0;
}

