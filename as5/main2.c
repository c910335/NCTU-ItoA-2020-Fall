#include <stdio.h>
#include <stdlib.h>

typedef struct N {
  struct N *p, *l, *r;
  int k, v, s;
} N;

int n, k, a;
N *r, **c, *p, *t;

int rand() {
  static int x = 1114;
  return x = x * 0xdefaced + 1;
}

void add() {
  c = &r;
  p = 0;
  while (*c) {
    p = *c;
    (*c)->s++;
    if (a < (*c)->v) {
      c = &((*c)->l);
    } else {
      c = &((*c)->r);
    }
  }
  *c = malloc(sizeof(N));
  t = *c;
  t->p = p;
  t->k = rand();
  t->v = a;
  t->s = 1;
  while (p && t->k < p->k) {
    if (t == p->l) {
      p->l = t->r;
      if (p->l)
        p->l->p = p;
      t->r = p;
    } else {
      p->r = t->l;
      if (p->r)
        p->r->p = p;
      t->l = p;
    }
    t->p = p->p;
    p->p = t;
    if (t->p) {
      if (p == t->p->l)
        t->p->l = t;
      else
        t->p->r = t;
    } else
      r = t;

    t->s = p->s;
    p->s = 1;
    if (p->l)
      p->s += p->l->s;
    if (p->r)
      p->s += p->r->s;
    p = t->p;
  }
}

int find(int k) {
  t = r;
  for (;;) {
    if (t->l) {
      if (t->l->s >= k) {
        t = t->l;
        continue;
      }
      k -= t->l->s;
    }
    if (k <= 1)
      return t->v;
    k--;
    t = t->r;
  }
}

int main() {
  scanf("%d%d", &n, &k);
  k = 100 - k;

  while (n--) {
    scanf("%d", &a);
    if (a) {
      add();
    } else {
      printf("%d\n", find(r->s - r->s * k / 100));
    }
  }

  return 0;
}
