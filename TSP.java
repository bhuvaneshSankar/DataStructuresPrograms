import java.util.Set;
import java.util.HashSet;
import java.io.*;
import java.util.*;
public class TSP{
    public static void printArr(int[][] arr, int n){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }
    }
  /*  public static int calcTourUtil(int[][] adj, int numOfVertices){
        Set<Integer> visited = new HashSet<>();
        int start=0, cost=0;
        visited.add(start);
        int current = start;
        return calcTour(adj, numOfVertices, visited, start, current, cost);
        
    } */
    static int tspGrid(int[][] horizontal, int[][] vertical) {
        int rh = horizontal.length;
        int ch = horizontal[0].length;
        int numOfVertices = rh*(ch+1);
        int[][] adjMatrix = new int[numOfVertices][numOfVertices];
        for(int i=0; i<numOfVertices; i++){
            Arrays.fill(adjMatrix[i], -1);
        }
        int curr=0;
        for(int i=0; i<rh; i++){
            for(int j=0; j<ch; j++){
                adjMatrix[curr][curr+1] = horizontal[i][j];
                adjMatrix[curr+1][curr] = horizontal[i][j];
                curr+=1;
            }
            curr+=1;
        }
        int rv = vertical.length;
        int cv = vertical[0].length;
        curr=0;
        for(int i=0; i<rv; i++){
            for(int j=0; j<cv; j++){
                adjMatrix[curr][curr+cv] = vertical[i][j];
                adjMatrix[curr+cv][curr] = vertical[i][j];
                curr+=1;
            }
        }
    //    printArr(adjMatrix, numOfVertices);
        Set<Integer> visited = new HashSet<>();
        int start=0, cost=0;
        visited.add(start);
        int current = start;
        List<Integer> localTspPath = new ArrayList<>();
        localTspPath.add(start);
        return calcTour(adjMatrix, numOfVertices, visited, start, current, cost, localTspPath);
    }
    static boolean foundPath = false;
    static int globalCost = Integer.MAX_VALUE;
    static ArrayList<Integer> tspPath = new ArrayList<>();
    public static int calcTour(int[][] adj, int numOfVertices, Set<Integer> visited, int start, int curr, int cost, List<Integer> localTspPath){
        if(visited.size()==numOfVertices){
            if(adj[curr][start]>=0){
                foundPath=true;
                cost += adj[curr][start];
                if(cost < globalCost){
                    globalCost = cost;
                    copyToTspPath(localTspPath);
                }
                return cost;
            }
            return 0;
        }
        for(int i=0; i<numOfVertices; i++){
            if(!visited.contains(i) && adj[curr][i]!=-1){
                visited.add(i);
                cost += adj[curr][i];
                localTspPath.add(i);
                calcTour(adj, numOfVertices, visited, start, i, cost, localTspPath);
                visited.remove(i);    //backtrack so remove current from set and reduce the current cost and continue traversal and also remove the vertice from the localTspPath 
                cost -= adj[curr][i];
                Integer o = new Integer(i);
                localTspPath.remove(o);        
            }
        }
        return 0;
    }
    public static void copyToTspPath(List<Integer> localPath){
        for(int i=0; i<localPath.size(); i++){
            int vertex = localPath.get(i);
            tspPath.add(i, vertex);
        }
    }
 /*   public static void main(String[] args){
        int numOfVertices=4;
        int[][] adj = {{0,5,6,0}, {5,0,0,7}, {0,0,0,18},  {0,7,8,0}};
        System.out.println(calcTourUtil(adj, numOfVertices));
    } */
    private static final Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) throws IOException {
        int m = scanner.nextInt();
        int n = scanner.nextInt();
        int[][] horizontal = new int[m][n-1];
        for (int horizontalRowItr = 0; horizontalRowItr < m; horizontalRowItr++) {
            for (int horizontalColumnItr = 0; horizontalColumnItr < n-1; horizontalColumnItr++) {
                int horizontalItem = scanner.nextInt();
                horizontal[horizontalRowItr][horizontalColumnItr] = horizontalItem;
            }
        }
        int[][] vertical = new int[m-1][n];
        for (int verticalRowItr = 0; verticalRowItr < m-1; verticalRowItr++) {
            for (int verticalColumnItr = 0; verticalColumnItr < n; verticalColumnItr++) {
                int verticalItem = scanner.nextInt();
                vertical[verticalRowItr][verticalColumnItr] = verticalItem;
            }
        }
        int result = tspGrid(horizontal, vertical);
        if(foundPath==true){
            
            System.out.println("gc "+globalCost);
            System.out.println(tspPath);
        }
        else
            System.out.println("gc 0");
        scanner.close();
    }
}
//output 87
/**
 *
 * see discussion in tsp hackerrank for explanation of this horizontal and vertical arrays
6 6
time taken to move from (i,j) to (i,j+1) and vice versa
9 7 4 6 9
9 4 2 5 3
6 3 1 7 2
8 1 1 4 7
7 1 7 3 9
3 7 1 0 0
time taken to move from (i,j) to (i+1, j) and vice versa
6 4 3 5 7 6
8 1 0 0 7 5
6 8 2 1 0 0
4 7 5 8 1 8
5 0 0 3 2 4
op -> 122
 */