import java.io.*;
import java.util.*;

public class Knapsack {

    public static int calcKnapsack(int[][] arr, int s, int n){
        int[][] dp = new int[n+1][s+1];
        Arrays.fill(dp[0], 0);
        for(int i=1; i<=n; i++){
            dp[i][0] = 0;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=s; j++){
                int weight = arr[i-1][0];
                if(j<weight){
                   dp[i][j] = dp[i-1][j]; 
                }
                else{
                int prev = dp[i-1][j-weight];
                int val = arr[i-1][1] + prev;
                if(val>dp[i-1][j]){
                    dp[i][j] = val;
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
                }
            }
        }
        return dp[n][s];
    }
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        while(t>0){
            --t;
            int s = scan.nextInt();
            int n = scan.nextInt();
            int[][] arr = new int[n][2];
            for(int i=0; i<n; i++){
                arr[i][0] = scan.nextInt();
                arr[i][1] = scan.nextInt();
            }
            int result = calcKnapsack(arr, s, n);
            System.out.println(result);
        }
    }
}