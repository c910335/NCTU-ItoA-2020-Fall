#include <cmath>
#include <iostream>

using std::cin;
using std::cout;

int t, y;
double l, m, r;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.precision(10);

  cin >> t;
  
  while (t--) {
    cin >> y;
    l = 0, r = 20;
    while (r - l >= 1e-9) {
      m = (l + r) / 2;
      if (m * exp(m) < y)
        l = m;
      else
        r = m;
    }
    cout << (l + r) / 2 << '\n';
  }

  return 0;
}
