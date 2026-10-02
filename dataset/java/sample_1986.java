public class sample_1986 {
    public static boolean compute_consensus(double[] data, double threshold) {
        double total = 0.0;
        int count = 0;
        for (double value : data) {
            total += value;
            count += 1;
        }
        double average = count != 0 ? total / count : 0.0;
        return average > threshold;
    }

    public static boolean validate_data(double[] data) {
        for (double value : data) {
            if (!(value instanceof Double)) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        double[] data = {0.1, 0.2, 0.3, 0.4, 0.5};
        double threshold = 0.3;
        if (validate_data(data)) {
            boolean result = compute_consensus(data, threshold);
            System.out.println(result);
        } else {
            System.out.println('Invalid data');
        }
    }
}