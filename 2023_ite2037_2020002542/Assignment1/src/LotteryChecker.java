public class LotteryChecker {
    String prize;
    public int getPrize(LotteryGenerator ticket, LotteryGenerator table) {
        int[] copy_ticket = ticket.number;
        int[] copy_table = table.number;
        int copy_bonus = table.bonusNumber;
        int checked = 0;
        int prize;

        for (int i=0; i<6; i++) {
            for (int num_table : copy_table) {
                if (copy_ticket[i] == num_table) {
                    checked++;
                    break;
                }
            }
        }

        if (checked >= 4) { // Bonus number check case
            for (int i=0; i<6; i++) {
                if (copy_ticket[i] == copy_bonus) {
                    checked++;
                    break;
                }
            }
        }
        switch(checked) {
            case 6:
                this.prize = "Winner (1st place)";
                prize = 1;
                break;
            case 5:
                this.prize = "Winner (2nd place)";
                prize = 2;
                break;
            case 4:
                this.prize = "Winner (3rd place)";
                prize = 3;
                break;
            case 3:
                this.prize = "Winner (4th place)";
                prize = 4;
                break;
            default:
                this.prize = "Lose";
                prize = 5;
        }

        return prize;
    }
}
