import java.util.Scanner;
import java.util.HashMap;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int n, t, a, c;
    HashMap<Integer, Integer> m = new HashMap();

    n = scanner.nextInt();
    t = scanner.nextInt();
    c = 0;

    while (n-- > 0) {
      a = scanner.nextInt();
      if (m.containsKey(t - a))
        c += m.get(t - a);
      if (m.containsKey(a))
        m.put(a, m.get(a) + 1);
      else
        m.put(a, 1);
    }

    System.out.print(c);
  }
}
