#include <stdio.h>
#include <string.h>

int n, i, a[100000], l, m, r, c, t;
char s[100001];

int main() {
  scanf("%d", &n);

  for (i = 0; i != n; ++i) {
    scanf("%s", s);
    a[i] = strlen(s);
    if (l < a[i] - 1)
      l = a[i] - 1;
    r += a[i];
  }

  while (l + 1 < r) {
    m = (l + r) / 2;
    t = -1;
    c = 1;
    for (i = 0; i != n; ++i) {
      if (t + a[i] + 1 > m) {
        c++;
        t = a[i];
        if (c > 24)
          break;
      } else
        t += a[i] + 1;
    }
    if (c > 24)
      l = m;
    else
      r = m;
  }

  printf("%d", r);

  return 0;
}
