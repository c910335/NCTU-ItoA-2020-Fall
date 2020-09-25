import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int t, n;
    long r, i;

    t = scanner.nextInt();

    while (t-- > 0) {
      r = scanner.nextLong();
      i = scanner.nextLong();
      n = scanner.nextInt();

      if (n == 0)
        System.out.println("1 0");
      else {
        C c = p(new C(r, i), n);
        System.out.println(c.r + " " + c.i);
      }
    }
  }

  public static C p(C c, int n) {
    if (n == 1)
      return c;
    C t = p(c.x(c), n / 2);
    if ((n & 1) == 1)
      t = t.x(c);
    return t;
  }

  public static class C {
    final static long MOD = (long) 1e9 + 7;
    long r, i;

    public C(long r, long i) {
      this.r = (r % MOD + MOD) % MOD;
      this.i = (i % MOD + MOD) % MOD;
    }

    public C x(C o) {
      long r = ((this.r * o.r - this.i * o.i) % MOD) % MOD;
      long i = ((this.r * o.i + this.i * o.r) % MOD) % MOD;
      return new C(r, i);
    }
  }
}
