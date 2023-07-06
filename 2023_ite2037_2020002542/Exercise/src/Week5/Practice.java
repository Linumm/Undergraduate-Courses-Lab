package Week5;
import java.util.StringTokenizer;
import java.util.Scanner;
public class Practice {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        String userInput = scn.nextLine();
        StringTokenizer st = new StringTokenizer(userInput, " /.");

        String st1_name, st2_name;
        int st1_y, st1_m, st1_d;

        st1_name = st.nextToken();
        st1_y = Integer.parseInt(st.nextToken());
        st1_m = Integer.parseInt(st.nextToken());
        st1_d = Integer.parseInt(st.nextToken());

        Student st1 = new Student(st1_name, st1_y, st1_m, st1_d);

        st2_name = scn.next();
        Student st2 = new Student(st2_name, st1_y);

        if (!st1.checkDate()) {
            System.out.println("invalid input");
            System.exit(1);
        }
        if (!st2.checkDate()) {
            System.out.println("invalid input in second student");
            System.exit(1);
        }

        System.out.println(st1.getName() +" "+ st1.getYear()+"/"+ st1.getMonth() + "/" + st1.getDay() + " age: " + st1.calAge());
        System.out.println(st2.getName() +" "+ st2.getYear()+"/"+ st2.getMonth() + "/" + st2.getDay() + " age: " + st2.calAge());
        if (st1.calAge() > st2.calAge())
            System.out.println(st1.getName() + " is older than " + st2.getName());
        else if (st1.calAge() < st2.calAge())
            System.out.println(st2.getName() + " is older than " + st2.getName());
        else if (st1.calAge() == st2.calAge())
            System.out.println("Same age");

    }
}
