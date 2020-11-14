#include <algorithm>
#include <climits>
#include <iostream>

using std::cin;
using std::cout;
using std::max;

int n, m, i, j, st[2000000], a;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (i = n; i != n << 1; ++i)
    cin >> st[i];
  for (i = n - 1; i != 0; --i)
    st[i] = max(st[i << 1], st[(i << 1) + 1]);
  while (m--) {
    cin >> i >> j;
    a = INT_MIN;
    for (i += n, j += n + 1; i < j; i >>= 1, j >>= 1) {
      if (i & 1) {
        if (a < st[i])
          a = st[i];
        i++;
      }
      if (j & 1) {
        j--;
        if (a < st[j])
          a = st[j];
      }
    }
    cout << a << '\n';
  }
  return 0;
}
