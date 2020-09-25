#include <stdio.h>

typedef struct {
  int v;
  long long l, r;
} P;

int n, i, j, k;
long long c;
P a[100000], t[50000];

void f(int l, int r) {
  if (l + 1 >= r)
    return;

  int m = (l + r) / 2, s = m - l;
  f(l, m);
  f(m, r);

  for (i = 0; i != s; ++i)
    t[i] = a[l + i];
  i = l, j = 0, k = m;

  for (;;) {
    if (t[j].v <= a[k].v) {
      a[i] = t[j++];
      a[i++].r += k - m;
      if (j == s)
        break;
    } else {
      a[i] = a[k++];
      a[i++].l += s - j;
      if (k == r)
        break;
    }
  }
  for (; j != s; ++i, ++j) {
    a[i] = t[j];
    a[i].r += k - m;
  }
}

int main() {
  scanf("%d", &n);
  for (i = 0; i != n; ++i)
    scanf("%d", &a[i].v);

  f(0, n);

  for (i = 0; i != n; ++i)
    c += a[i].l * a[i].r;

  printf("%lld", c);

  return 0;
}
