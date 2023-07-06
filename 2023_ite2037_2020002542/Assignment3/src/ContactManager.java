import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

public class ContactManager {
    private static class MyStorage<T> {
        private int size;
        private ArrayList<T> list;
        private String file_path;
        public MyStorage(int size)
        {
            this.size = size;
            this.list = new ArrayList<T>();
            this.file_path = "ContactList.txt";
            File tmp = new File(this.file_path);
            try {
                FileOutputStream fileOutputStream = new FileOutputStream(tmp, true);
            }
            catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }
    }
    private MyStorage<ContactInfo> contactStorage;
    public CommandLineInterface cli;
    public ContactManager(CommandLineInterface cli)
    {
        this.cli = cli;
        contactStorage = new MyStorage<ContactInfo>(0);
    }
    public void setStorageSize(int size)
    {
        this.contactStorage.size = size;
    }
    public void saveToFile()
    {
        // In-text deletion
        PrintWriter writer = null;
        try {
            writer = new PrintWriter(new FileOutputStream(contactStorage.file_path, false));
            for (ContactInfo info: contactStorage.list) {
                if (info.getClass().getSimpleName().equals("NormalContact")) {
                    writer.println("N " + info.getInfo());
                }
                else if (info.getClass().getSimpleName().equals("ClubContact")) {
                    writer.println("C " + info.getInfo());
                }
                else if (info.getClass().getSimpleName().equals("DepartmentContact")) {
                    writer.println("D " + info.getInfo());
                }
            }
            writer.close();
        } catch (IOException e) { e.printStackTrace(); }
    }
    public void loadFromFile()
    {
        if (!cli.printAskContinue())
            return;
        Scanner file_reader = null;
        try {
            file_reader = new Scanner(new FileInputStream(contactStorage.file_path));
        }
        catch (FileNotFoundException e) {
            System.out.println("Failed to load saved file");
            return;
        }
        // Clear current contactStorage.list
        contactStorage.list.clear();
        String contact_type = "";
        String name = "";
        String phone_num = "";
        String detail_info = "";

        while (file_reader.hasNextLine()) {
            // Bring info from file
            String current_line = file_reader.nextLine();
            StringTokenizer current = new StringTokenizer(current_line);
            if (current.hasMoreTokens())
                contact_type = current.nextToken();
            if (current.hasMoreTokens())
                name = current.nextToken();
            if (current.hasMoreTokens())
                phone_num = current.nextToken();
            if (current.hasMoreTokens())
                detail_info = current.nextToken();

            // Make object to add in contactStorage.list
            ContactInfo tmp = null;
            if (contact_type.equals("N")) { // Case : Normal Contact
                tmp = new NormalContact(name, phone_num, detail_info);
            }
            else if (contact_type.equals("C")) { // Case : Club Contact
                tmp = new ClubContact(name, phone_num, detail_info);
            }
            else if (contact_type.equals("D")) { // Case : Department Contact
                tmp = new DepartmentContact(name, phone_num, detail_info);
            }
            contactStorage.list.add(tmp);
        }
        contactStorage.size = contactStorage.list.size();
        cli.printFinished();
    }
    public String searchContact(int category, String detail_info)
    {
        ArrayList<String> result = new ArrayList<String>();

        switch (category) {
            case 1:
                for (ContactInfo data: contactStorage.list) {
                    if (detail_info.equals(data.name)) {
                        result.add(data.toString());
                    }
                }
                break;
            case 2:
                for (ContactInfo data: contactStorage.list) {
                    if (detail_info.equals(data.phone_num)) {
                        result.add(data.toString());
                    }
                }
                break;
            case 3:
                for (ContactInfo data: contactStorage.list) {
                    if (data.getClass().getSimpleName().equals("NormalContact") && detail_info.equals(data.getSpecificInfo())) {
                        result.add(data.toString());
                    }
                }
                break;
            case 4:
                for (ContactInfo data: contactStorage.list) {
                    if (data.getClass().getSimpleName().equals("ClubContact") && detail_info.equals(data.getSpecificInfo())) {
                        result.add(data.toString());
                    }
                }
                break;
            case 5:
                for (ContactInfo data: contactStorage.list) {
                    if (data.getClass().getSimpleName().equals("DepartmentContact") && detail_info.equals(data.getSpecificInfo())) {
                        result.add(data.toString());
                    }
                }
                break;
            default:
                break;
        }

        String output = "";
        if (result.size() == 0) output += "Sorry, not found";
        else {
            output += result.size() + " contacts are found\n";
            for (int i=0; i<result.size(); i++)
                output += result.get(i) + "\n";
        }

        return output;
    }
    public void deleteContact(ContactInfo target)
    {
        if (cli.printAskContinue())
            contactStorage.list.remove(target);
        cli.printFinished();
    }
    public void editContact(ContactInfo target, int category, String detail_info)
    {
        if (!cli.printAskContinue()) {
            cli.printFinished();
            return;
        }
        switch (category) {
            case 1:
                target.setName(detail_info);
                break;
            case 2:
                target.setPhoneNum(detail_info);
                break;
            case 3:
                target.setSpecific(detail_info);
                break;
            case 4:
                target.setSpecific(detail_info);
                break;
            case 5:
                target.setSpecific(detail_info);
                break;
            default:
                break;
        }
        cli.printFinished();
    }
    public String getAllContactInfo()
    {
        // Categorize
        String normal_contacts = "Normal Contacts\n";
        String club_contacts = "Club Contacts\n";
        String department_contacts = "Department Contacts\n";
        int n_count = 1;
        int c_count = 1;
        int d_count = 1;
        for (int i=0; i<contactStorage.list.size(); i++) {
            ContactInfo tmp = contactStorage.list.get(i);
            if (tmp.getClass().getSimpleName().equals("NormalContact")) {
                normal_contacts += ("\t" + n_count + ". " + tmp.toString() +"\n");
                n_count++;
            }
            else if (tmp.getClass().getSimpleName().equals("ClubContact")) {
                club_contacts += ("\t" + c_count + ". " + tmp.toString() + "\n");
                c_count++;
            }
            else if (tmp.getClass().getSimpleName().equals("DepartmentContact")) {
                department_contacts += ("\t" + d_count + ". " + tmp.toString() + "\n");
                d_count++;
            }
        }

        String result = normal_contacts + club_contacts + department_contacts;
        return result;
    }
    public ContactInfo getOneSearchResult(int category, String detail_info)
    {
        ContactInfo target = null;

        switch (category) {
            case 1:
                for (ContactInfo data: contactStorage.list) {
                    if (detail_info.equals(data.name)) {
                        target = data;
                        break;
                    }
                }
                break;
            case 2:
                for (ContactInfo data: contactStorage.list) {
                    if (detail_info.equals(data.phone_num)) {
                        target = data;
                        break;
                    }
                }
                break;
            case 3:
                for (ContactInfo data: contactStorage.list) {
                    if (data.getClass().getSimpleName().equals("NormalContact") && detail_info.equals(data.getSpecificInfo())) {
                        target = data;
                        break;
                    }
                }
                break;
            case 4:
                for (ContactInfo data: contactStorage.list) {
                    if (data.getClass().getSimpleName().equals("ClubContact") && detail_info.equals(data.getSpecificInfo())) {
                        target = data;
                        break;
                    }
                }
                break;
            case 5:
                for (ContactInfo data: contactStorage.list) {
                    if (data.getClass().getSimpleName().equals("DepartmentContact") && detail_info.equals(data.getSpecificInfo())) {
                        target = data;
                        break;
                    }
                }
                break;
            default:
                break;
        }

        return target;
    }
    public void addInfoToStorage(ContactInfo info)
    {
        contactStorage.list.add(info);
    }
    public boolean checkStorageSize() {
        if (contactStorage.size == contactStorage.list.size()) {
            cli.printSizeError();
            return false;
        }
        return true;
    }
}
