package Week5;
import java.util.Calendar;
import java.util.Random;
public class Student {
    private String name;
    private int year;
    private int month;
    private int day;

    public Student(String name, int year, int month, int day) {
        this.name = name;
        this.year = year;
        this.month = month;
        this.day = day;
    }

    public Student(String name, int year) {
        Random rnd = new Random();
        this.name = name;
        this.year = year;
        this.month = rnd.nextInt(1, 13);
        this.day = rnd.nextInt(1, 32);
    }

    public String getName() { return this.name; }
    public int getYear() { return this.year; }
    public int getMonth() { return this.month; }
    public int getDay() { return this.day; }

    public boolean checkDate() {
        Calendar current = Calendar.getInstance();
        Calendar _this = Calendar.getInstance();
        _this.set(Calendar.YEAR, this.year);
        _this.set(Calendar.MONTH, this.month-1);
        _this.set(Calendar.DATE, this.day);

        if (_this.after(current)) return false;

        int m = this.month;
        if (this.day < 0 || m < 0) return false;

        if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) {
            if (this.day > 31) return false;
            else return true;
        }
        else if (m==2) { //윤년 고려 X
            if (this.day > 28) return false;
            else return true;
        }
        else if (m < 12) {
            if (this.day > 30) return false;
            else return true;
        }
        return true;
    }

    public int calAge() {
        Calendar current = Calendar.getInstance();
        int age = current.get(Calendar.YEAR) - this.year - 1;
        // if birthday already passed, +1
        if (this.month < current.get(Calendar.MONTH) + 1) age++;
        else if (this.month == current.get(Calendar.MONTH) + 1) {
            if (this.day <= current.get(Calendar.DATE)) age++;
        }

        return age;
    }

    public boolean isOlder(Student stu) {
        int stu_year = stu.getYear();
        int stu_month = stu.getMonth();
        int stu_day = stu.getDay();

        Calendar stu_bth = Calendar.getInstance();
        stu_bth.set(Calendar.YEAR, stu_year);
        stu_bth.set(Calendar.MONTH, stu_month-1);
        stu_bth.set(Calendar.DATE, stu_day);

        Calendar _this = Calendar.getInstance();
        _this.set(Calendar.YEAR, this.year);
        _this.set(Calendar.MONTH, this.month-1);
        _this.set(Calendar.DATE, this.day);

        return _this.before(stu_bth);
    }
}
