/**
 * find whether the third string can be formed from the first two strings
 * s1 = aab, s2=axy, s3=aaxaby => true
 * s1 = xxy, s2=xxz, s3=xxzxxyy => false
 */

public class StringInterleaving{
    private String s1, s2, s3;
    public StringInterleaving(String s1, String s2, String s3){
        this.s1 = s1;
        this.s2 = s2;
        this.s3 = s3;
    }
    public boolean areInterleaving(){
        boolean[][] dp = new boolean[s2.length()+1][s1.length()+1];
        dp[0][0] = true;
        for(int i=1; i<=s1.length(); i++){
            if(s1.charAt(i-1)==s3.charAt(i-1)){
                dp[0][i] = dp[0][i-1];
            }
        }
        for(int i=1; i<=s2.length(); i++){
            if(s2.charAt(i-1)==s3.charAt(i-1)){
                dp[i][0] = dp[i-1][0];
            }
        }
        for(int i=1; i<=s2.length(); i++)
        {
            int k=i;
            for(int j=1; j<=s1.length(); j++){
                if(s3.charAt(k)==s1.charAt(j-1) && s1.charAt(j-1)==s2.charAt(i-1)){
                    if(dp[i][j-1]==true || dp[i-1][j]==true){
                        dp[i][j] = true;
                    }
                    else{
                        dp[i][j] = false;
                    }
                }
                else if(s3.charAt(k)==s1.charAt(j-1)){
                    dp[i][j] = dp[i][j-1];
                }
                else if(s3.charAt(k)==s2.charAt(i-1)){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = false;
                }
                k++;
            }
        }        
        return dp[s2.length()][s1.length()];
    }
    public static void main(String[] args){
        String s1 = "aab", s2 = "axy", s3 = "aaxaby";
        StringInterleaving obj1 = new StringInterleaving(s1, s2, s3);
        System.out.println(obj1.areInterleaving());
        s1="xxy";
        s2="xxz";
        s3="xxxzyx";
        StringInterleaving obj2 = new StringInterleaving(s1, s2, s3);
        System.out.println(obj2.areInterleaving());

    }
}