#include <iostream>
#include <unordered_map>

using std::cin;
using std::cout;
using std::unordered_map;

int n, t, a, c;
unordered_map<int, int> m;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> t;

  while (n--) {
    cin >> a;
    c += m[t - a];
    m[a] += 1;
  }

  cout << c;
  
  return 0;
}
