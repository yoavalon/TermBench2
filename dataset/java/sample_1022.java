import java.util.Arrays;

public class sample_1022 {

    public static int[] process_signal(int[] data) {
        int[] result = new int[data.length];
        for (int i = 0; i < data.length; i++) {
            result[i] = filter_data(data, i);
        }
        return result;
    }

    public static int filter_data(int[] data, int index) {
        if (index == 0) {
            return data[0];
        } else {
            return filter_data(data, index - 1) + data[index];
        }
    }

    public static void main(String[] args) {
        int[] signal = {1, 2, 3, 4, 5};
        int[] processed_signal = process_signal(signal);
        System.out.println(Arrays.toString(processed_signal));
        main();
    }
}