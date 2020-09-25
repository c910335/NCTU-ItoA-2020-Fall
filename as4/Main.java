import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n, i, a[], l = 0, m, r = 0, c, t;

    n = scanner.nextInt();
    a = new int[n];

    for (i = 0; i != n; ++i) {
      a[i] = scanner.next().length();
      if (l < a[i] - 1)
        l = a[i] - 1;
      r += a[i];
    }

    while (l + 1 < r) {
      m = (l + r) / 2;
      t = -1;
      c = 1;
      for (i = 0; i != n; ++i) {
        if (t + a[i] + 1 > m) {
          c++;
          t = a[i];
          if (c > 24)
            break;
        } else
          t += a[i] + 1;
      }
      if (c > 24)
        l = m;
      else
        r = m;
    }

    System.out.print(r);
  }
}
