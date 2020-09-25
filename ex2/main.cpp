#include <iostream>

using std::cin;
using std::cout;

int t, n, k, a;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  
  cin >> t;

  while (t--) {
    cin >> n >> k;
    a = 0;
    while (n >= k) {
      a += n / k;
      n = n / k + n % k;
    }
    cout << a << '\n';
  }

  return 0;
}
