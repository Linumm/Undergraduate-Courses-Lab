package Week6.Exercise1;

import java.util.Date;
import Week6.Exercise1.util.AgeCalculator;

public class Main {
    public static void main(String[] args)
    {
        Date p1_birth = new Date(1999, 4, 13);
        Date p2_birth = new Date(2002, 4, 12);

        Person p1 = new Person("John", p1_birth, null);
        Person p2 = new Person("Paul", p2_birth, null);

        int p1_age = AgeCalculator.calAge(p1);
        int p2_age = AgeCalculator.calAge(p2);

        System.out.println(p1.toString());
        System.out.println(p2.toString());
        System.out.println("isOlder() result: " + AgeCalculator.isOlder(p1, p2));
    }
}
