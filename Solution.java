import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;




public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int N = Integer.parseInt(bufferedReader.readLine().trim());

        int M = Integer.parseInt(bufferedReader.readLine().trim());

        int costsRows = Integer.parseInt(bufferedReader.readLine().trim());
        int costsColumns = Integer.parseInt(bufferedReader.readLine().trim());

        List<List<Integer>> costs = new ArrayList<>();

        IntStream.range(0, costsRows).forEach(i -> {
            try {
                costs.add(
                    Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
                        .map(Integer::parseInt)
                        .collect(toList())
                );
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        int result = Result.minimizeMeetingCost(N, M, costs);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}




class Result {

    /*
     * Complete the 'minimizeMeetingCost' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts following parameters:
     *  1. INTEGER N
     *  2. INTEGER M
     *  3. 2D_INTEGER_ARRAY costs
     */
    static int cost=0;
    public static void getVal(int r, int c, int[][] arr, int[][] visited, int i, int j){
        System.out.println(i+"  "+j);
        if(i>=0 && j>=0 && i<r && j<c && arr[i][j]<0 && visited[i][j]==0){
            System.out.println(i+"  "+j);
            visited[i][j] = 1;
            cost = cost - arr[i][j];
            getVal(r, c, arr, visited, i+1, j);
            getVal(r, c, arr, visited, i-1, j);
            getVal(r, c, arr, visited, i, j+1);
            getVal(r, c, arr, visited, i, j-1);
        }
    }
    public static void print(int[][] a, int r, int c){
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                System.out.print(a[i][j]+" ");
            }
            System.out.println();
        }
    }
    public static int minimizeMeetingCost(int N, int M, List<List<Integer>> costs) {
        
        int[][] arr = new int[N][M];
        System.out.println(N+"  "+M);
        for(int i=0; i<N; i++){
            Object[] objArr = costs.get(i).toArray();
            for(int j=0; j<M; j++){
                arr[i][j] = (int)objArr[j];
        //        System.out.print(arr[i][j]+" ");
            }
        //    System.out.println();
        }
        print(arr, N, M);
        int min = 100000;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(arr[i][j]<0){
                    int[][] visited = new int[N][M];
                    for(int p=0; i<N; i++){
                        for(int q=0; j<M; j++){
                            visited[p][q] = 0;
                        }
                    }
                    System.out.println("here "+i+"  "+j);
                    getVal(N, M, arr, visited, i, j);
                    if(cost<min){
                        min = cost;
                    }
                    cost=0;
                }
            }
        }
        return min;

    }

}

