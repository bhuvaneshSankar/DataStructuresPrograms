public class MergeSort {
    public static void merge(int[] arr, int start, int mid, int end){
        int leftArrayLength = mid-start+1;
        int rightArrayLength = end-mid;
        int[] left = new int[leftArrayLength];
        int[] right  = new int[rightArrayLength];
        for(int i=0; i<leftArrayLength; i++){
            left[i] = arr[start+i];
        }
        for(int i=0; i<rightArrayLength; i++){
            right[i] = arr[mid+i+1];
        }
        int i=0, j=0, k=start;
        while(i<leftArrayLength && j<rightArrayLength){
            if(left[i] <= right[j]){
                arr[k++] = left[i++];
            }
            else{
                arr[k++] = right[j++];
            }
        }
        while(i<leftArrayLength){
            arr[k++] = left[i++];
        }
        while(j<rightArrayLength){
            arr[k++] = right[j++];
        }
    }
    public static void sort(int[] arr, int start, int end){
        if(start < end){
            int mid = (end + start)/2;
            sort(arr, start, mid);
            sort(arr, mid+1, end);
            merge(arr, start, mid, end);
        }
    }
    public static void printArr(int[] arr, int length){
        for(int i=0; i<length; i++){
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
    public static void main(String[] args){
    //    int[] arr = {38, 27, 43, 3, 9, 82, 10};
    //    int[] arr = {1, 2, 3, 4, 5, 6, 7};
        int[] arr = {3, 2, 1};
        int length = arr.length;
        sort(arr, 0, length-1);
        printArr(arr, length);
    }
}