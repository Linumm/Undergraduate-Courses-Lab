public class NormalContact extends ContactInfo{
    String relation;
    NormalContact(String name, String phone_num, String relation)
    {
        super(name, phone_num);
        this.relation = relation;
    }
    public String getInfo()
    {
        String info = name + " "+ phone_num + " " + relation;
        return info;
    }
    public String toString()
    {
        String contact_info = "name: " + name + " / phone number: " + phone_num + " / relation: " + relation;
        return contact_info;
    }
    @Override
    public String getSpecificInfo() {
        String specific = new String(relation);
        return specific;
    }
    public void setSpecific(String specific) {this.relation = specific;}
}
