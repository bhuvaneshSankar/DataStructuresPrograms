import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class SherlockAndCost {

    // Complete the cost function below.
    static int getCost(int[] arr){
        int sum=0;
        for(int i=1; i<arr.length; i++){
            int diff = arr[i] - arr[i-1];
            diff = Math.abs(diff);
            sum += diff;
        }
        return sum;
    }
    static int cost(int[] B) {
        int n = B.length;
        if(n==1){
            return B[0];
        }
        int[] arr = new int[n];
        if(B[0]>B[1]){
        for(int i=0; i<n; i++){
            if(i%2==0){
                arr[i] = B[i];
            }
            else{
                arr[i] = 1;
            }
        }
        }
        else{
            for(int i=0; i<n; i++){
            if(i%2!=0){
                arr[i] = B[i];
            }
            else{
                arr[i] = 1;
            }
        }
        }
        return getCost(arr);

    }

    private static final Scanner scan = new Scanner(System.in);

    public static void copyArr(int[] a1, int[] a2){
        for(int i=0; i<a1.length; i++){
            a1[i] = a2[i];
        }
    }
    public static void printArr(int[] arr){
        for(int i=0; i<arr.length; i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }
    
    public static int left(int[] a){
        int n=a.length;
        int[] arr = new int[a.length];
        copyArr(arr, a);
        for(int i=0; i<n; i+=2){
            arr[i]=1;
        }
        printArr(arr);
        return getCost(arr);
    }
    public static int right(int[] a){
        int n=a.length;
        int[] arr = new int[a.length];
        copyArr(arr, a);
        for(int i=1; i<n; i+=2){
            arr[i]=1;
        }
        printArr(arr);
        return getCost(arr);
    }
    public static int max(int a, int b){
        System.out.println(a+"  "+b);
        return a>b ? a:b;
    }
    public static int myLogic(int[] arr){
        for(int i=1; i<arr.length; i++){
            int[] a = new int[i+1];
            for(int j=0; j<=i; j++){
                a[j] = arr[j];
            }
            int val = max(left(a), right(a));
            System.out.println();
        }
        return max(left(arr), right(arr));
    }
  /*  public static void main(String[] args){
        int t = scan.nextInt();
        for(int i=0; i<t; i++){
            int n = scan.nextInt();
            int[] arr = new int[n];
            for(int j=0; j<n; j++){
                arr[j] = scan.nextInt();
            }
            System.out.println("answer " + myLogic(arr));
        }

        scan.close();
    }  */  
  /*  public static void main(String[] args) throws IOException {
        int t = scan.nextInt();
        for(int i=0; i<t; i++){
            int n = scan.nextInt();
            int[] arr = new int[n];
            for(int j=0; j<n; j++){
                arr[j] = scan.nextInt();
            }
            System.out.println("answer " + cost(arr));
        }

        scan.close();
    }  */
    public static void main(String[] args) {
		int dp[][]=new int[100001][2];
		int N=0;
		Scanner in = new Scanner(System.in);
		String t = in.nextLine();
		for (int a 	= 0; a < Integer.parseInt(t); a++) {
			N=Integer.parseInt(in.nextLine());
			String line[]=in.nextLine().split(" ");
			dp[0][0]=dp[0][1]=0;
			for (int i = 0; i < N-1; i++) {
				dp[i+1][0]=Math.max(dp[i][0], dp[i][1]+Math.abs(Integer.parseInt(line[i])-1));
                dp[i+1][1]=Math.max(dp[i][0]+Math.abs(Integer.parseInt(line[i+1])-1), dp[i][1]+Math.abs(Integer.parseInt(line[i+1])-Integer.parseInt(line[i])));
                System.out.println(dp[i][0]+"  "+dp[i][1] +"\n");
			}
			
			System.out.println(Math.max(dp[N-1][1], dp[N-1][0]));
		}
	}   
}
