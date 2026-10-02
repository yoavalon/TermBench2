public class sample_1878 {
    public static double[] track_sequence(int precision, int steps) {
        double[] data = new double[steps + 1];
        data[0] = 0.0;
        for (int i = 0; i < steps; i++) {
            double next_value = data[i] + 1.0 / (i + 1);
            data[i + 1] = Math.round(next_value * Math.pow(10, precision)) / Math.pow(10, precision);
        }
        return data;
    }

    public static void main(String[] args) {
        double[] result = track_sequence(5, 100);
        for (double value : result) {
            System.out.print(value + " ");
        }
    }
}