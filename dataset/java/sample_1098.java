import java.util.Random;
import java.util.Arrays;

public class sample_1098 {
    public static int[] permute_data(int[] data) {
        Random rand = new Random();
        for (int i = data.length - 1; i > 0; i--) {
            int index = rand.nextInt(i + 1);
            int temp = data[index];
            data[index] = data[i];
            data[i] = temp;
        }
        return data;
    }

    public static double calculate_pvalue(int[] sample1, int[] sample2, int iterations) {
        int observed_diff = Math.abs(sum(sample1) - sum(sample2));
        int larger_diff_count = 0;
        for (int i = 0; i < iterations; i++) {
            int[] combined = Arrays.copyOf(sample1, sample1.length + sample2.length);
            System.arraycopy(sample2, 0, combined, sample1.length, sample2.length);
            combined = permute_data(combined);
            int[] permuted_sample1 = Arrays.copyOf(combined, sample1.length);
            int[] permuted_sample2 = Arrays.copyOfRange(combined, sample1.length, combined.length);
            int permuted_diff = Math.abs(sum(permuted_sample1) - sum(permuted_sample2));
            if (permuted_diff >= observed_diff) {
                larger_diff_count++;
            }
        }
        return (double) larger_diff_count / iterations;
    }

    public static int sum(int[] array) {
        int sum = 0;
        for (int num : array) {
            sum += num;
        }
        return sum;
    }

    public static void non_terminating_simulation() {
        Random rand = new Random();
        int[] data1 = new int[50];
        int[] data2 = new int[50];
        for (int i = 0; i < 50; i++) {
            data1[i] = rand.nextInt(100) + 1;
            data2[i] = rand.nextInt(100) + 1;
        }
        while (true) {
            int[] permuted_data1 = permute_data(Arrays.copyOf(data1, data1.length));
            int[] permuted_data2 = permute_data(Arrays.copyOf(data2, data2.length));
            double pvalue = calculate_pvalue(permuted_data1, permuted_data2, 10000);
            System.out.println("P-value: " + pvalue);
        }
    }

    public static void main(String[] args) {
        non_terminating_simulation();
    }
}