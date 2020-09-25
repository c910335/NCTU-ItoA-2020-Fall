#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int n, i, a[100000], l, m, r, c, t;
string s;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (i = 0; i != n; ++i) {
    cin >> s;
    a[i] = s.size();
    r += a[i];
    if (l < a[i] - 1)
      l = a[i] - 1;
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

  cout << r;

  return 0;
}
