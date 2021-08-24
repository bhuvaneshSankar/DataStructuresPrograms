import java.util.*;
public class SmallestWindowContainingCharsOfAnotherString{
    int start=0, end=0;
    boolean reachedEnd=false, hasWindow=false;
   public void hashString(String s, int[] a){
       for(int i=0; i<s.length(); i++){
           char ch = s.charAt(i);
           int pos = ch-'a';
           a[pos] += 1;
       }
   }
   public void incrementHash(int[] a, char ch){
       int pos = ch-'a';
           a[pos] += 1;
   }
   public boolean isEqual(int[] a, int[] b){
       for(int i=0; i<a.length; i++){
           if(a[i]<b[i]){
               return false;
           }
       }
       return true;
   }
   public void computeSmallestWindowUtil(String s1, String s2, int[] h1, int[] h2){
       int pos;
       while(end<s1.length() && !isEqual(h1, h2)){
       //    print(h1);
           pos = s1.charAt(end)-'a';
           if(h2[pos]>0){
               h1[pos]+=1;
           }
           end++;
       }
       if(isEqual(h1, h2)){
           hasWindow=true;
       }
       if(end==s1.length() && !isEqual(h1, h2)){
           reachedEnd=true;
       }
       else{
           end--;
       }
   }
   public void compressWindow(String s1, String s2, int[] h1, int[] h2){
       int pos;
      // System.out.println(start+" "+end);
      // print(h1);
      // print(h2);
       while(start<end && isEqual(h1, h2)){
           pos = s1.charAt(start)-'a';
       //    System.out.println(pos);
           if(h2[pos]>0 && h1[pos]==h2[pos]){
               break;
           }
           if(h2[pos]>0 && h1[pos]>h2[pos]){
               h1[pos]-=1;
               
           }
           start++;            
       }
   }
   public void print(int[] a){
       for(int i=0; i<a.length; i++){
           System.out.print(a[i]+" ");
       }
       System.out.println();
   }
   public String computeSmallestWindow(String s1, String s2, int[] h1, int[] h2){
       
       int pos=s1.charAt(start)-'a';
       while(h2[pos]==0 && start<s1.length()){
           start++;
           pos = s1.charAt(start)-'a';
       }
       end = start+1;
       int minLength = s1.length()+1, minStart=0, minEnd=0;
       pos = s1.charAt(start)-'a';
       if(h2[pos]>0)
           h1[pos] += 1;
       while(reachedEnd==false && (start+s2.length())<s1.length()){
        //   print(h1);
        //   print(h2);
           computeSmallestWindowUtil(s1, s2, h1, h2);
        //   System.out.println("compute "+start+" "+end);
           if(reachedEnd==false){
               compressWindow(s1, s2, h1, h2);
        //       System.out.println("compress "+start+" "+end);
               if(reachedEnd==false){
                   int len = end-start+1;
                   if(len<minLength){
                       minLength=len;
                       minStart=start;
                       minEnd=end;
                   }
               }
               pos = s1.charAt(start)-'a';
               h1[pos] -= 1;
               start++;
               if(end==s1.length()-1){
                   break;
               }
               end++;
               pos = s1.charAt(end)-'a';
           }
           
           
           
       }
     //  System.out.println(minStart+" "+minEnd);
       if(hasWindow==false){
           hasWindow=false;
           reachedEnd=false;
           start=0;
           end=0;
           return "-1";
       }
       hasWindow=false;
           reachedEnd=false;
           start=0;
           end=0;
       return s1.substring(minStart, minEnd+1);
   }
    public static void main(String[] args){
    //    String s1 = "thisisateststring";
    //    String s2 = "tist";
    //    String s1 = "geeksforgeeks";
    //    String s2 = "ork";
    //    String s1 = "timetopractice";
    //    String s2 = "toc";
    //    String s1 = "zoomlazapzo";
    //    String s2 = "oza";
        Scanner scan = new Scanner(System.in);
        String s1 = scan.next();
        String s2 = scan.next();
        int[] h1 = new int[26];
        int[] h2 = new int[26];
        
        SmallestWindowContainingCharsOfAnotherString obj = new SmallestWindowContainingCharsOfAnotherString();
        obj.hashString(s2, h2);
        String s = obj.computeSmallestWindow(s1, s2, h1, h2);
        System.out.println(s);
    }
}