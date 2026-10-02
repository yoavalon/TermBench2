import java.util.Arrays;

public class sample_0681 {
    public static void main(String[] args) {
        int[] data = {10, 20, 30, 40, 50};
        int threshold = 25;
        int[] processed_data = process_signal(data, 0, threshold);
        System.out.println(Arrays.toString(processed_data));
    }

    public static int[] process_signal(int[] data, int index, int threshold) {
        if (index >= data.length) {
            return data;
        }
        if (data[index] > threshold) {
            data[index] = 0;
        }
        return process_signal(data, index + 1, threshold);
    }
}