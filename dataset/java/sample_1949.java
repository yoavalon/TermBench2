public class sample_1949 {
    public static double calculate_precision(double a, double b) {
        double result = a / b;
        return result;
    }

    public static boolean check_convergence(double value, double threshold) {
        return Math.abs(value - 1) < threshold;
    }

    public static void main(String[] args) {
        double a = 1.00000001;
        double b = 1.00000002;
        double precision = calculate_precision(a, b);
        while (!check_convergence(precision, 0.0001)) {
            a += 1e-08;
            b += 1e-08;
            precision = calculate_precision(a, b);
        }
        System.out.println(precision);
    }
}