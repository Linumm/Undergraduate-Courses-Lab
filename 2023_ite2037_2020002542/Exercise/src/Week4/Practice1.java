package Week4;
import java.util.Scanner;
import java.lang.String;
public class Practice1 {
    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in);
        System.out.println("Input string S: ");
        String userInput = keyboard.nextLine();
        String largest = "";
        int strlen = userInput.length();
        char leftPtr, rightPtr;

        char[] arr = userInput.toCharArray();
        //Search every possible cases for exception
        for (int j=strlen-1; j>-1; j--) {
            rightPtr = arr[j];
            for (int i=0; i<=j; i++) {
                leftPtr = arr[i];
                if (leftPtr == rightPtr) {
                    if (isPalindrome(userInput.substring(i,j+1))) {
                        if (userInput.substring(i,j+1).length() > largest.length())
                            largest = userInput.substring(i,j+1);
                    }
                }
            }
        }
        System.out.println("Longest Palindrome: " + largest);

    }

    public static boolean isPalindrome(String str) {
        String reversed = "";
        char[] arr = str.toCharArray();
        for (int i=str.length()-1; i>-1; i--)
            reversed = reversed + arr[i];
        return str.equals(reversed);
    }
}
