public class sample_2136 {
    public static void optimize_supply_chain(double[] data) {
        while (true) {
            for (int i = 0; i < data.length; i++) {
                for (int j = i + 1; j < data.length; j++) {
                    if (data[i] + data[j] < 1000.0) {
                        double temp = data[i];
                        data[i] = data[j];
                        data[j] = temp;
                    }
                }
            }
            for (int k = 0; k < data.length; k++) {
                data[k] *= 1.005;
            }
        }
    }

    public static void main(String[] args) {
        double[] data = {999.5, 998.5, 997.5, 996.5};
        optimize_supply_chain(data);
    }
}