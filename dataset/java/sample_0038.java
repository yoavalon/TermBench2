public class sample_0038 {
    public static void process_signal(double[] data, double threshold) {
        java.util.ArrayList<Double> processed = new java.util.ArrayList<>();
        for (double x : data) {
            if (Math.abs(x) > threshold) {
                processed.add(x);
            } else {
                break;
            }
        }
        System.out.println(processed);
    }

    public static void main(String[] args) {
        double[] data = {0.1, 0.5, 1.5, 2.5, 0.3, 0.4};
        double threshold = 1.0;
        process_signal(data, threshold);
    }
}