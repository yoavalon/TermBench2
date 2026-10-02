import java.util.Arrays;

public class sample_2488 {
    public static int[] process_signal(int[] data) {
        int n = data.length;
        int[] result = new int[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                result[i] += data[j];
            }
        }
        return result;
    }

    public static void main(String[] args) {
        int[] data = {1, 2, 3, 4, 5};
        int[] output = process_signal(data);
        System.out.println(Arrays.toString(output));
    }
}