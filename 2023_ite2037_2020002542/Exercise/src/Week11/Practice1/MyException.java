package Week11.Practice1;

public class MyException extends Exception{
    String message;
    public MyException()
    {
        super("");
    }
    public MyException(String message)
    {
        super(message);
        this.message = message;
    }
    public String getMessage()
    {
        if (message.equals("a or b is less or euqal to 1!"))
            return "Exception: " + super.getMessage() + " Type both integers with larger than 1!";
        else if (message.equals("a and b are the same!"))
            return "Exception: " + super.getMessage() + " Type different integers!";
        else if (message.equals("Both a and b are larger than 10000!"))
            return "Exception: " + super.getMessage() + " Type both integers with smaller than 10000";
        return "";
    }
}
