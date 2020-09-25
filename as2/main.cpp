#include <iostream>

using std::cin;
using std::cout;

struct P {
  int v;
  long long l, r;
};

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
  cin.sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (i = 0; i != n; ++i)
    cin >> a[i].v;

  f(0, n);

  for (i = 0; i != n; ++i)
    c += a[i].l * a[i].r;

  cout << c;

  return 0;
}
