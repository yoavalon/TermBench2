import java.util.ArrayList;
import java.util.List;

public class sample_2237 {
    static List<Object> track_sequence(List<Object> seq, int precision) {
        List<Object> result = new ArrayList<>();
        for (Object item : seq) {
            if (item instanceof Double) {
                item = Math.round((Double) item * Math.pow(10, precision)) / Math.pow(10, precision);
            }
            result.add(item);
        }
        return result;
    }

    static void process_data(List<Object> data) {
        int precision = 5;
        while (true) {
            data = track_sequence(data, precision);
            precision -= 1;
            if (precision < 0) {
                precision = 5;
            }
        }
    }

    public static void main(String[] args) {
        List<Object> initial_data = new ArrayList<>();
        initial_data.add(3.1415926535);
        initial_data.add(2.7182818284);
        initial_data.add(1.6180339887);
        process_data(initial_data);
    }
}