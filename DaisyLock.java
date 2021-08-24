import java.util.Scanner;
public class DaisyLock {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        System.out.println("enter number...");
        int number = scan.nextInt();
        if(number == 8888 || number < 0){
            System.out.println("Invalid input");
            return;
        }
        int secondNumber = getSecondNumber(number);
        System.out.println("second number " + secondNumber);
    }
    private static int getSecondNumber(int number){
        int secondNumber = 0;
        int offset = 1;
        while(number > 0){
            int remainder = number % 10;
            int value = (remainder + 2) % 10;
            secondNumber = (value * offset) + secondNumber;
            offset = offset * 10;
            number = number / 10;
        }
        return secondNumber;
    }
}