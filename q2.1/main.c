#include <stdio.h>

int n, a, b, c;

int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &b);
    if (b) {
      c++;
    } else if (c) {
      a += (c >> 1) + (c & 1);
      c = 0;
    }
  }
  a += (c >> 1) + (c & 1);
  printf("%d", a);
  return 0;
}
