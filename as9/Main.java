// TLE
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n, m, i, j, k, s;
    int[] a, b;

    n = scanner.nextInt();
    m = scanner.nextInt();
    a = new int[n + 1];
    b = new int[n + 1];
    for (i = 1; i <= n; ++i) {
      a[i] = scanner.nextInt();
      b[i] += a[i];
      if ((j = i + (i & -i)) <= n)
        b[j] += b[i];
    }
    while (m-- > 0) {
      i = scanner.nextInt();
      j = scanner.nextInt();
      k = scanner.nextInt();
      if (i == 0) {
        k -= a[++j];
        a[j] += k;
        for (; j <= n; j += j & -j)
          b[j] += k;
      } else {
        s = 0;
        if (j > k)
          for (i = n; i > 0; i &= i - 1)
            s += b[i];
        for (; j > 0; j &= j - 1)
          s -= b[j];
        for (k++; k > 0; k &= k - 1)
          s += b[k];
        System.out.println(s);
      }
    }
  }
}
