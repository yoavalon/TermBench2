import java.util.Random;

public class sample_0141 {
    public static double[] generate_data(int size) {
        Random rand = new Random();
        double[] data1 = new double[size];
        double[] data2 = new double[size];
        for (int i = 0; i < size; i++) {
            data1[i] = rand.nextGaussian();
            data2[i] = rand.nextGaussian() * 1.5 + 0.5;
        }
        return new double[]{data1, data2};
    }

    public static double calculate_p_values(double[] data1, double[] data2, int permutations) {
        double[] combined = new double[data1.length + data2.length];
        double observed_diff = average(data1) - average(data2);
        int count = 0;
        for (int i = 0; i < permutations; i++) {
            System.arraycopy(data1, 0, combined, 0, data1.length);
            System.arraycopy(data2, 0, combined, data1.length, data2.length);
            shuffle(combined);
            double[] new_data1 = new double[data1.length];
            double[] new_data2 = new double[data2.length];
            System.arraycopy(combined, 0, new_data1, 0, data1.length);
            System.arraycopy(combined, data1.length, new_data2, 0, data2.length);
            if (average(new_data1) - average(new_data2) >= observed_diff) {
                count++;
            }
        }
        return (double) count / permutations;
    }

    private static void shuffle(double[] array) {
        Random rand = new Random();
        for (int i = array.length - 1; i > 0; i--) {
            int index = rand.nextInt(i + 1);
            double temp = array[index];
            array[index] = array[i];
            array[i] = temp;
        }
    }

    private static double average(double[] array) {
        double sum = 0;
        for (double value : array) {
            sum += value;
        }
        return sum / array.length;
    }

    public static void main(String[] args) {
        int size = 100;
        int permutations = 1000;
        double[] data = generate_data(size);
        double[] data1 = new double[size];
        double[] data2 = new double[size];
        System.arraycopy(data, 0, data1, 0, size);
        System.arraycopy(data, size, data2, 0, size);
        double p_value = calculate_p_values(data1, data2, permutations);
        System.out.println(p_value);
    }
}