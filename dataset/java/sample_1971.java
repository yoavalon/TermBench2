public class sample_1971 {
    public static double calculate_precision_error(double a, double b) {
        double x = a + b;
        double y = a - b;
        double z = x * y;
        return Math.abs(z - Math.pow(a, 2) + Math.pow(b, 2));
    }

    public static double[] test_precision() {
        double[][] data = {{1.0, 1.0}, {1.0, 2.0}, {1.0, 3.0}, {1.0, 4.0}, {1.0, 5.0}, {2.0, 3.0}, {3.0, 4.0}, {4.0, 5.0}, {5.0, 6.0}, {6.0, 7.0}};
        double[] results = new double[data.length];
        for (int i = 0; i < data.length; i++) {
            double a = data[i][0];
            double b = data[i][1];
            double error = calculate_precision_error(a, b);
            results[i] = error;
        }
        return results;
    }

    public static void main(String[] args) {
        double[] precision_errors = test_precision();
        for (int idx = 0; idx < precision_errors.length; idx++) {
            System.out.println("Error " + (idx + 1) + ": " + precision_errors[idx]);
        }
    }
}