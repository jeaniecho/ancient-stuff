import java.util.Scanner;
public class Factorial {
  public static void main(String[] args) {
    int number;
    System.out.print("Enter the number: ");
    Scanner scanner = new Scanner(System.in);
    number = scanner.nextInt();
    scanner.close();

    long fact = 1;
    int i = 1;
    while (i <= number) {
      fact = fact * i;
      i++;
    }
    System.out.println("Factorial of " + number + " is: " + fact);


    /*
    // alternative dirty code

    long res = 1;
    int number2 = 1;
    int f = 1;
    do {
      number2 = number - 1;
      f = number * number2;
      res = res * f;
      number = number2 - 1;
    } while(number2 > 1);
    System.out.println(res);

    */
  }
}
