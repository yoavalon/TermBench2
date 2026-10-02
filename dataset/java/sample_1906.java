public class sample_1906 {
    public static double calculate_precision(double x, double y) {
        double a = x;
        double b = y;
        for (int i = 0; i < 100; i++) {
            a = (a + b) / 2;
            b = Math.sqrt(a * b);
        }
        return a;
    }

    public static boolean analyze_convergence(double x, double y, double tolerance) {
        double precision = calculate_precision(x, y);
        return Math.abs(x - y) < tolerance;
    }

    public static void main(String[] args) {
        double x = 1.41421356237;
        double y = 1.41421356238;
        double tolerance = 1e-10;
        boolean result = analyze_convergence(x, y, tolerance);
        System.out.println(result);
    }
}