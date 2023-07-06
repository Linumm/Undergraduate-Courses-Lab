package Week7;
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;
public class practice2 {
    public static void main(String[] args)
    {
        int[][] board = MakeBoard();
        Scanner keyboard = new Scanner(System.in);
        int row1, row2, col1, col2;
        int open_count = 0;

        // Print out initial state
        System.out.println("    1   2   3   4");
        for (int i=0; i<4; i++) {
                System.out.println((i+1)+"   *   *   *   *");
        }

        while (open_count != 8) {
            System.out.print(" Enter Coordinate: ");
            row1 = keyboard.nextInt()-1;
            col1 = keyboard.nextInt()-1;
            row2 = keyboard.nextInt()-1;
            col2 = keyboard.nextInt()-1;

            System.out.println();
            //Check validity first
            if (board[row1][col1] < 9 || board[row2][col2] < 9) {
                System.out.println("Invalid Input: There's an opened card");
                continue;
            }
            //Compare the value
            if (board[row1][col1] == board[row2][col2]) {
                board[row1][col1] -= 10;
                board[row2][col2] -= 10;
                open_count++;
                System.out.println(board[row1][col1]+" == "+board[row2][col2]);
            }
            else if (board[row1][col1] != board[row2][col2])
                System.out.println((board[row1][col1]-10) +" != "+(board[row2][col2]-10));

            //Print out board
            System.out.println("    1   2   3   4");
            for (int i=0; i<4; i++) {
                System.out.print((i+1) + "   ");
                for (int j=0; j<4; j++) {
                    if (board[i][j] > 10) // Unopened cards
                        System.out.print("*   ");
                    else if (board[i][j] < 9)
                        System.out.print(board[i][j] + "   ");
                }
                System.out.println();
            }
            System.out.println();
        }

        System.out.println("All cards are opened! Game over");
    }

    public static int[][] MakeBoard()
    {
        int[][] board = new int[4][4];
        int insert_count = 0; // Insertion count
        int input_int1 = 1;
        int input_int2 = 1;
        Random rnd = new Random();
        int row, col;

        while (insert_count <16) {
            while (true) {
                row = rnd.nextInt(0, 4);
                col = rnd.nextInt(0, 4);
                if (board[row][col] == 0) {
                    if (input_int1 > 8) {
                        board[row][col] = input_int2 + 10;
                        input_int2++;
                    }
                    else {
                        board[row][col] = input_int1 + 10; // +10 means it is not opened by user yet.
                        input_int1++;
                    }
                    break;
                }
            }
            insert_count++;
        }

        return board;
    }
}
