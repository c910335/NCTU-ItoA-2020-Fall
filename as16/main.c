#include <stdio.h>
#define S 40000

struct {
  int x, y;
} q[S], w[S];

struct {
  int x, y, d;
} e[S];

int n, m, t, i, j, g[102][102], es, ql, qr, ws, a, cr, d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main() {
  scanf("%d%d%d", &n, &m, &t);
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j) {
      scanf("%d", &g[i][j]);
      if (g[i][j] >= 4) {
        e[es].x = i;
        e[es].y = j;
        e[es].d = g[i][j] - 4;
        es++;
        g[i][j] = 1;
      } else if (g[i][j] == 2) {
        q[qr].x = i;
        q[qr].y = j;
        qr = (qr + 1) % S;
      } else if (g[i][j] == 3) {
        w[ws].x = i;
        w[ws].y = j;
        ws++;
        g[i][j] = 1;
      }
    }

  if (!ws) {
    puts("-1");
    return 0;
  }

  for (a = 1; a <= t; ++a) {
    cr = qr;
    if (ql == qr)
      break;
    for (; ql != cr; ql = (ql + 1) % S) {
      if (g[q[ql].x][q[ql].y] != a + 1)
        continue;
      for (i = 0; i != 4; ++i)
        if (g[q[ql].x + d[i][0]][q[ql].y + d[i][1]] == 1) {
          g[q[ql].x + d[i][0]][q[ql].y + d[i][1]] = a + 2;
          q[qr].x = q[ql].x + d[i][0];
          q[qr].y = q[ql].y + d[i][1];
          qr = (qr + 1) % S;
        }
    }
    for (i = 0; i != es; ++i) {
      g[e[i].x][e[i].y] = 1;
      for (j = 0; j != 4; ++j)
        if (g[e[i].x + d[j][0]][e[i].y + d[j][1]] >= 2) {
          g[e[i].x + d[j][0]][e[i].y + d[j][1]] = a + 2;
          q[qr].x = e[i].x + d[j][0];
          q[qr].y = e[i].y + d[j][1];
          qr = (qr + 1) % S;
        }
      if (g[e[i].x + d[e[i].d][0]][e[i].y + d[e[i].d][1]]) {
        e[i].x += d[e[i].d][0];
        e[i].y += d[e[i].d][1];
        g[e[i].x][e[i].y] = 1;
      } else
        e[i].d = (e[i].d + 1) % 4;
    }
    for (i = 0; i != ws; ++i)
      if (g[w[i].x][w[i].y] >= 2) {
        printf("%d", a);
        return 0;
      }
  }
  puts("-1");
  return 0;
}
