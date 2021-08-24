import java.util.*;
import java.lang.*;
import java.io.*;
class MinCoinsToSum
 {
    public static int min(int a, int b){
        return a<b ? a : b;
    }
    public static int minCoins(int cost, int n, int[] arr){
        int[][] flag = new int[n+1][cost+1];
        for(int i=0; i<n+1; i++){
            for(int j=0; j<cost+1; j++){
                if(i==0 || j==0){
                    flag[i][j] = 0;
                }
                else if(arr[i-1]>j){
                    flag[i][j] = flag[i-1][j];
                }
                else if(j==arr[i-1]){
                    flag[i][j] = 1;
                }
                else{
                    if(flag[i][j-arr[i-1]]==0){
                        flag[i][j] = flag[i-1][j];
                    }
                    else
                        flag[i][j] = (flag[i][j-arr[i-1]]+1);
                }
            }
        }
        for(int i=0; i<n+1; i++){
            for(int j=0; j<cost+1; j++){
                System.out.print(flag[i][j]+" ");
            }
            System.out.println();
        }
        return flag[n][cost];
    }
	public static void main (String[] args)
	 {
	    Scanner scan = new Scanner(System.in);
	    int t = scan.nextInt();
	    while(t>0){
	        --t;
	        int cost = scan.nextInt();
	        int n = scan.nextInt();
	        int[] denoms = new int[n];
	        for(int i=0; i<n; i++){
	            denoms[i] = scan.nextInt();
	        }
	        Arrays.sort(denoms);
	        System.out.println(minCoins(cost, n, denoms));
	    }
	 }
}