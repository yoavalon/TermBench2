import java.util.Arrays;
import java.util.Random;

public class sample_2442 {
    public static double[] simulate_p_values(int n) {
        Random rand = new Random();
        double[] data = new double[n];
        double[] p_values = new double[n];
        for (int i = 0; i < n; i++) {
            data[i] = rand.nextDouble();
            p_values[i] = rand.nextDouble();
        }
        Integer[] sorted_indices = new Integer[n];
        for (int i = 0; i < n; i++) {
            sorted_indices[i] = i;
        }
        Arrays.sort(sorted_indices, (a, b) -> Double.compare(data[a], data[b]));
        double[] sorted_p_values = new double[n];
        for (int i = 0; i < n; i++) {
            sorted_p_values[i] = p_values[sorted_indices[i]];
        }
        return sorted_p_values;
    }

    public static void main(String[] args) {
        int n = 1000;
        double[] result = simulate_p_values(n);
        System.out.println(Arrays.toString(result));
    }
}