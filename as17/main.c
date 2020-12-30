#include <stdio.h>
#include <stdlib.h>
const int QS = 10001;
const int INF = 0x1FFFFFFF;

typedef struct E {
  int t, w;
  struct E *n;
} E;

int n, m, v[3], i, j, k, d[10000], q[10001], e[10000], ql, qr, c;
E *g[10000], *t;

int main() {
  scanf("%d%d%d%d%d", &n, &m, v, v + 1, v + 2);
  while (m--) {
    scanf("%d%d%d", &i, &j, &k);
    t = malloc(sizeof(E));
    t->t = j;
    t->w = k;
    t->n = g[i];
    g[i] = t;
  }

  j = k = 0;
  for (i = 0; i != 3; ++i) {
    for (c = 0; c != n; ++c) {
      d[c] = INF;
      e[c] = 1;
    }
    d[v[i]] = 0;
    ql = 0;
    qr = 1;
    q[0] = v[i];
    e[v[i]] = 0;
    while (ql != qr) {
      c = q[ql];
      ql = (ql + 1) % QS;
      for (t = g[c]; t; t = t->n)
        if (d[t->t] > d[c] + t->w) {
          d[t->t] = d[c] + t->w;
          if (e[t->t]) {
            q[qr] = t->t;
            e[t->t] = 0;
            qr = (qr + 1) % QS;
          }
        }
      e[c] = 1;
    }
    j += d[v[(i + 1) % 3]];
    k += d[v[(i + 2) % 3]];
  }

  if (j >= INF && k >= INF)
    puts("-1");
  else
    printf("%d", j < k ? j : k);

  return 0;
}
