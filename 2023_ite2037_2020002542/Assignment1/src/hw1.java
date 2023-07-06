import java.util.Scanner;
import java.util.Random;

public class hw1 {
    public static void main(String[] args){
        Scanner userInput = new Scanner(System.in);
        int n_userMoney, m_numOfTicket;
        int current = 0;

        while (true){
            System.out.println("Input your money and number of lottery tickets:");
            System.out.print("<< ");
            n_userMoney = userInput.nextInt();
            m_numOfTicket = userInput.nextInt();
            int[] rank = {0,0,0,0,0}; // rank[0]: 1st, rank[1]: 2nd ... rank[4]: lose

            // If n or m is 0, end the program
            if (n_userMoney == 0 || m_numOfTicket == 0) {
                System.out.println();
                System.out.println(">> End of program");
                System.exit(0);
            }
            else if (m_numOfTicket * 10 > n_userMoney) continue;

            current += n_userMoney - m_numOfTicket * 10;

            LotteryGenerator winning_table = new LotteryGenerator(false);
            LotteryChecker checker = new LotteryChecker();
            System.out.println("Lottery and checker generated");

            //Print out winning_table
            System.out.print(">> Round Winning number : ");
            for (int i=0; i<6; i++)
                System.out.print(winning_table.number[i] + " ");
            System.out.println("+ " + winning_table.bonusNumber);

            //Make ticket each times and print out the result
            for (int i=0; i<m_numOfTicket; i++) {
                //Generate tickets and directly check.
                LotteryGenerator ticket = new LotteryGenerator(true);
                rank[checker.getPrize(ticket, winning_table) - 1] += 1;
                System.out.print(">> Lottery number : ");
                for (int num: ticket.number)
                    System.out.print(num + " ");
                System.out.println(checker.prize);
            }

            //Print out current money
            System.out.println(">> Remaining money : " + current);

            //Print out the podium
            System.out.println(">> 1st place: " + rank[0]);
            System.out.println(">> 2nd place: " + rank[1]);
            System.out.println(">> 3rd place: " + rank[2]);
            System.out.println((">> 4th place: " + rank[3]));
        }
    }
}

