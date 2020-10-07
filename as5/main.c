#include <stdio.h>

int n, k, a, b, t, s, ls, rs, l[500000], r[500000];

void lup() {
  a = ls;
  while (a && l[(a - 1) >> 1] < l[a]) {
    t = l[(a - 1) >> 1];
    l[(a - 1) >> 1] = l[a];
    l[a] = t;
    a = (a - 1) >> 1;
  }
  ls++;
}

void rup() {
  a = rs;
  while (a && r[(a - 1) >> 1] > r[a]) {
    t = r[(a - 1) >> 1];
    r[(a - 1) >> 1] = r[a];
    r[a] = t;
    a = (a - 1) >> 1;
  }
  rs++;
}

int main() {
  scanf("%d%d", &n, &k);
  k = 100 - k;

  while (n--) {
    scanf("%d", &a);
    if (a) {
      s += 1;
      if (!ls || a <= l[0]) {
        l[ls] = a;
        lup();
        if (rs < s * k / 100) {
          r[rs] = l[0];
          rup();
          ls--;
          l[0] = l[ls];
          a = 0;
          while ((b = (a << 1) + 1) < ls) {
            if (b + 1 < ls && l[b] < l[b + 1])
              b++;
            if (l[a] < l[b]) {
              t = l[a];
              l[a] = l[b];
              l[b] = t;
              a = b;
            } else
              break;
          }
        }
      } else {
        r[rs] = a;
        rup();
        if (rs > s * k / 100) {
          l[ls] = r[0];
          lup();
          rs--;
          r[0] = r[rs];
          a = 0;
          while ((b = (a << 1) + 1) < rs) {
            if (b + 1 < rs && r[b] > r[b + 1])
              b++;
            if (r[a] > r[b]) {
              t = r[a];
              r[a] = r[b];
              r[b] = t;
              a = b;
            } else
              break;
          }
        }
      }
    } else if (ls)
      printf("%d\n", l[0]);
    else
      printf("%d\n", r[0]);
  }

  return 0;
}
