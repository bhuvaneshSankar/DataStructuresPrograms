import java.util.*;
import java.lang.*;
import java.io.*;
class Boggle
{
     static void copyArr(int[] a1, int[] a2, int len){
         for(int i=0; i<len; i++){
             a1[i] = a2[i];
         }
     }
     static void findWords(String[] dictionary, int len, char[][] boggle, int r, int c){
        TreeSet<String> ts = new TreeSet<>();
        int[] hash = new int[255];
        int[] original = new int[255];
        int[] copy = new int[255];
        Arrays.fill(hash, 0);
        Arrays.fill(copy, 0);
        int i, j;
        for(i=0; i<r; i++){
            for(j=0; j<c; j++){
                hash[boggle[i][j]]++;
            }
        }
        copyArr(original, hash, 255);
        copyArr(copy, hash, 255);
        boolean isPrinted = false;
        for(i=0; i<len; i++){
            String str = dictionary[i];
            boolean flag = true;
            for(j=0; j<str.length(); j++){
                if(copy[str.charAt(j)] == 0){
                    flag=false;
                    break;
                }
                else{
                    copy[str.charAt(j)]--;
                }
            }
            if(flag==false){
                copyArr(hash, original, 255);
                copyArr(copy, original, 255);
            }
            else{
                isPrinted = true;
            //    System.out.print(str+" ");
                ts.add(str);
                copyArr(hash, original, 255);
                copyArr(copy, original, 255);
            }
        }
        if(isPrinted==false){
            System.out.print("-1");
        }
        else{
            
            for(String s: ts){
                System.out.print(s+" ");
            }
        }
    }
	public static void main (String[] args)
	 {
	    Scanner scan = new Scanner(System.in);
	    int t = scan.nextInt();
	    while(t>0){
	        t--;
	        int n = scan.nextInt();
	        String[] dictionary = new String[n];
	        for(int i=0; i<n; i++){
	            dictionary[i] = scan.next();
	        }
	        int r, c;
	        r = scan.nextInt();
	        c = scan.nextInt();
	        char[][] boggle = new char[r][c];
	        for(int i=0; i<r; i++){
	            for(int j=0; j<c; j++){
	                boggle[i][j] = scan.next().charAt(0);
	            }
	        }
	        findWords(dictionary, n, boggle, r, c);
	        System.out.println();
	    }  
	 }
}