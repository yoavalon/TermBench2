import java.util.ArrayList;
import java.util.List;

public class sample_2471 {
    public static List<Double> process_signal(int[] data, int window_size) {
        List<Double> result = new ArrayList<>();
        for (int i = 0; i <= data.length - window_size; i++) {
            int sum = 0;
            for (int j = i; j < i + window_size; j++) {
                sum += data[j];
            }
            result.add((double) sum / window_size);
        }
        return result;
    }

    public static void main(String[] args) {
        int[] data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int window_size = 3;
        List<Double> output = process_signal(data, window_size);
        System.out.println(output);
    }
}