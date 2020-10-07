#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
using std::greater;
using std::priority_queue;
using std::vector;

int n, k, a, s;
priority_queue<int> l;
priority_queue<int, vector<int>, greater<int> > r;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  k = 100 - k;

  while (n--) {
    cin >> a;
    if (a) {
      s++;
      if (l.empty() || a <= l.top()) {
        l.push(a);
        if (r.size() < s * k / 100) {
          r.push(l.top());
          l.pop();
        }
      } else {
        r.push(a);
        if (r.size() > s * k / 100) {
          l.push(r.top());
          r.pop();
        }
      }
    } else if (l.empty())
      cout << r.top() << '\n';
    else
      cout << l.top() << '\n';
  }

  return 0;
}
