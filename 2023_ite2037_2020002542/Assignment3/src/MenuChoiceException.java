

public class MenuChoiceException extends Exception{
    private int out_of_bound;
    public MenuChoiceException(int choice) {
        super(choice + "is out of bound");
    }
}
