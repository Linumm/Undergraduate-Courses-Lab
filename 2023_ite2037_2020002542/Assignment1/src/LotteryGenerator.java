import java.util.Random;
import java.util.Arrays;
public class LotteryGenerator {
    int[] number = new int[6];
    int bonusNumber = -1;
    int[] duplicationCheck = new int[20];
    boolean is_ticket; // To distinguish the ticket and winning number table
    LotteryGenerator(boolean is_ticket) { // Case of Winning number
        Random rnd = new Random();
        this.is_ticket = is_ticket;
        int tmp; // Random number
        boolean is_dub = false;
        int idx = 0; //idx of number array


        while (idx < 6) {
            is_dub = false;
            tmp = rnd.nextInt(1,21);
            for (int dup : duplicationCheck) {
                if (tmp == dup) {
                    is_dub = true;
                    break;
                }
            }

            if (!is_dub) {
                number[idx] = tmp;
                duplicationCheck[idx] = tmp;
                idx++;
            }
        }
        while (bonusNumber == -1) {
            is_dub = false;
            tmp = rnd.nextInt(1,21);
            for (int dup : duplicationCheck) {
                if (tmp == dup) {
                    is_dub = true;
                    break;
                }
            }

            if (!is_dub)
                bonusNumber = tmp;
        }
    }

}
