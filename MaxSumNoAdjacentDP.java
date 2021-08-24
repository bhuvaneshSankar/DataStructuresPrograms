// compute the maximum sum from an array such that no two elements are adjacent using dynamic programming
import java.util.*;
import java.lang.*;
import java.io.*;
class MaxSumNoAdjacentDP{
    public static int computeMax(int[] arr, int n, int[] flag){
        if(n==1)                    //if the array has only one element then that element should be the max
            return arr[0];
        else if(n==2){              //if the array has two elements then return the greater of two
            if(arr[0]>arr[1])
                return arr[0];
            else
                return arr[1];
        }
        int max=-1;                 //declaring the max value to be -1 
        flag[n-1] = arr[n-1];
        if(arr[n-1]>max)
            max = arr[n-1];
        flag[n-2] = arr[n-2];
        if(arr[n-2]>max)
            max = arr[n-2];
        flag[n-3] = arr[n-3] + arr[n-1];                //if there are three elements in the array then maxvalue at 0th index is arr[0] + arr[2]
        if(arr[n-3]>max)    
            max = arr[n-3];
        if(arr[n-1] + arr[n-3] > max)
            max = arr[n-1] + arr[n-3];
        for(int i=n-4; i>=0; i--){
            int n1 = arr[i] + flag[i+2];                //add current and current+2 
            int n2 = arr[i] + flag[i+3];                //add current and current+3    
            if(n1>max)          
                max = n1;
            if(n2>max)
                max=n2;
            if(n1>n2){
                flag[i] = n1;
            }
            else
                flag[i] = n2;
        }
        return max;                                     //return the max value
    }
	public static void main (String[] args)
	 {
	    Scanner scan = new Scanner(System.in);
	    int t = scan.nextInt();
	    while(t>0){
	        --t;
	        int n = scan.nextInt();
	        int[] arr = new int[n];
	        int[] flag = new int[n];
	        for(int i=0; i<n; i++){
	            arr[i] = scan.nextInt();
	            flag[i]=-1;
	        }
	        int max = computeMax(arr, n, flag);
	        System.out.println(max);
	    }
	 }
}
//10, 20, 15, 1, 9, 12, 5