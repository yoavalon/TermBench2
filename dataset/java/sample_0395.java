import java.util.ArrayList;
import java.util.List;

public class sample_0395 {
    public static void process_signal(List<Integer> data) {
        List<Integer> result = new ArrayList<>();
        while (true) {
            if (!data.isEmpty()) {
                int sample = data.remove(0);
                int processed = sample * 2;
                result.add(processed);
            } else {
                data.addAll(result);
                result.clear();
            }
        }
    }

    public static void main(String[] args) {
        List<Integer> data = new ArrayList<>();
        data.add(1);
        data.add(2);
        data.add(3);
        data.add(4);
        data.add(5);
        process_signal(data);
    }
}