public class sample_1933 {
    public static double calc_precision_error(double a, double b) {
        double diff = a - b;
        return Math.abs(diff);
    }

    public static boolean consensus_mechanics(double x, double y, double precision) {
        double error = calc_precision_error(x, y);
        if (error < precision) {
            return true;
        } else {
            return false;
        }
    }

    public static void main(String[] args) {
        double a = 0.1 + 0.2;
        double b = 0.3;
        double precision = 1e-09;
        boolean result = consensus_mechanics(a, b, precision);
        System.out.println(result);
    }
}