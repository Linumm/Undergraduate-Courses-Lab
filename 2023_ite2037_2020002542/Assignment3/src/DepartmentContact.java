public class DepartmentContact extends ContactInfo{
    private String department;
    DepartmentContact(String name, String phone_num, String department)
    {
        super(name, phone_num);
        this.department = department;
    }
    public String getInfo()
    {
        String info = name + " " + phone_num + " " + department;
        return info;
    }
    public String toString()
    {
        String contact_info = "name: " + name + " / phone number: " + phone_num + " / department: " + department;
        return contact_info;
    }
    public String getSpecificInfo() {
        String specific = new String(department);
        return specific;
    }
    public void setSpecific(String specific) {this.department = specific;}
}
