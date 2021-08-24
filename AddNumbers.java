import java.util.Scanner;
public class AddNumbers{
    public static int addNumbers(int a, int b){
        int c = a+b;
        return c;
    }
    public static void main(String[] args){
        int a, b;
        Scanner scan = new Scanner(System.in);
        a = scan.nextInt();
        b = scan.nextInt();
        AddNumbers addObj = new AddNumbers();
        int c = AddNumbers.addNumbers(a, b);
        System.out.println(c);
    }
}