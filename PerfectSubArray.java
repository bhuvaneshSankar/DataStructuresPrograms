import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class PerfectSubArray {
    public static boolean isPerfectSquare(int value) {
        double num = (double) value;
        double sq = Math.sqrt(num);
        return (sq - Math.floor(sq) == 0);
    }

    public static String binary(int num) {
        int q = -1, r;
        String bin = "";
        while (q != 0) {
            q = num / 2;
            r = num % 2;
            num = num / 2;
            char ch = (char) (r + '0');
            bin = ch + bin;
        }
        return bin;
    }

    public static boolean isAddable(String str) {
        String pattern = "1[0]+1";
        Pattern r = Pattern.compile(pattern);
        Matcher m = r.matcher(str);
        if (m.find()) {
            return false;
        } else {
            return true;
        }
    }

    public static List generateBinaries(int val, int maxLen) {
        List<String> binaries = new ArrayList<>();

        for (int i = 1; i < val; i++) {
            String bin = binary(i);
            int len = bin.length();
            while (len < maxLen) {
                bin = "0" + bin;
                len++;
            }
            if (isAddable(bin)) {
                binaries.add(bin);
            }
        }
        return binaries;
    }

    public static int solve(int[] arr, int n) {
        int count = 0;
        int max = (int) Math.pow((double) 2, (double) n);
        List<String> binaries = generateBinaries(max, n);
        for (int i = 0; i < binaries.size(); i++) {
            String binary = binaries.get(i);
            int sum = 0;
            for (int j = 0; j < binary.length(); j++) {
                char ch = binary.charAt(j);
                if (ch == '1') {
                    sum += arr[j];
                }
            }
            if (isPerfectSquare(sum)) {
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        for (int p = 0; p < t; p++) {
            int n = scan.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = scan.nextInt();
            }
            int count = solve(arr, n);
            System.out.println("Case #" + (p + 1) + ": " + count);
        }
    }
}

/*
 * 3 3 2 2 6 5 30 30 9 1 30 4 4 0 0 16
 */