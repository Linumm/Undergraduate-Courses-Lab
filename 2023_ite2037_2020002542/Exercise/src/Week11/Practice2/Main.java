package Week11.Practice2;
import java.util.Scanner;
public class Main {
    public static void main(String[] args)
    {
        Scanner scn = new Scanner(System.in);
        String id;
        String account_num;
        int balance;
        while (true) {
            id = scn.next();
            account_num = scn.next();
            balance = scn.nextInt();

            Account new_account = new Account(id, account_num, balance);
            if (new_account.valid_account) {
                System.out.println(new_account.toString());
                break;
            }
        }
    }
}
