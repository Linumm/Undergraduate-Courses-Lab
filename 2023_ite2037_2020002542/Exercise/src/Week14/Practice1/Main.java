package Week14.Practice1;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        System.out.print("Input max number: ");
        int n = scn.nextInt();
        ArrayList<Integer> prime_num = Eratos.sieve(n);

        Iterator<Integer> it = prime_num.iterator();
        while (it.hasNext()) {
            System.out.print(it.next());
            System.out.print(" ");
        }
    }
}
