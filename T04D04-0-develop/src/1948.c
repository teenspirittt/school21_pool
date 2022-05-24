#include <stdio.h>

int main() {
  float  n;
  scanf("%f", &n);
    if ((n == 0) || (n == 1)) {
      printf("n/a");
	  return 1;
  }
  if (n < 0) {
	  n = n * (-1);
  }
    int a[100];
    int max;
    for (int i = 0; i <(int)n + 1; i++)
  	a[i] = i;
    for (int p = 2; p < (int)n + 1; p++)
        if (a[p] != 0) {
            for (int j = p*p; j <(int)n + 1; j += p)
        }
        	a[j] = 0;
  for (int i = 0; i < (int)n; i++) {
      if (a[i] == 0) continue;
      if ((n / a[i]) == (int)(n / a[i]))
		max = a[i];
  }
  printf("%d", max);
  return 0;
}
