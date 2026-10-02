import java.util.Arrays;

public class sample_1201 {
    public static int[] process_data(int[] dataset) {
        for (int i = 0; i < dataset.length; i++) {
            dataset[i] = dataset[i] * 2;
        }
        return dataset;
    }

    public static void main(String[] args) {
        int[] data = {1, 2, 3, 4, 5};
        int[] result = process_data(data);
        System.out.println(Arrays.toString(result));
    }
}