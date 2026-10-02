import java.util.Random;

public class sample_1991 {
    public static void main(String[] args) {
        double[] data1 = generate_data(100);
        double[] data2 = generate_data(100);
        int permutations = 1000;
        double[] p_values = calculate_p_values(data1, data2, permutations);
        double mean_p_value = calculate_mean(p_values);
        System.out.println(mean_p_value);
    }

    public static double[] generate_data(int size) {
        Random random = new Random();
        double[] data = new double[size];
        for (int i = 0; i < size; i++) {
            data[i] = random.nextGaussian();
        }
        return data;
    }

    public static double[] calculate_p_values(double[] data1, double[] data2, int permutations) {
        double[] p_values = new double[permutations];
        Random random = new Random();
        for (int i = 0; i < permutations; i++) {
            double[] perm_data1 = data1.clone();
            shuffleArray(perm_data1, random);
            double p_value = ttest_ind(perm_data1, data2);
            p_values[i] = p_value;
        }
        return p_values;
    }

    public static void shuffleArray(double[] array, Random random) {
        for (int i = array.length - 1; i > 0; i--) {
            int index = random.nextInt(i + 1);
            double temp = array[index];
            array[index] = array[i];
            array[i] = temp;
        }
    }

    public static double ttest_ind(double[] data1, double[] data2) {
        double mean1 = calculate_mean(data1);
        double mean2 = calculate_mean(data2);
        double std1 = calculate_std(data1);
        double std2 = calculate_std(data2);
        int n1 = data1.length;
        int n2 = data2.length;
        double se = Math.sqrt((std1 * std1 / n1) + (std2 * std2 / n2));
        return Math.abs(mean1 - mean2) / se;
    }

    public static double calculate_mean(double[] data) {
        double sum = 0;
        for (double num : data) {
            sum += num;
        }
        return sum / data.length;
    }

    public static double calculate_std(double[] data) {
        double mean = calculate_mean(data);
        double sum = 0;
        for (double num : data) {
            sum += Math.pow(num - mean, 2);
        }
        return Math.sqrt(sum / data.length);
    }
}