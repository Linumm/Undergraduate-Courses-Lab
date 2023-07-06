package Week3;
import java.util.Scanner;
public class Practice3 {
    public static void main(String[] args)
    {
        Scanner keyboard = new Scanner(System.in);

        System.out.println("Enter name of item 1: ");
        String name1 = keyboard.nextLine();
        //keyboard.nextLine();
        System.out.println("Enter quantity of item 1: ");
        int quantity1 = keyboard.nextInt();
        keyboard.nextLine();
        System.out.println("Enter price of item 1: ");
        double price1 = keyboard.nextDouble();
        keyboard.nextLine();

        System.out.println("Enter name of item 2: ");
        String name2 = keyboard.nextLine();
        System.out.println("Enter quantity of item 2: ");
        int quantity2 = keyboard.nextInt();
        keyboard.nextLine();
        System.out.println("Enter price of item 2: ");
        double price2 = keyboard.nextDouble();
        keyboard.nextLine();

        System.out.println("Enter name of item 3: ");
        String name3 = keyboard.nextLine();
        System.out.println("Enter quantity of item 3: ");
        int quantity3 = keyboard.nextInt();
        keyboard.nextLine();
        System.out.println("Enter price of item 3: ");
        double price3 = keyboard.nextDouble();

        double total1 = price1 * quantity1;
        double total2 = price2 * quantity2;
        double total3 = price3 * quantity3;
        double subtotal = total1 + total2 + total3;
        double plusTax = subtotal * 0.0625;
        double total =  subtotal + plusTax;


        System.out.println("Your bill:");
        System.out.println();
        System.out.printf("%-30s%-10s%-10s%-10s\n", "ITEM", "QUANTITY", "PRICE", "TOTAL");
        System.out.printf("%-30s%-10d%-10.2f%-10.2f\n", name1, quantity1, price1, total1);
        System.out.printf("%-30s%-10d%-10.2f%-10.2f\n", name2, quantity2, price2, total2);
        System.out.printf("%-30s%-10d%-10.2f%-10.2f\n", name3, quantity3, price3, total3);
        System.out.println();

        System.out.printf("%-50s%-10.2f\n", "SUBTOTAL", subtotal);
        System.out.printf("%-50s%-10.2f\n", "6.25% SALES TAX", plusTax);
        System.out.printf("%-50s%-10.2f\n", "TOTAL", total);
    }
}
