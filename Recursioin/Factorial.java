import java.util.Scanner;
class Factorial {
    
    public static int factorial(int n) {
        if (n == 0) return 1;  // Base case: factorial of 0 is 1
        return n * factorial(n - 1);  // Recursive case: n * factorial of (n-1)
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Input number
        System.out.println("Factorial is: " + factorial(n));
        scanner.close();  // Close scanner
    }
}
