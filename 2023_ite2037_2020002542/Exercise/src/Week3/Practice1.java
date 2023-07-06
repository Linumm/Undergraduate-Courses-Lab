package Week3;
import java.util.Scanner;
public class Practice1 {
    //Reading in a string containing two int nums from the keyboard
    // and divides the first num by the second num.
    public static void main(String[] args)
    {
        Scanner keyboard = new Scanner(System.in);
        String userInput = keyboard.nextLine();
        String[] tmp = userInput.split(",", 2);
        int num1 = Integer.parseInt(tmp[0]);
        int num2 = Integer.parseInt(tmp[1]);


        int quotient = (num1 / num2);
        int remainder = num1%num2;

        System.out.println("dividend: " + num1);
        System.out.println("divisor: " + num2);
        System.out.println("quotient: " + quotient);
        System.out.println("remainder: " + remainder );

    }
}
