#include <iostream>

using std::cin;
using std::cout;

int n, m, i, j, k, a[500001], b[500001], s;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (i = 1; i <= n; ++i) {
    cin >> a[i];
    b[i] += a[i];
    if ((j = i + (i & -i)) <= n)
      b[j] += b[i];
  }

  while (m--) {
    cin >> i >> j >> k;
    if (i) {
      s = 0;
      if (j > k)
        for (i = n; i > 0; i &= i - 1)
          s += b[i];
      for (; j > 0; j &= j - 1)
        s -= b[j];
      for (k++; k > 0; k &= k - 1)
        s += b[k];
      cout << s << '\n';
    } else {
      k -= a[++j];
      a[j] += k;
      for (; j <= n; j += j & -j)
        b[j] += k;
    }
  }

  return 0;
}
