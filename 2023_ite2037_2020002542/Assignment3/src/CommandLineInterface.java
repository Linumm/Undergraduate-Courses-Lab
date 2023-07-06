import java.util.Scanner;
public class CommandLineInterface {
    private Scanner scanner;
    public CommandLineInterface()
    {
        this.scanner = new Scanner(System.in);
    }
    public int getMainMenu() // Print main menu, user command 입력 받아서 return 해주기
    {
        System.out.println("----<Main Menu>----");
        System.out.println("1. Set size of total contacts");
        System.out.println("2. Save the current contact to a file");
        System.out.println("3. Load the saved contact file");
        System.out.println("4. Register new contact");
        System.out.println("5. Search contact");
        System.out.println("6. Delete contact");
        System.out.println("7. Edit contact");
        System.out.println("8. View All Contacts");
        System.out.println("9. Exit");
        System.out.print("Select: ");
        int user_cmd = scanner.nextInt();

        return user_cmd;
    }
    public int getSetSizeMenu()
    {
        System.out.println("Type storage size: ");
        int storage_size = scanner.nextInt();
        return storage_size;
    }
    public ContactInfo getCreateContactMenu() // Print Contact menu: normal/club/department
    {
        ContactInfo contact_ptr = null;
        System.out.println("Create contact...");
        System.out.println("1. normal contact");
        System.out.println("2. club contact");
        System.out.println("3. department contact");
        System.out.print("Select: ");
        int contact_type = -1;
        while (true) {
            contact_type = scanner.nextInt();
            if (contact_type < 1 || contact_type > 3) {
                System.out.println("Wrong input, type among 1~3: ");
            }
            else
                break;
        }
        System.out.println();

        System.out.print("Write your name: ");
        String name = scanner.next();
        scanner.nextLine();
        System.out.println();
        System.out.println("Write your phone number: (***-****-****, including '-')");
        String phone_num = "";
        while (true) {
            phone_num = scanner.nextLine();
            if (checkPhoneNumFormat(phone_num))
                break;
            else
                System.out.println("Wrong format. write-> ***-****-****");
        }
        System.out.println();

        //
        String additional_info;
        if (contact_type == 1) {
            System.out.print("Write relation: ");
            additional_info = scanner.next();
            contact_ptr = new NormalContact(name, phone_num, additional_info);
        }
        else if (contact_type == 2) {
            System.out.print("Write club name: ");
            additional_info = scanner.next();
            contact_ptr = new ClubContact(name, phone_num, additional_info);
        }
        else if (contact_type == 3) {
            System.out.print("Write department: ");
            additional_info = scanner.next();
            contact_ptr = new DepartmentContact(name, phone_num, additional_info);
        }
        System.out.println();
        return contact_ptr;
    }
    public int getSearchContactMenu()
    {
        System.out.println("Search contact...");
        return chooseVariable();
    }
    public int getDeleteContactMenu()
    {
        System.out.println("Search contact before deletion");
        return chooseVariable();
    }
    public int getEditContactMenu()
    {
        System.out.println("Choose a detail you want to edit");
        return chooseVariable();
    }
    public void printContactInfo(ContactManager manager) // Contact type 분류해서 print
    {
        System.out.print(manager.getAllContactInfo());
    }
    public void printErrorMessage()
    {
        System.out.println("Wrong Command: Select one menu among 1~9 and type one");
    }
    public String getDetailInput(int category)
    {
        String detail_info = "";
        System.out.println("Write the detailed (case of phone num: ***-****-****): ");

        if (category == 2) {
            while (true) {
                detail_info = scanner.nextLine();
                if (checkPhoneNumFormat(detail_info))
                    break;
            }
        }

        detail_info = scanner.next();
        return detail_info;
    }
    public void printSearchResult(String result)
    {
        System.out.println(result);
    }
    public int chooseVariable()
    {
        System.out.println("Choose the variable");
        System.out.println("1. name");
        System.out.println("2. phone number");
        System.out.println("3. relation");
        System.out.println("4. club name");
        System.out.println("5. department");
        int user_cmd;
        while (true) {
            System.out.print("Select: ");
            user_cmd = scanner.nextInt();
            System.out.println();
            if (user_cmd < 1 || user_cmd > 5) {
                System.out.println("Wrong input: select 1, 2, 3, 4 or 5");
            }
            else
                break;
        }
        return user_cmd;
    }
    public boolean printAskContinue()
    {
        System.out.println("CAUTION: Will you continue?");
        System.out.print("Continue? if yes, type \"yes\" or type anything: ");
        String user_cmd = scanner.next();
        if (user_cmd.equals("yes"))
            return true;
        else
            return false;
    }
    public void printFinished()
    {
        System.out.println("Process finished");
    }
    public void printNotFound()
    {
        System.out.println("Sorry, not found");
    }
    public void printOneSearchResult(ContactInfo info)
    {
        System.out.println(info.toString());
    }
    public void printSizeError() { System.out.println("Sorry, current storage size is full, Set storage size first."); }
    public boolean checkPhoneNumFormat(String s)
    {
        if (s.length() != 13)
            return false;
        if (s.charAt(3) != '-' || s.charAt(8) != '-')
            return false;
        for (int i=0; i<13; i++) {
            if (i == 3 || i == 8)
                continue;
            if (s.charAt(i) < '0' || s.charAt(i) > '9')
                return false;
        }
        return true;
    }
}
