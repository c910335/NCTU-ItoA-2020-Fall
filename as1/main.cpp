#include <iostream>
#include <complex>

using std::cin;
using std::cout;
using std::complex;

const long long MOD = 1e9 + 7;
int t, a, b, n;
complex<long long> c;

void m(complex<long long> &x) {
  x.real((x.real() % MOD + MOD) % MOD);
  x.imag((x.imag() % MOD + MOD) % MOD);
}

complex<long long> p(complex<long long> x, int n) {
  m(x);
  if (n == 1)
    return x;
  complex<long long> t = p(x * x, n / 2);
  if (n & 1)
    t *= x;
  m(t);
  return t;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);

  cin >> t;

  while (t--) {
    cin >> a >> b >> n;
    if (n) {
      c = p({a, b}, n);
      cout << c.real() << ' ' << c.imag() << '\n';
    } else
      cout << "1 0\n";
  }

  return 0;
}
