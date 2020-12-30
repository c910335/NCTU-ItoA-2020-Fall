#include <stdio.h>
#include <stdlib.h>

typedef struct E {
  int t;
  struct E *n;
} E;

int z, n, m, i, u, v, d[20000], l[20000];
E *g[20000], *t, *f;

void add() {
  t = malloc(sizeof(E));
  t->t = v;
  t->n = g[u];
  g[u] = t;
}

void clear() {
  for (i = 0; i != n; ++i) {
    for (t = g[i]; t; t = f) {
      f = t->n;
      free(t);
    }
    d[i] = l[i] = 0;
    g[i] = 0;
  }
}

int tj(int c) {
  d[c] = l[c] = ++v;
  for (E *t = g[c]; t; t = t->n) {
    if (!l[t->t] && !tj(t->t))
      return 0;
    if (l[c] > l[t->t])
      l[c] = l[t->t];
  }
  if (d[c] == l[c])
    return c == 0 && v == n;
  return 1;
}

int main() {
  scanf("%d", &z);
  while (z--) {
    scanf("%d%d", &n, &m);
    while (m--) {
      scanf("%d%d", &u, &v);
      add();
    }
    v = 0;
    printf("%d\n", tj(0));
    clear();
  }
  return 0;
}
