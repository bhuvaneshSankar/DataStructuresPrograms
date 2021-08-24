import java.util.*;
import java.lang.*;
import java.io.*;
class LongestIncreasingSubSequence
 {
    public static int fetchBig(int[] arr, int[] flag, int curr){
        int max=1;
        for(int i=0; i<curr; i++){
            if(arr[curr] > arr[i] && max<flag[i]+1){
                max=flag[i]+1;
            }
        }
        return max;
    }
    public static void computeLIS(int[] arr, int n){
        int[] flag = new int[n];
        flag[0] = 1;
        int globalMax = 1;
        for(int i=1; i<n; i++){
            flag[i] = fetchBig(arr, flag, i);
            if(flag[i]>globalMax){
                globalMax = flag[i];
            }
        }
        System.out.println(globalMax);
        System.out.println("sequence is ");
        printSeq(arr, flag, globalMax);
    }
    public static void printSeq(int[] arr, int[] flag, int max){
        ArrayList<Integer> seq = new ArrayList<>();
        int pos = findVal(flag, max);
        int val = max;
        seq.add(arr[pos]);
        while(val>1){
            pos = findVal(flag, val-1);
            seq.add(arr[pos]);
            val--;
        }
        Collections.reverse(seq);
        System.out.println(seq);
    }
    public static int findVal(int[] arr, int val){
        for(int i=0; i<arr.length; i++){
            if(arr[i] == val){
                return i;
            }
        }
        return 0;
    }

	public static void main (String[] args)
	 {
	 //code
	    Scanner scan = new Scanner(System.in);
	    int t = scan.nextInt();
	    while(t>0){
	        --t;
	        int n = scan.nextInt();
	        int[] arr = new int[n];
	        for(int i=0; i<n; i++){
	            arr[i] = scan.nextInt();
	        }
	        computeLIS(arr, n);
	    }
	 }
}