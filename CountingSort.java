import java.util.Arrays;
public class CountingSort{                                      //O(n+range)
    public static int[] countingSort(int[] arr, int range){     //range is the maximum value in the array
        int[] countArr = new int[range+1];
        int n = arr.length;
        Arrays.fill(countArr, 0);
        for(int i=0; i<n; i++){
            countArr[arr[i]]++;                                 //hashtable approach - store the number of occurences of the value in countArr's corresponding index
        }
        for(int i=1; i<range+1; i++){
            countArr[i] = countArr[i-1] + countArr[i];          //sum up and store the values in the indexes that denotes that if there is a value x, then there are x elements or occurrences including that index in the array before it
        }
        int[] sortedArr = new int[n];
        for(int i=n-1; i>=0; i--){
            int val = arr[i];
            int pos = countArr[val]-1;                          //pos gives the maximum(correct) index in which the value could occur
            countArr[val] -= 1;                                 //it will be helpful if there are multiple same values - to place them        
            sortedArr[pos] = val;
        }   
        return sortedArr;
    }
    public static char[] countingSort(char[] arr, int range){     //range is the maximum value in the array
        int[] countArr = new int[range+1];
        int n = arr.length;
        Arrays.fill(countArr, 0);
        for(int i=0; i<n; i++){
            countArr[arr[i]]++;                                 //hashtable approach - store the number of occurences of the value in countArr's corresponding index
        }
        for(int i=1; i<range+1; i++){
            countArr[i] = countArr[i-1] + countArr[i];          //sum up and store the values in the indexes that denotes that if there is a value x, then there are x elements or occurrences including that index in the array before it
        }
        char[] sortedArr = new char[n];
        for(int i=n-1; i>=0; i--){
            char val = arr[i];
            int pos = countArr[val]-1;                          //pos gives the maximum(correct) index in which the value could occur
            countArr[val] -= 1;                                 //it will be helpful if there are multiple same values - to place them        
            sortedArr[pos] = val;
        }   
        return sortedArr;
    }
    public static void printArr(int[] arr){
        for(int i=0; i<arr.length; i++)
            System.out.print(arr[i]+" ");
        System.out.println();
    }
    public static void printArr(char[] arr){
        for(int i=0; i<arr.length; i++)
            System.out.print(arr[i]+" ");
        System.out.println();
    }
    public static void main(String[] args){
    //    int[] arr = {1, 4, 1, 2, 7, 5, 2};
    //    int range = 7;
    //    int[] arr = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    //    int range = 9;
    //    int[] sortedArr = countingSort(arr, range);
        String str = "geeksforgeeks";
        char[] arr = str.toCharArray();
        int range = 255;
        char[] sortedArr = countingSort(arr, range);
        printArr(sortedArr);
    }
}