import java.util.PriorityQueue;
import java.util.Scanner;
import static java.util.Collections.reverseOrder;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    PriorityQueue<Integer> q = new PriorityQueue<>(reverseOrder());
    int n = scanner.nextInt(), a;
    long c = 0;
    while (n-- > 0) {
      a = scanner.nextInt();
      q.add(a);
    }
    q.add(0);

    while (q.size() > 1) {
      a = q.poll();
      a -= q.poll();
      if (a != 0) {
        c += a;
        q.add(a);
      }
    }

    System.out.print(c);
  }
}
