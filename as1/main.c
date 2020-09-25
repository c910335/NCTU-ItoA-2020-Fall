#include <stdio.h>

typedef struct {
  long long r, i;
} C;

const long long MOD = 1e9 + 7;
int t, n;
C c;

void m(C *c) {
  c->r = (c->r % MOD + MOD) % MOD;
  c->i = (c->i % MOD + MOD) % MOD;
}

C x(C a, C b) {
  C t;
  t.r = a.r * b.r - a.i * b.i;
  t.i = a.r * b.i + a.i * b.r;
  return t;
}

C p(C c, int n) {
  m(&c);
  if (n == 1)
    return c;
  C t = p(x(c, c), n / 2);
  if (n & 1)
    t = x(t, c);
  m(&t);
  return t;
}

int main() {
  scanf("%d", &t);

  while (t--) {
    scanf("%lld%lld%d", &c.r, &c.i, &n);
    if (n) {
      c = p(c, n);
      printf("%lld %lld\n", c.r, c.i);
    } else
      puts("1 0");
  }
  return 0;
}
