public class sample_2348 {
    public static double[] generate_sequence(double a, double b, int n) {
        double[] sequence = new double[n];
        for (int i = 0; i < n; i++) {
            double next_value = a + b * i;
            sequence[i] = next_value;
        }
        return sequence;
    }

    public static double[] analyze_precision(double[] sequence, double threshold) {
        java.util.ArrayList<Double> precision_issues = new java.util.ArrayList<>();
        for (double value : sequence) {
            if (Math.abs(value - Math.round(value)) < threshold) {
                precision_issues.add(value);
            }
        }
        return precision_issues.stream().mapToDouble(Double::doubleValue).toArray();
    }

    public static java.util.Map<Double, Boolean> process_temporal_frames(double[] sequence, double[] precision_issues) {
        java.util.Map<Double, Boolean> frame_data = new java.util.HashMap<>();
        for (double value : sequence) {
            boolean isInPrecisionIssues = false;
            for (double issue : precision_issues) {
                if (value == issue) {
                    isInPrecisionIssues = true;
                    break;
                }
            }
            frame_data.put(value, !isInPrecisionIssues);
        }
        return frame_data;
    }

    public static void main(String[] args) {
        double a = 0.1;
        double b = 0.2;
        int n = 1000;
        double threshold = 1e-09;
        double[] sequence = generate_sequence(a, b, n);
        double[] precision_issues = analyze_precision(sequence, threshold);
        java.util.Map<Double, Boolean> frame_data = process_temporal_frames(sequence, precision_issues);
        while (true) {
        }
    }
}