package Week14.Practice1;
import java.util.ArrayList;

public class Eratos {
    public static ArrayList<Integer> sieve(int n)
    {
        ArrayList<Integer> prime_nums = new ArrayList<Integer>(n);
        boolean[] is_prime = new boolean[n+1];

        for (int i=2; i<n+1; i++) {
            is_prime[i] = true;
        }
        for (int i=2; i<n+1; i++) {
            if (is_prime[i]) {
                for (int j = 2; j * i <= n; j++) {
                    is_prime[j*i] = false;
                }
            }
        }

        for (int i=2; i<n+1; i++) {
            if (is_prime[i])
                prime_nums.add(i);
        }

        return prime_nums;
    }
}
