#include <iostream>

using std::cin;
using std::cout;

int n, a, f;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  n = 2 * n - 1;

  while (n--) {
    cin >> a;
    f ^= a;
  }

  cout << f;

  return 0;
}
