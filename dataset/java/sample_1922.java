import java.util.Arrays;

public class sample_1922 {
    public static double[] simulate_temperature_change(double initial_temp, double rate, int steps) {
        double[] data = new double[steps];
        for (int i = 0; i < steps; i++) {
            data[i] = initial_temp + i * rate;
        }
        return data;
    }

    public static int[] analyze_data(double[] data, double threshold) {
        int count = 0;
        for (double value : data) {
            if (value > threshold) {
                count++;
            }
        }
        int[] indices = new int[count];
        int index = 0;
        for (int i = 0; i < data.length; i++) {
            if (data[i] > threshold) {
                indices[index++] = i;
            }
        }
        return indices;
    }

    public static void main(String[] args) {
        double initial_temp = 300.0;
        double rate = 0.1;
        int steps = 1000;
        double threshold = 350.0;
        double[] data = simulate_temperature_change(initial_temp, rate, steps);
        int[] indices = analyze_data(data, threshold);
        System.out.println(Arrays.toString(indices));
    }
}