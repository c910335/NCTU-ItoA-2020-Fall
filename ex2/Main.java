import java.io.StreamTokenizer;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
  public static void main(String[] args) throws IOException {
    StreamTokenizer st = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    int t, n, k, a;
    st.nextToken();
    t = (int) st.nval;

    while (t-- > 0) {
      st.nextToken();
      n = (int) st.nval;
      st.nextToken();
      k = (int) st.nval;
      a = 0;
      while (n >= k) {
        a += n / k;
        n = n / k + n % k;
      }
      System.out.println(a);
    }
  }
}
