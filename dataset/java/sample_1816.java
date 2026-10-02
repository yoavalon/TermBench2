public class sample_1816 {
    public static double func(double x, int n) {
        if (n == 0) {
            return 1;
        } else {
            return x * func(x, n - 1);
        }
    }

    public static void main(String[] args) {
        double result = func(2.0, 10);
        System.out.println(result);
    }
}