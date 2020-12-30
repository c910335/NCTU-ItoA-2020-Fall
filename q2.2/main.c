#include <stdio.h>
#include <stdlib.h>

int n, m, i, a[500000], l, r, cc, cv, ac, av;

int cmp(const void *a, const void *b) {
  return *(int*)a - *(int*)b;
}

int main() {
  scanf("%d%d", &n, &m);
  for (; i != n; ++i)
    scanf("%d", a + i);
  while (m--) {
    scanf("%d%d", &l, &r);
    qsort(a + l, r - l, sizeof(int), cmp);
    cc = ac = 1;
    cv = av = a[l];
    for (i = l + 1; i != r; ++i) {
      if (a[i] == cv)
        cc++;
      else {
        if (cc > ac) {
          ac = cc;
          av = cv;
        }
        cc = 1;
        cv = a[i];
      }
    }
    if (cc > ac) {
      ac = cc;
      av = cv;
    }
    printf("%d\n", av);
  }
  return 0;
}
