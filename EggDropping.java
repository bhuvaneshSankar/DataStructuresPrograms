import java.util.Scanner;
public class EggDropping{
    public int getMinimumFloor(int k, int n){
        int r = k+1, c = n;
        int[][] array = new int[r][c-1];
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(i==0 || j==0){
                    array[i][j] = 0;
                }
                else if(i==1){
                    array[i][j] = j;
                }
                
            }
        }
    }
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int k, n;
        k = scan.nextInt();
        n = scan.nextInt();
        int minimumFloor = getMinimumFloor(k, n);
        System.out.println(minimumFloor);
        
    }
}