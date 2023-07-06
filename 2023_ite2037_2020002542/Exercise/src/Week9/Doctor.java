package Week9;
import java.util.Date;

public class Doctor extends Person{
    private String hospital;

    public Doctor(String name, Date born, Date died, String hospital)
    {
        super(name, born, died);
        this.hospital = hospital;
    }

    public void setHospital(String hospital)
    {
        this.hospital = hospital;
    }

    public String toString()
    {
        return "[Doctor]" + super.toString() + ", Affiliation : " + this.hospital;
    }

    public boolean equals(Doctor doc) // Since parameter type is different, so it's overloading
    {
        return super.equals(doc) && this.hospital.equals(doc.hospital);
    }

    public void examination(Patient P)
    {
        System.out.println("I haven't decided my major yet");
    }
}
