import java.util.Scanner;

public class Candies {
    public static int query(int[] arr, int start, int end) {
        int sum = 0;
        int curr = 1;
        for (int i = start - 1; i <= end - 1; i++, curr++) {
            sum = curr % 2 != 0 ? sum + (arr[i] * curr) : sum - (arr[i] * curr);
        }
        return sum;
    }

    public static void update(int[] arr, int pos, int val) {
        arr[pos - 1] = val;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        for (int p = 0; p < t; p++) {
            int n = scan.nextInt();
            int k = scan.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = scan.nextInt();
            }
            int globalSum = 0;
            for (int i = 0; i < k; i++) {
                char type = scan.next().charAt(0);
                int q1 = scan.nextInt();
                int q2 = scan.nextInt();
                if (type == 'Q') {
                    globalSum += query(arr, q1, q2);
                } else {
                    update(arr, q1, q2);
                }
            }
            System.out.println("Case #" + (p + 1) + ": " + globalSum);
        }
        scan.close();
    }
}
/*
 * 2 5 4 1 3 9 8 2 Q 2 4 Q 5 5 U 2 10 Q 1 2 3 3 4 5 5 U 1 2 U 1 7 Q 1 2
 */