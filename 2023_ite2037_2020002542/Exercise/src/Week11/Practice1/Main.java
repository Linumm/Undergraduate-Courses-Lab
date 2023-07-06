package Week11.Practice1;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Main {
    public static boolean isCoprime(int a, int b)
    {
        try {
            if (a <= 1 || b <= 1)
                throw new MyException("a or b is less or euqal to 1!");
            if (a == b)
                throw new MyException("a and b are the same!");
            if (a > 10000 && b > 10000)
                throw new MyException("Both a and b are larger than 10000!");

            int smaller;
            if (a <= b)
                smaller = a;
            else
                smaller = b;

            for (int i=1; i<=smaller; i++) {
                if (a % smaller == 0 && b % smaller == 0)
                    return false;
            }

        } catch (MyException excp) {
            System.out.println(excp.getMessage());
            System.exit(0);
        }
        return true;
    }
    public static void main(String[] args)
    {
        Scanner scn = new Scanner(System.in);
        try {
            int a = scn.nextInt();
            int b = scn.nextInt();

            if (isCoprime(a, b))
                System.out.println("'Coprime'");
            else
                System.out.println("Not 'Coprime'");
        } catch (InputMismatchException excp) {
            System.out.println("Input type is not 'integer'");
        }

    }
}
