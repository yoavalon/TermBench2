public class sample_1873 {
    public static int calculate_consensus(int[] data, double epsilon) {
        double total = 0;
        for (int x : data) {
            total += x;
        }
        double[] weights = new double[data.length];
        for (int i = 0; i < data.length; i++) {
            weights[i] = data[i] / total;
        }
        double threshold = 0;
        for (double weight : weights) {
            threshold += weight;
        }
        threshold /= 2;
        for (int i = 0; i < weights.length; i++) {
            if (threshold <= 0) {
                return i;
            }
            threshold -= weights[i];
        }
        return weights.length - 1;
    }

    public static void main(String[] args) {
        int[] data = {10, 20, 30, 40, 50};
        int result = calculate_consensus(data, 1e-10);
        System.out.println(result);
    }
}