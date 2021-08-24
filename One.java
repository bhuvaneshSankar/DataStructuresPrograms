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

public class One {



    // Complete the closestStraightCity function below.
    static int getNearCity(List<Integer> x,List<Integer> y, int currIndex, int currX, int currY){
        int min=100000, minPos=-1;
        int dist=-1;
        for(int i=0; i<x.size(); i++){
            if(i!=currIndex){
                int thisX = x.get(i);
                int thisY = y.get(i);
                System.out.println(thisX+" "+thisY);
                if(thisX==currX){
                    dist = currY - thisY;
                    if(dist<0){
                        dist = -dist;
                    }
                }
                else if(thisY==currY){
                    dist = currX - thisX;
                    if(dist<0)
                        dist = -dist;
                }
                if(dist<min){
                    min=dist;
                    minPos=i;
                }
            }
        }
        return minPos;

    }
    static List<String> closestStraightCity(List<String> c, List<Integer> x, List<Integer> y, List<String> q) {
        ArrayList<String> al = new ArrayList<>();
        for(int i=0; i<q.size(); i++){
            String s = q.get(i);
            int currX = x.get(i);
            int currY = y.get(i);
            int pos = getNearCity(x, y, i, currX, currY);
            System.out.println(pos);
            if(pos==-1){
                al.add("NONE");
            }
            else{
                String city = c.get(i);
                al.add(city);

            }
        }
        return al;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int cCount = Integer.parseInt(bufferedReader.readLine().trim());

        List<String> c = new ArrayList<>();

        IntStream.range(0, cCount).forEach(i -> {
            try {
                c.add(bufferedReader.readLine());
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        int xCount = Integer.parseInt(bufferedReader.readLine().trim());

        List<String> xTemp = new ArrayList<>();

        IntStream.range(0, xCount).forEach(i -> {
            try {
                xTemp.add(bufferedReader.readLine().replaceAll("\\s+$", ""));
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        List<Integer> x = xTemp.stream()
            .map(String::trim)
            .map(Integer::parseInt)
            .collect(toList());

        int yCount = Integer.parseInt(bufferedReader.readLine().trim());

        List<String> yTemp = new ArrayList<>();

        IntStream.range(0, yCount).forEach(i -> {
            try {
                yTemp.add(bufferedReader.readLine().replaceAll("\\s+$", ""));
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        List<Integer> y = yTemp.stream()
            .map(String::trim)
            .map(Integer::parseInt)
            .collect(toList());

        int qCount = Integer.parseInt(bufferedReader.readLine().trim());

        List<String> q = new ArrayList<>();

        IntStream.range(0, qCount).forEach(i -> {
            try {
                q.add(bufferedReader.readLine());
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        List<String> res = closestStraightCity(c, x, y, q);

        bufferedWriter.write(
            res.stream()
                .collect(joining("\n"))
            + "\n"
        );

        bufferedReader.close();
        bufferedWriter.close();
    }
}

/*
    5
green
red
blue
yellow
pink
5
100
200
300
400
500
5
100
200
300
400
500
5
green
red
blue
yellow
pink

(all NONE)



3
london
warsaw
hackerland
3
1
10
20
3
1
10
10
3
london
warsaw
hackerland
Sample Output 1

NONE
hackerland
warsaw
*/