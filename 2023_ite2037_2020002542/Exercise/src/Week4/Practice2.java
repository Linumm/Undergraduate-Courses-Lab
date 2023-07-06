package Week4;
import java.util.Scanner;
import java.util.Random;
public class Practice2 {
    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in);
        Random rnd = new Random();
        int player_score = 0;
        int com_score = 0;
        int tmp_cumulate = 0; //If player roll and roll, there needs memory for previous dice
        boolean player_turn = true; //
        boolean firstRoll = true;

        String action;
        int dice = 0;

        while (player_score < 100 && com_score <100) {
            action = "";
            tmp_cumulate = 0;
            firstRoll = true;
            if (player_turn) {
                while (!action.equals("h")) {
                    if (firstRoll) {
                        System.out.print("(You) insert action r(roll) : ");
                    }
                    else {
                        System.out.print("(You) insert action r(roll), h(hold) : ");
                    }

                    action = keyboard.next();

                    if (action.equals("r")) {
                        dice = rnd.nextInt(1, 7);
                        System.out.println("(You) dice rolled : " + dice);
                        tmp_cumulate += dice; //Save a number for case of hold
                        firstRoll = false;
                    }
                    else if (action.equals("h")) {
                        player_score += tmp_cumulate;
                        player_turn = false;
                        System.out.println("(You) " + tmp_cumulate + " added to You");
                        break;
                    }
                    else {
                        System.out.println("Wrong Command. Program end");
                        System.exit(0);
                    }

                    if (dice == 1) {
                        System.out.println("(You) No socre added");
                        player_turn = false;
                        break;
                    }
                }
                System.out.println("(You) Your score " + player_score + ", Computer score " + com_score);
            }
            else {
                while (true) {
                    if (tmp_cumulate >= 20) { // Computer always roll again until cumulative score go over 20
                        System.out.println("(Computer) insert action r(roll), h(hold) : h");
                        break;
                    }

                    if (firstRoll) {
                        System.out.println("(Computer) insert action r(roll) : r");
                        firstRoll = false;
                    } else {
                        System.out.println("(Computer) insert action r(roll), h(hold) : r");
                    }
                    dice = rnd.nextInt(1, 6);
                    System.out.println("(Computer) dice rolled : " + dice);
                    tmp_cumulate += dice;

                    if (dice == 1) {
                        System.out.println("(Computer) No score added");
                        player_turn = true;
                        tmp_cumulate = 0;
                        break;
                    }
                }
                com_score += tmp_cumulate;
                player_turn = true;
                System.out.println("(Computer) Your score " + player_score + ", Computer score " + com_score);
            }
            System.out.println();
        }

        //Score announcement
        System.out.println("(Game) Your score " + player_score + ", Computer score " + com_score);
        if (player_score > com_score)
            System.out.println("Congratulations! You win!");
        else if (com_score > player_score)
            System.out.println("Sorry, the computer wins.");
    }
}
