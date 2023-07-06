package Week9;
import javax.print.Doc;
import java.util.Date;
public class Main {
    public static void main(String[] args)
    {
        String doc_name = "D";
        String patient_name = "PA";
        String phy_name = "PH";

        Date born_date = new Date(2001, 10, 11);
        Date died_date = new Date(2040, 10, 11);

        Doctor doc = new Doctor(doc_name, born_date, died_date, "HOSPITAL");
        Patient patient = new Patient(patient_name, born_date, died_date, "internal");
        Patient patient2 = new Patient(patient_name, born_date, died_date, "Dental");
        Physician phy = new Physician(phy_name, born_date, died_date, "HOSPITAL");

        System.out.print("Doctor class examination: ");
        doc.examination(patient);
        System.out.print("Physician class examination with patient: ");
        phy.examination(patient);
        System.out.print("Physician class examination with patient2: ");
        phy.examination(patient2);

        System.out.println(doc.toString());
        System.out.println(patient.toString());
    }
}
