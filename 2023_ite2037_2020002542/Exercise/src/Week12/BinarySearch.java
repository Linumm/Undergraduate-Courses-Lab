package Week12;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class BinarySearch {
    public static void main(String[] args)
    {
        Scanner inputStream = null;
        try
        {
            inputStream = new Scanner(new FileInputStream("C:\\Users\\snowm\\2023_ite2037_2020002542\\Exercise\\src\\Week12\\input.txt"));

        }
        catch (FileNotFoundException e)
        {
            System.out.println("File input.txt was not found");
            System.exit(0);
        }

        // Make target nums set
        int[] target_set = new int[100];
        for (int i=0; i<target_set.length; i++) {
            if (inputStream.hasNextInt())
                target_set[i] = inputStream.nextInt();
        }

        // Push 100,000 nums in num_set
        int[] num_set = new int[100000];
        for (int i=0; i<num_set.length; i++) {
            if (inputStream.hasNextInt())
                num_set[i] = inputStream.nextInt();
        }

        for (int i=0; i<target_set.length; i++) {
            int index = BinarySearchIndex(num_set, 0, num_set.length-1, target_set[i]);
            System.out.print("target: " + target_set[i] + "  index: ");
            if (index == -1) {
                System.out.println("Not found");
            }
            else {
                System.out.println(index);
            }
        }

    }
    public static int BinarySearchIndex(int[] arr, int start, int end, int target)
    {
        int mid = start;
        if (start == end)
            return -1;
        if (start < end) {
            mid += (int)(end-start)/2;
        }
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] > target) {
            return BinarySearchIndex(arr, start, mid-1, target);
        }
        else if (arr[mid] < target) {
            return BinarySearchIndex(arr, mid+1, end, target);
        }

        return -1;
    }
}
