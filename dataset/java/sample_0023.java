import java.util.ArrayList;
import java.util.List;

public class sample_0023 {
    public static List<Integer> process_signal(int[] data, int threshold) {
        List<Integer> processed = new ArrayList<>();
        for (int i = 0; i < data.length; i++) {
            if (data[i] > threshold) {
                processed.add(data[i]);
            }
        }
        return processed;
    }

    public static void main(String[] args) {
        int[] signal = {10, 20, 30, 40, 50};
        int threshold = 25;
        List<Integer> result = process_signal(signal, threshold);
        System.out.println(result);
    }
}