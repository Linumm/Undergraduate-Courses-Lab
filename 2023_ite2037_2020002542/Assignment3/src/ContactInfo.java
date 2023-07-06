public abstract class ContactInfo {
    protected String name;
    protected String phone_num;
    ContactInfo(String name, String phone_num)
    {
        this.name = name;
        this.phone_num = phone_num;
    }
    public abstract String getInfo();
    public abstract String toString();
    public abstract String getSpecificInfo();
    public void setName(String name) {this.name = name;}
    public void setPhoneNum(String phone_num) {this.phone_num = phone_num;}
    public abstract void setSpecific(String specific);
}
