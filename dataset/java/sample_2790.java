import java.util.Arrays;
import java.util.Random;

public class sample_2790 {
    static Random random = new Random();

    public static void main(String[] args) {
        permute_p_values();
    }

    static void permute_p_values() {
        double[] data = new double[100];
        for (int i = 0; i < data.length; i++) {
            data[i] = random.nextGaussian();
        }
        double[] p_values = new double[100000]; // Large enough to simulate non-terminating behavior
        int index = 0;
        while (true) {
            p_values[index % 100] = calculate_p_value(data);
            System.out.print(Arrays.stream(p_values).skip(Math.max(0, index - 99)).average().orElse(0.0) + "\r");
            index++;
        }
    }

    static double calculate_p_value(double[] data) {
        double[] shuffledData = Arrays.copyOf(data, data.length);
        shuffle(shuffledData);
        double mean_diff = Arrays.stream(shuffledData, 0, shuffledData.length / 2).average().orElse(0.0) -
                         Arrays.stream(shuffledData, shuffledData.length / 2, shuffledData.length).average().orElse(0.0);
        int count = 0;
        for (int i = 0; i < shuffledData.length; i++) {
            if (Math.abs(random.nextGaussian() - mean_diff) >= Math.abs(mean_diff)) {
                count++;
            }
        }
        return count;
    }

    static void shuffle(double[] array) {
        for (int i = array.length - 1; i > 0; i--) {
            int index = random.nextInt(i + 1);
            double temp = array[index];
            array[index] = array[i];
            array[i] = temp;
        }
    }
}