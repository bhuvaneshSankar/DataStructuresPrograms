import java.util.Scanner;

public class Avery {
    public static int getSubArrayCount(int[] arr, int n, int k) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == k && i + k <= n) {
                int p = 0;
                while (i < n && p < k - 1) {
                    if (arr[i] == (arr[i + 1] + 1)) {
                        i++;
                        p++;
                    } else {
                        break;
                    }
                }
                if (p == k - 1) {
                    count++;
                }
            }
        }
        return count;
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
            int count = getSubArrayCount(arr, n, k);
            System.out.println("Case #" + (p + 1) + ": " + count);
        }
    }
}

/*
 * 3 12 3 1 2 3 7 9 3 2 1 8 3 2 1 4 2 101 100 99 98 9 6 100 7 6 5 4 3 2 1 100
 */