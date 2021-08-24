/**
  * if my target value is 4 and i have coins of values 1,2,3
    i can get 4rupees in 4 ways which is {1,1,1,1}, {1,1,2}, {2,2}, {1,3}
*/
import java.util.Arrays;
import java.util.Scanner;
class CoinChange
 {
    /**
     * construct a flag array which is a dp table and fill it
     * row consists of the available denominations, 0 is included by default
     * column consists of costs, starting from 0 to the target cost
     * if the denomination is greater than the cost then just copy the value in the above row and same column i.e number of ways for the same cost and excluding the current denomination
     * if the cost and the denomination are equal then increment the above row with 1, the above row and same column denotes the number of ways in which we can attain the cost by excluding the currenet denomination, we are adding one to this value as we are now including the current denomination now
     * if not then we add the above row and same col value and the value subtracting the cost with current denomination
     * @param n size of array
     * @param arr array itself
     * @param m target value
     * @return number of ways in which we can form m
     */
    public static int numOfDenoms(int n, int[] arr, int m){
        int[][] flag = new int[n+1][m+1];
        for(int i=0; i<n+1; i++){
            for(int j=0; j<m+1; j++){
                if(i==0 || j==0){
                    flag[i][j] = 0;
                }
                else if(arr[i-1]>j){
                    flag[i][j] = flag[i-1][j];
                }
                else if(arr[i-1]==j){
                    flag[i][j] = flag[i-1][j] + 1;
                }
                else{
                    flag[i][j] = flag[i-1][j] + flag[i][j-arr[i-1]];
                }
            }
        }
        return flag[n][m];
    }
	public static void main (String[] args)
	 {
	    Scanner scan = new Scanner(System.in);
	    int t = scan.nextInt();
	    while(t>0){
	        --t;
	        int n = scan.nextInt();
	        int[] arr = new int[n];
	        for(int i=0; i<n; i++){
	            arr[i] = scan.nextInt();
	        }
	        Arrays.sort(arr);
	        int m = scan.nextInt();
	        System.out.println(numOfDenoms(n, arr, m));
	    }
	 }
}