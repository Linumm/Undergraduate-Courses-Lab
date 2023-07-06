package Week6.Exercise1.util;
import Week6.Exercise1.Person;
import java.util.Calendar;
public class AgeCalculator {
    public static int calAge(Person p)
    {
        Calendar current = Calendar.getInstance();
        int age = current.get(Calendar.YEAR) - p.getBorn().getYear() - 1;
        if (p.getBorn().getMonth() < current.get(Calendar.MONTH))
            age++;
        else if (p.getBorn().getMonth() == current.get(Calendar.MONTH)) {
            if (p.getBorn().getDate() <= current.get(Calendar.YEAR))
                age++;
        }

        return age;
    }

    public static int isOlder(Person p1, Person p2)
    {
        Calendar current = Calendar.getInstance();
        int p1_age = calAge(p1);
        int p2_age = calAge(p2);

        if (p1_age > p2_age) return 1;
        else if (p1_age == p2_age) return 0;
        else return -1;
    }
}
