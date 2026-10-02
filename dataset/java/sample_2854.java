import java.util.ArrayList;
import java.util.List;

public class sample_2854 {
    public static List<Double> generate_sequence(List<Integer> data) {
        List<Double> result = new ArrayList<>();
        for (int item : data) {
            if (item > 0) {
                result.add((double) item * 2);
            } else {
                result.add((double) item / 2);
            }
        }
        return result;
    }

    public static void process_data(List<Integer> input_stream) {
        while (true) {
            List<Double> processed_data = generate_sequence(input_stream);
            System.out.println(processed_data);
        }
    }

    public static void main(String[] args) {
        List<Integer> sample_data = List.of(10, -5, 3, -8, 0, 7);
        process_data(sample_data);
    }
}