public class ClubContact extends ContactInfo{
    String club_name;
    ClubContact(String name, String phone_num, String club_name)
    {
        super(name, phone_num);
        this.club_name = club_name;
    }
    public String getInfo()
    {
        String info = name + " " + phone_num + " " + club_name;
        return info;
    }
    public String toString()
    {
        String contact_info = "name: " + name + " / phone number: " + phone_num + " / club name: " + club_name;
        return contact_info;
    }
    public String getSpecificInfo() {
        String specific = new String(club_name);
        return specific;
    }
    public void setSpecific(String specific) {this.club_name = specific;}
}
