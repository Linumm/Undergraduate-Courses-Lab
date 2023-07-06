package Week9;
import java.util.Date;
public class Patient extends Person {
    private String department;

    public Patient(String name, Date born, Date died, String department)
    {
        super(name, born, died);
        this.department = department;
    }

    public void setDepartment(String department)
    {
        this.department = department;
    }

    public String getDepartment()
    {
        return this.department;
    }

    public String toString()
    {
        return "[Patient]" + super.toString() + ", Department : " + this.department;
    }

    public boolean equals(Patient patient)
    {
        return super.equals(patient) && this.department.equals(patient.department);
    }
}
