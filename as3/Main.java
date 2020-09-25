import java.lang.Math;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int t, y;
    double l, m, r;

    t = scanner.nextInt();
    
    while (t-- > 0) {
      y = scanner.nextInt();
      l = 0;
      r = 20;
      while (r - l >= 1e-9) {
        m = (l + r) / 2;
        if (m * Math.exp(m) < y)
          l = m;
        else
          r = m;
      }
      System.out.println((l + r) / 2);
    }
  }
}
