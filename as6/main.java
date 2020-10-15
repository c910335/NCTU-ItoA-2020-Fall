// TLE
import java.util.Scanner;
import static java.lang.Math.max;

public class Main {
  public static int[][] st;

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n, m, i, j, k;
    int[] l = new int[4], r = new int[4], t;

    n = scanner.nextInt();
    m = scanner.nextInt();

    st = new int[2 * n][4];
    for (i = n; i != n << 1; ++i) {
      st[i][0] = st[i][1] = st[i][2] = 0;
      st[i][3] = scanner.nextInt();
    }
    for (i = n - 1; i != 0; --i)
      update(i);

    while (m-- > 0) {
      i = scanner.nextInt();
      j = scanner.nextInt();
      k = scanner.nextInt();
      j += n;
      if (i == 0) {
        st[j][3] = k;
        while ((j >>= 1) > 0)
          update(j);
      } else {
        k += n + 1;
        for (i = 0; i != 4; ++i) {
          l[i] = 0;
          r[i] = 0;
        }
        while (j < k) {
          if ((j & 1) == 1) {
            t = l.clone();
            merge(l, t, st[j]);
            j++;
          }
          if ((k & 1) == 1) {
            k--;
            t = r.clone();
            merge(r, st[k], t);
          }
          j >>= 1;
          k >>= 1;
        }
        t = l.clone();
        merge(l, t, r);
        System.out.println(l[3]);
      }
    }
  }

  public static void update(int x) {
    merge(st[x], st[x << 1], st[(x << 1) + 1]);
  }

  public static void merge(int[] p, int[] l, int[] r) {
    p[0] = max(l[1] + r[0], l[0] + r[2]);
    p[1] = max(l[1] + r[1], l[0] + r[3]);
    p[2] = max(l[2] + r[2], l[3] + r[0]);
    p[3] = max(l[3] + r[1], l[2] + r[3]);
  }
}
