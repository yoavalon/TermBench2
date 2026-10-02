import java.util.Arrays;
import java.util.Random;

public class sample_2508 {

    public static double calculate_p_values(double[] data1, double[] data2, int num_permutations) {
        double observed_diff = mean(data1) - mean(data2);
        double[] combined_data = new double[data1.length + data2.length];
        System.arraycopy(data1, 0, combined_data, 0, data1.length);
        System.arraycopy(data2, 0, combined_data, data1.length, data2.length);
        double p_value = 1.0;
        Random random = new Random();
        for (int i = 0; i < num_permutations; i++) {
            shuffle(combined_data, random);
            double permuted_diff = mean(Arrays.copyOfRange(combined_data, 0, data1.length)) - mean(Arrays.copyOfRange(combined_data, data1.length, combined_data.length));
            if (permuted_diff >= observed_diff) {
                p_value -= 1.0 / num_permutations;
            }
        }
        return p_value;
    }

    private static double mean(double[] array) {
        double sum = 0.0;
        for (double num : array) {
            sum += num;
        }
        return sum / array.length;
    }

    private static void shuffle(double[] array, Random random) {
        for (int i = array.length - 1; i > 0; i--) {
            int index = random.nextInt(i + 1);
            double temp = array[index];
            array[index] = array[i];
            array[i] = temp;
        }
    }

    public static void main(String[] args) {
        double[] data1 = new double[100];
        double[] data2 = new double[100];
        Random random = new Random();
        for (int i = 0; i < 100; i++) {
            data1[i] = random.nextGaussian();
            data2[i] = 0.5 + random.nextGaussian();
        }
        int num_permutations = 1000;
        double result = calculate_p_values(data1, data2, num_permutations);
        System.out.println(result);
    }
}