import java.util.*;
import java.lang.*;
import java.io.*;
class PairsWithGivenSum             //number of pairs in the array with given sum
 {
    public static void print(int[] arr){
        for(int i=0; i<arr.length; i++)
            System.out.print(arr[i]+" ");
        System.out.println();
    }
	public static void main (String[] args)
	 {
	    Scanner scan = new Scanner(System.in);
	    int t = 1;
	    while(t>0){
	        --t;
	        int n = scan.nextInt();
	        int[] arr = new int[n];
	        int[] count = new int[101];     //hash table as range for elems is 0 to 100
	        int end = 101;

	        int target = scan.nextInt();
	        Arrays.fill(count, 0);
	        for(int i=0; i<n; i++){
	            arr[i] = scan.nextInt();
	            count[arr[i]]++;
	        }
	        int occur=0;
	        for(int i=0; i<n; i++){
	            int diff = target-arr[i];       //check if the difference in the array 
	            if(diff<0)                      //if the difference is negative it wont be there in the array
	                continue;
	            int no = count[diff];           //get the number of times that number(difference) is preset in the array
                if(no==0)                       //this means that the number is not in the array
                    continue;
	            if(diff==arr[i]){               //case target is 2 and arr[i] =1 here difference == arr[i] (1) at that time we should exclude the count of the current number so --no 
	                --no;
	                occur += no;
	                count[arr[i]]--;            //after incrementing occur we must decrease the count of occurrence of current value in the array by 1 becoz it shouldnt be taken into account further
                    System.out.println("2  "+arr[i]);
	                continue;
	            }
	            else{
	                occur += no;
	                count[arr[i]]--;
                    System.out.println("3  "+arr[i]);
	                continue;
	            }
	            
	        }
	        System.out.println(occur);
	        
	    }
	 }
}

/*
IP 4 6
1  5  7 1
OP 2

IP 4 2
1 1 1 1
OP 6
*/