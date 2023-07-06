import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args)
    {
        CommandLineInterface cli = new CommandLineInterface();
        ContactManager manager = new ContactManager(cli);
        int choice;
        ContactInfo current = null;
        int category;
        String detail_info ="";

        while(true)
        {
            try
            {
                choice = cli.getMainMenu();
                if(choice < 1 || choice > 9)
                    throw new MenuChoiceException(choice);


                switch(choice)
                {
                    case 1: // Set size of total contacts
                        int storage_size = cli.getSetSizeMenu();
                        manager.setStorageSize(storage_size);
                        break;
                    case 2: // Save the current contact to a file
                        manager.saveToFile();
                        cli.printFinished();
                        break;
                    case 3: // Load the saved contact file
                        manager.loadFromFile();
                        cli.printFinished();
                        break;
                    case 4: // Register new contact
                        if(manager.checkStorageSize()) {
                            current = cli.getCreateContactMenu();
                            manager.addInfoToStorage(current);
                            cli.printFinished();
                        }
                        break;
                    case 5: // Search contact
                        category = cli.getSearchContactMenu();
                        detail_info = cli.getDetailInput(category);
                        String result = manager.searchContact(category, detail_info);
                        cli.printSearchResult(result);
                        break;
                    case 6: // Delete contact
                        // Search process
                        category = cli.getDeleteContactMenu();
                        detail_info = cli.getDetailInput(category);
                        current = manager.getOneSearchResult(category, detail_info);
                        cli.printOneSearchResult(current);

                        // Delete process
                        if (current == null) cli.printNotFound();
                        else manager.deleteContact(current);
                        break;
                    case 7: // Edit contact
                        // Search process
                        category = cli.getSearchContactMenu();
                        detail_info = cli.getDetailInput(category);
                        current = manager.getOneSearchResult(category, detail_info);
                        cli.printOneSearchResult(current);

                        // Edit process
                        if (current == null) cli.printNotFound();
                        else {
                            int edit_var = cli.getEditContactMenu();
                            String edit_detail = cli.getDetailInput(edit_var);
                            manager.editContact(current, edit_var, edit_detail);
                        }
                        break;
                    case 8: // View all contacts
                        cli.printContactInfo(manager);
                        break;
                    case 9: // exit
                        cli.printAskContinue();
                        System.exit(1);
                        break;
                    default:
                        break;

                }
            }
            catch(MenuChoiceException e)
            {
                cli.printErrorMessage();
            }
        }
    }
}
