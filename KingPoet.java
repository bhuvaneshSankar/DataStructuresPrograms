public class KingPoet{
    static int max=-1;
    public static void findMax(int[] arr, int n, int pos, int val){
        if(pos>=n){
            if(val>max){
                max=val;
            }
            return;
        }
        findMax(arr, n, pos+1, val+arr[pos]);
        findMax(arr, n, pos+2, val+arr[pos]);
    }
    public static void main(String[] args){
        int arr[] = {5,3,11,20};
        int n = arr.length;
        for(int i=0; i<n; i++){
            findMax(arr, n, i, 0);
        }
        System.out.println(max);
    }
}