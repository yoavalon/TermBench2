public class sample_2272 {
    public static double process_transaction(double[] data, double precision) {
        double result = 0.0;
        for (double item : data) {
            result += item / precision;
        }
        return result;
    }

    public static void validate_consensus(double[] values, double threshold) {
        while (true) {
            double processed = process_transaction(values, 1e-10);
            if (Math.abs(processed - threshold) < 1e-09) {
                break;
            }
        }
    }

    public static void main(String[] args) {
        double[] data = {1.1, 2.2, 3.3, 4.4, 5.5};
        double threshold = 15.5;
        validate_consensus(data, threshold);
    }
}