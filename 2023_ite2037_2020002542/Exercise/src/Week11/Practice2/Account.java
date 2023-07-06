package Week11.Practice2;

public class Account {
    private String ID;
    private int account_num;
    private String digit_account_num;
    private int balance;
    public boolean valid_account;

    public Account(String ID, String account_num, int balance)
    {
        try {
            char c = ID.charAt(0);
            if (ID.length() != 4)
                throw new Exception("ID format is invalid: format ('Alphabet'+ 3 digits')");

            char d1 = ID.charAt(1);
            char d2 = ID.charAt(2);
            char d3 = ID.charAt(3);

            char a0 = account_num.charAt(0);
            char a1 = account_num.charAt(1);
            char a2 = account_num.charAt(2);
            char a3 = account_num.charAt(3);
            char a4 = account_num.charAt(4);

            if (!(d1 >= '0' && d1 <= '9') && !(d2 >= '0' && d2 <= '9') && !(d3 >= '0' && d3 <= '9'))
                throw new Exception("ID format is invalid: format ('Alphabet'+ 3 digits'");

            if (!(c >= 'A' && c <= 'Z') && !(c >= 'a' && c <= 'z')) {
                throw new Exception("ID format is invalid: format ('Alphabet'+ 3 digits'");
            }
            if (account_num.length() != 5 || !(a0 >= '0' && a0 <= '9') && !(a1 >= '0' && a1 <= '9') && !(a2 >= '0' && a2 <= '9') && !(a3 >= '0' && a3 <= '9') && !(a4 >= '0' && a4 <= '9')) {
                throw new Exception("Account number is not five digits");
            }
            if (balance <= 1000)
                throw new Exception("Balance is not above 1000$");

            this.ID = ID;
            this.account_num = Integer.parseInt(account_num);
            this.digit_account_num = account_num;
            this.balance = balance;
            this.valid_account = true;

        } catch (Exception excp){
            System.out.println(excp.getMessage());
            this.valid_account = false;
        }
    }

    public String toString()
    {
        return "ID: " + this.ID + " Account num: " + this.digit_account_num + " Balance: " + this.balance;
    }
}
