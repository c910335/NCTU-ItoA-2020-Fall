import java.util.Scanner;

public class Main {
  public static P[] a;

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n;
    long c = 0;

    n = scanner.nextInt();
    a = new P[n];
    for (int i = 0; i != n; ++i)
      a[i] = new P(scanner.nextInt());

    f(0, n);

    for (int i = 0; i != n; ++i)
      c += a[i].l * a[i].r;

    System.out.print(c);
  }

  public static void f(int l, int r) {
    if (l + 1 >= r)
      return;

    int m = (l + r) / 2, s = m - l;
    f(l, m);
    f(m, r);

    P[] t = new P[s];
    for (int i = 0; i != s; ++i)
      t[i] = a[l + i];
    int i = l, j = 0, k = m;

    for (;;) {
      if (t[j].v <= a[k].v) {
        a[i] = t[j++];
        a[i++].r += k - m;
        if (j == s)
          break;
      } else {
        a[i] = a[k++];
        a[i++].l += s - j;
        if (k == r)
          break;
      }
    }
    for (; j != s; ++i, ++j) {
      a[i] = t[j];
      a[i].r += k - m;
    }
  }

  public static class P {
    int v;
    long l, r;

    public P(int v) {
      this.v = v;
      l = r = 0;
    }
  }
}
