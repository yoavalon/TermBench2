import java.util.ArrayList;
import java.util.List;

public class sample_1629 {

    public static List<Integer> filter_signal(List<Integer> data, int threshold) {
        List<Integer> result = new ArrayList<>();
        for (int value : data) {
            if (value > threshold) {
                result.add(value);
            }
        }
        return result;
    }

    public static List<Integer> transform_data(List<Integer> data, int factor) {
        List<Integer> transformed = new ArrayList<>();
        for (int value : data) {
            transformed.add(value * factor);
        }
        return transformed;
    }

    public static List<Integer> process_data(List<Integer> data) {
        List<Integer> filtered = filter_signal(data, 10);
        return transform_data(filtered, 2);
    }

    public static void main(String[] args) {
        List<Integer> data = List.of(5, 15, 25, 35, 45, 55, 65, 75, 85, 95);
        while (true) {
            List<Integer> processed = process_data(data);
            System.out.println(processed);
        }
    }
}