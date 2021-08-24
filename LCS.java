import java.util.Arrays;
public class LCS{                   //s1 = "abcde" s2 = "bade" o/p = "ade" or "bde" length = 3
    private String s1, s2;
    LCS(String s1, String s2){
        this.s1 = s1;
        this.s2 = s2;
    }
    public int max(int a, int b){
        return a > b ? a : b;
    }
    /*
       recursive calculates all the cases t(c) = 2^n which is exponential
       if we reach the end of the string simply return 0 as we cant compare the characters anymore
       if both the characters of the specified index are equal then it contributes length 1 to lcs and recursively calculate for i+1 in s1 and j+1 in s2
       if the characters at specified index are not equal then return the maximum value of this two cases:
            compare substring that starts from the next index in s1 and the rest of the substring including the current index in s2
            compare rest of the substring including the current index in s1 and the substring that starts from the next index in s2
    */
    public int recursive(int i, int j){    
        if(i==s1.length() || j==s2.length()){   
            return 0;
        }
        else if(s1.charAt(i)==s2.charAt(j)){
            return 1+recursive(i+1, j+1);
        }
        else{
            return max(recursive(i+1, j), recursive(i, j+1));
        }
    }
    /*
        no need to recursively calculate for repeated cases so t(c) = o(s1.length() * s2.length())
        calculate the solution in top down fashion(s.length() to 0) store it in an array so that no need to recalcuate the same case if it occurs in further recursions
    */
    public int recursiveMemoiz(int i, int j, int[][] memoiz){
        if(memoiz[i][j]==0){
            if(i==s1.length() || j==s2.length()){
                return 0;
            }
            else if(s1.charAt(i)==s2.charAt(j)){
                memoiz[i][j] = 1+recursive(i+1, j+1);
                return memoiz[i][j];
            }
            else{
                memoiz[i][j] = max(recursive(i+1, j), recursive(i, j+1));
                return memoiz[i][j];
            }
        }
        else{
            return memoiz[i][j];
        }
    }
    public int memoizUtil(){
        int[][] memoiz = new int[s1.length()][s2.length()];
        resetArr(memoiz);
        return recursiveMemoiz(0, 0, memoiz);
    }
    /*
        t(c) = 0(s1.length()*s2.length())
        fill the 0th index with 0 in the table as the base case and it works same as the cases in recursive calculations
    */
    public int dynamicProgramming(){
        int[][] dpTable = new int[s1.length()+1][s2.length()+1];
        for(int i=0; i<s1.length()+1; i++){
            dpTable[i][0] = 0;
        }
        for(int i=1; i<s2.length()+1; i++){
            dpTable[0][i] = 0;
        }
        for(int i=1; i<s1.length()+1; i++){
            for(int j=1; j<s2.length()+1;j++){
                if(s1.charAt(i-1)==s2.charAt(j-1)){
                    dpTable[i][j] = dpTable[i-1][j-1] + 1; 
                }
                else{
                    dpTable[i][j] = max(dpTable[i][j-1], dpTable[i-1][j]);
                }
            }
        }
        return dpTable[s1.length()][s2.length()];
    }
    public void resetArr(int[][] arr){
        for(int i=0; i<arr.length; i++){
            Arrays.fill(arr[i], 0);
        }
    }
    public static void main(String[] args){
        String s1 = "abcde", s2 = "bce";
        LCS obj = new LCS(s1, s2);
        System.out.println("recursive method "+obj.recursive(0,0));
        System.out.println("memoiz method "+obj.memoizUtil());
        System.out.println("dp method "+obj.dynamicProgramming());
        s1 = "bd";
        s2 = "abe";
        LCS obj1 = new LCS("bd", "abe");
        System.out.println("recursive method" + obj1.recursive(0,0));
        System.out.println("memoiz method "+obj1.memoizUtil());
        System.out.println("dp method "+obj1.dynamicProgramming());
    }
}