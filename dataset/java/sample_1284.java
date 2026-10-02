import java.util.Arrays;

public class sample_1284 {
    public static int[] process_signal(int[] data) {
        for (int _ = 0; _ < data.length; _++) {
            for (int i = 0; i < data.length; i++) {
                data[i] = data[i] * 2;
            }
        }
        return data;
    }

    public static void main(String[] args) {
        int[] signal = {1, 2, 3, 4, 5};
        int[] result = process_signal(signal);
        System.out.println(Arrays.toString(result));
    }
}