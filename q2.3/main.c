#include <stdio.h>

const int d[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
int n, m, k, i, j, g[1002][1002], q[100000][4], qs, p[1002][1002][2], tx, ty, t, a[100000], as;

void f(int x, int y) {
  for (tx = x, ty = y; p[tx][ty][0] != tx || p[tx][ty][1] != ty; t = tx, tx = p[t][ty][0], ty = p[t][ty][1]);
  for (; p[x][y][0] != x || p[x][y][1] != y; t = x, x = p[t][y][0], y = p[t][y][1]) {
    p[x][y][0] = tx;
    p[x][y][1] = ty;
  }
}

int c(int a, int b, int x, int y) {
  f(x, y);
  x = tx;
  y = ty;
  f(a, b);
  return x == tx && y == ty;
}

void u(int a, int b, int x, int y) {
  f(x, y);
  x = tx;
  y = ty;
  f(a, b);
  p[x][y][0] = tx;
  p[x][y][1] = ty;
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j) {
      scanf("%d", &g[i][j]);
      p[i][j][0] = i;
      p[i][j][1] = j;
    }

  while (k--) {
    scanf("%d", &q[qs][0]);
    q[qs][0]++;
    if (q[qs][0]) {
      scanf("%d%d%d", &q[qs][1], &q[qs][2], &q[qs][3]);
      q[qs][1]++;
      q[qs][2]++;
      q[qs][3]++;
    }
    else {
      scanf("%d%d", &q[qs][2], &q[qs][3]);
      q[qs][2]++;
      q[qs][3]++;
      if (!g[q[qs][2]][q[qs][3]])
        continue;
      g[q[qs][2]][q[qs][3]] = 0;
    }
    qs++;
  }

  for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j)
      if (g[i][j])
        for (k = 0; k != 4; ++k)
          if (g[i + d[k][0]][j + d[k][1]])
            u(i, j, i + d[k][0], j + d[k][1]);

  for (i = qs - 1; i >= 0; --i) {
    if (q[i][0])
      a[as++] = g[q[i][0]][q[i][1]] && c(q[i][0], q[i][1], q[i][2], q[i][3]);
    else {
      g[q[i][2]][q[i][3]] = 1;
      for (k = 0; k != 4; ++k)
        if (g[q[i][2] + d[k][0]][q[i][3] + d[k][1]])
          u(q[i][2], q[i][3], q[i][2] + d[k][0], q[i][3] + d[k][1]);
    }
  }

  while (as--)
    printf("%d\n", a[as]);
  return 0;
}
