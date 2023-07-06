package Week7;
import java.util.Arrays;
import java.util.Scanner;
public class practice1 {
    public static int[][] drawSnail(int n)
    {
        int input_int = 1;
        int direction = 0; // R:0, D:1, L:2, U:3

        int upper_bound = 0;
        int bottom_bound = n-1;
        int left_bound = 0;
        int right_bound = n-1;

        int[][] snail_arr = new int[n][n];

        while (input_int <= n*n) {
            if (direction == 0) { // ->
                for (int i=left_bound; i<=right_bound; i++) {
                    snail_arr[upper_bound][i] = input_int++;
                }
                upper_bound++;
                direction = 1;
            }
            else if (direction == 1) { // down
                for (int i=upper_bound; i<=bottom_bound; i++) {
                    snail_arr[i][right_bound] = input_int++;
                }
                right_bound--;
                direction = 2;
            }
            else if (direction == 2) { // <-
                for (int i=right_bound; i>= left_bound; i--) {
                    snail_arr[bottom_bound][i] = input_int++;
                }
                bottom_bound--;
                direction = 3;
            }
            else if (direction == 3) { // up
                for (int i=bottom_bound; i>= upper_bound; i--) {
                    snail_arr[i][left_bound] = input_int++;
                }
                left_bound++;
                direction = 0;
            }
        }

        return snail_arr;
    }

    public static void main(String[] args)
    {
        Scanner user_input = new Scanner(System.in);
        System.out.println("Enter integer: ");
        int n = user_input.nextInt();
        int[][] snail_arr = drawSnail(n);

        for (int i=0; i<n; i++) {
            for (int j =0; j<n; j++)
                System.out.print(snail_arr[i][j] + " ");
            System.out.println();
        }
    }
}
