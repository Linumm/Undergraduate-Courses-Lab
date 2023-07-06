package Week3;

import java.util.Scanner;

public class Practice2 {
    public  static void main(String[] args)
    {
        Scanner keyboard = new Scanner(System.in);
        int userInput = keyboard.nextInt();
        int gpa = (userInput * 4)/100;

        System.out.println("(" + userInput + "/100)*4=" + gpa);
    }
}
