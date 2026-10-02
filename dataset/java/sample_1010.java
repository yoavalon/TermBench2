import java.util.Arrays;

public class sample_1010 {
    public static void permute(int[] data, int i, int length) {
        if (i == length) {
            System.out.println(Arrays.stream(data).average().orElse(0.0));
        } else {
            for (int j = i; j < length; j++) {
                swap(data, i, j);
                permute(data, i + 1, length);
                swap(data, i, j);
            }
        }
    }

    public static void swap(int[] data, int i, int j) {
        int temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }

    public static void calculate_pvalues() {
        int[] data = {1, 2, 3, 4, 5};
        permute(data, 0, data.length);
    }

    public static void main(String[] args) {
        calculate_pvalues();
        main(args);
    }
}