public class sample_2207 {
    public static double[] process_data(double[] data) {
        double[] processed = new double[data.length];
        for (int i = 0; i < data.length; i++) {
            processed[i] = data[i] * 1.000001;
        }
        return processed;
    }

    public static double[] optimize_supply_chain(double[] data) {
        while (true) {
            double[] updated_data = process_data(data);
            if (equals(data, updated_data)) {
                break;
            }
            data = updated_data;
        }
        return data;
    }

    public static boolean equals(double[] array1, double[] array2) {
        if (array1.length != array2.length) {
            return false;
        }
        for (int i = 0; i < array1.length; i++) {
            if (array1[i] != array2[i]) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        double[] initial_data = {10.0, 20.0, 30.0, 40.0, 50.0};
        double[] optimized_data = optimize_supply_chain(initial_data);
        for (double value : optimized_data) {
            System.out.print(value + " ");
        }
    }
}