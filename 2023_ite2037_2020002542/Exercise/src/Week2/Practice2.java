package Week2;

public class Practice2 {
    public static void main(String[] args) {
        String input = "Walt Savitch";
        String output = null;

        String input1 = input.substring(1,2).toUpperCase() + input.substring(2, input.indexOf(" ")).toLowerCase() + input.substring(0, 1).toLowerCase() + "ay";
        String input2 = input.substring(input.indexOf(" ")+1);
        input2 = input2.substring(1,2).toUpperCase() + input2.substring(2).toLowerCase() + input2.substring(0, 1).toLowerCase() + "ay";

        output = input1 + " " + input2;


        System.out.println(output);
    }
}
