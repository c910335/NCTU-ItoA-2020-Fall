#include <stdio.h>
#include <stdlib.h>

typedef struct E {
  int t;
  struct E *n;
} E;

int n, m, u, v, d[100000], l[100000], s[100000], st, z[100000], m1, m2, a;
E *g[100000], *t;

void tj(int c) {
  d[c] = l[c] = v++;
  s[st++] = c;
  z[c] = 1;
  for (E *t = g[c]; t; t = t->n) {
    if (!l[t->t])
      tj(t->t);
    if (z[t->t] && l[c] > l[t->t])
      l[c] = l[t->t];
  }
  if (d[c] == l[c]) {
    a = 1;
    while (s[--st] != c) {
      z[s[st]] = 0;
      a++;
    }
    z[c]= 0;
    if (m1 < a) {
      m2 = m1;
      m1 = a;
    } else if (m2 < a)
      m2 = a;
  }
}

int main() {
  scanf("%d%d", &n, &m);
  while (m--) {
    scanf("%d%d", &u, &v);
    t = malloc(sizeof(E));
    t->t = v;
    t->n = g[u];
    g[u] = t;
  }

  for (u = 0, v = 1; u != n; ++u)
    if (!d[u])
      tj(u);

  printf("%d", m2);

  return 0;
}
