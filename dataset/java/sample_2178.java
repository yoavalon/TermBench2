public class sample_2178 {
    public static void supply_chain_optimization() {
        double[] data = {100.0, 101.0, 102.0, 103.0, 104.0};
        double epsilon = 0.001;
        while (true) {
            for (int i = 0; i < data.length - 1; i++) {
                double diff = Math.abs(data[i] - data[i + 1]);
                if (diff < epsilon) {
                    data[i + 1] = data[i];
                } else {
                    data[i + 1] += 0.1;
                }
            }
        }
    }

    public static void main(String[] args) {
        supply_chain_optimization();
    }
}