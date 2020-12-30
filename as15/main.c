#include <stdio.h>
#include <string.h>

int n, m, q, i, v, w, j, g[5000][5000], o[500000][2], os, p[5000], s[5000], a[500000], t;

int f(int x) {
  for (t = x; t != p[t]; t = p[t]);
  for (; x != p[x]; x = p[x])
    p[x] = t;
  return t;
}

void u(int x, int y) {
  x = f(x);
  y = f(y);
  if (x != y) {
    if (s[x] < s[y]) {
      p[x] = y;
      s[y] += s[x];
    } else {
      p[y] = x;
      s[x] += s[y];
    }
  }
}

int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (; i != m; ++i) {
    scanf("%d%d", &v, &w);
    g[v][w]++;
    g[w][v]++;
  }
  for (i = os = 0; i != q; ++i, ++os) {
    scanf("%d%d", &o[os][0], &o[os][1]);
    if (o[os][0] > -1) {
      if (g[o[os][0]][o[os][1]]) {
        g[o[os][0]][o[os][1]]--;
        g[o[os][1]][o[os][0]]--;
      } else
        os--;
    }
  }
  s[0] = 1;
  for (i = 1; i != n; ++i) {
    p[i] = i;
    s[i] = 1;
    for (j = 0; j < i; ++j)
      if (g[i][j])
        u(i, j);
  }
  for (i = os - 1, j = 0; i >= 0; --i) {
    if (o[i][0] > -1) {
      u(o[i][0], o[i][1]);
    } else
      a[j++] = s[f(o[i][1])];
  }
  for (--j; j >= 0; --j)
    printf("%d\n", a[j]);
  return 0;
}
