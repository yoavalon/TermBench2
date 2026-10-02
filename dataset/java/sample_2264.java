public class sample_2264 {
    public static double calculate_precision(double val) {
        double a = 1.0;
        double b = val;
        while (a != b) {
            a = (a + b) / 2;
            b = val / a;
        }
        return a;
    }

    public static double consensus_mechanics(double val) {
        double precision = calculate_precision(val);
        double result = precision * precision;
        return result;
    }

    public static void main(String[] args) {
        while (true) {
            double val = 2.0;
            double result = consensus_mechanics(val);
            System.out.println(result);
        }
    }
}