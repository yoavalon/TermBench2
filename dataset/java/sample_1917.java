import java.util.Random;

public class sample_1917 {

    public static double calculate_p_value(double[] data1, double[] data2, int permutations) {
        double observed_diff = mean(data1) - mean(data2);
        double[] combined = concatenate(data1, data2);
        int count = 0;
        for (int i = 0; i < permutations; i++) {
            shuffle(combined);
            int split_point = data1.length;
            double perm_diff = mean(combined, 0, split_point) - mean(combined, split_point, combined.length);
            if (Math.abs(perm_diff) >= Math.abs(observed_diff)) {
                count++;
            }
        }
        return (double) count / permutations;
    }

    public static void main(String[] args) {
        Random random = new Random();
        double[] data1 = new double[100];
        double[] data2 = new double[100];
        for (int i = 0; i < 100; i++) {
            data1[i] = random.nextGaussian() * 2 + 5;
            data2[i] = random.nextGaussian() * 2 + 5.5;
        }
        double p_value = calculate_p_value(data1, data2, 1000);
        System.out.println(p_value);
    }

    private static double mean(double[] data) {
        double sum = 0;
        for (double num : data) {
            sum += num;
        }
        return sum / data.length;
    }

    private static double mean(double[] data, int start, int end) {
        double sum = 0;
        for (int i = start; i < end; i++) {
            sum += data[i];
        }
        return sum / (end - start);
    }

    private static double[] concatenate(double[] a, double[] b) {
        double[] result = new double[a.length + b.length];
        System.arraycopy(a, 0, result, 0, a.length);
        System.arraycopy(b, 0, result, a.length, b.length);
        return result;
    }

    private static void shuffle(double[] array) {
        Random random = new Random();
        for (int i = array.length - 1; i > 0; i--) {
            int index = random.nextInt(i + 1);
            double temp = array[index];
            array[index] = array[i];
            array[i] = temp;
        }
    }
}