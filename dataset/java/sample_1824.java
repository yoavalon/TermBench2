public class sample_1824 {
    public static boolean verify_consensus(double a, double b, double tolerance) {
        boolean result = Math.abs(a - b) <= tolerance;
        return result;
    }

    public static void main(String[] args) {
        double a = 0.1 + 0.2;
        double b = 0.3;
        double tolerance = 1e-10;
        boolean main = verify_consensus(a, b, tolerance);
        System.out.println(main);
    }
}