#include <stdio.h>

const int INF = 0x3FFFFFFF;
int n, g[500][500], i, j, k;

int main() {
  scanf("%d", &n);
  for (; i != n; ++i)
    for (j = 0; j != n; ++j) {
      scanf("%d", &g[i][j]);
      if (!g[i][j] && i != j)
        g[i][j] = INF;
    }
  for (i = 0; i != n; ++i)
    for (j = 0; j != n; ++j)
      for (k = 0; k != n; ++k)
        if (g[j][k] > g[j][i] + g[i][k])
          g[j][k] = g[j][i] + g[i][k];
  for (i = 0; i != n; ++i) {
    for (j = 0; j != n; ++j)
      printf("%d ", g[i][j] < INF ? g[i][j] : -1);
    puts("");
  }
}
