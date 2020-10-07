// TLE
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    PriorityQueue<Integer> l = new PriorityQueue<>(Collections.reverseOrder());
    PriorityQueue<Integer> r = new PriorityQueue<>();
    int n, k, x, s = 0;
    n = scanner.nextInt();
    k = scanner.nextInt();
    k = 100 - k;

    while (n-- > 0) {
      x = scanner.nextInt();
      if (x == 0) {
        if (l.isEmpty())
          System.out.println(r.peek());
        else
          System.out.println(l.peek());
      } else {
        s++;
        if (l.isEmpty() || x < l.peek()) {
          l.add(x);
          if (r.size() < s * k / 100)
            r.add(l.poll());
        } else {
          r.add(x);
          if (r.size() > s * k / 100)
            l.add(r.poll());
        }
      }
    }
  }
}
