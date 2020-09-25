#include <math.h>
#include <stdio.h>

int t, y;
double l, m, r;

int main() {
  scanf("%d", &t);
  
  while (t--) {
    scanf("%d", &y);
    l = 0, r = 20;
    while (r - l >= 1e-9) {
      m = (l + r) / 2;
      if (m * exp(m) < y)
        l = m;
      else
        r = m;
    }
    printf("%.9lf\n", (l + r) / 2);
  }

  return 0;
}
