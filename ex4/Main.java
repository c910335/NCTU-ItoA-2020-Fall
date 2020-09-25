import java.io.StreamTokenizer;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
  public static void main(String[] args) throws IOException {
    StreamTokenizer st = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    int n, a, f = 0;

    st.nextToken();
    n = (int) st.nval;
    n = 2 * n - 1;
    while (n-- > 0) {
      st.nextToken();
      a = (int) st.nval;
      f ^= a;
    }

    System.out.print(f);
  }
}
