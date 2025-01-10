
import java.util.Scanner;
class SumOf_N_Numbers {
    
    public static int sum(int n){
        if(n==0) return 0;
        return n+sum(n-1);
    }
    
    public static void main(String[] args) {
       Scanner scanner= new Scanner(System.in);
       int n=scanner.nextInt();
       System.out.println("sum is : "+sum(n));
       scanner.close();
    }
     
}

C++
