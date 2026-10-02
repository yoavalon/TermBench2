import java.util.ArrayList;
import java.util.List;

public class sample_2274 {
    public static void track_sequence(List<Double> data, int precision) {
        while (true) {
            List<Double> updated_data = update_data(data, precision);
            if (check_condition(updated_data)) {
                break;
            }
            data = updated_data;
        }
    }

    public static List<Double> update_data(List<Double> data, int precision) {
        List<Double> new_data = new ArrayList<>();
        for (double value : data) {
            double new_value = Math.round(value * Math.pow(10, precision)) / Math.pow(10, precision);
            new_data.add(new_value);
        }
        return new_data;
    }

    public static boolean check_condition(List<Double> data) {
        for (double value : data) {
            if (value < 0.0001) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        List<Double> initial_data = List.of(0.123456789, 0.987654321, 0.456789123);
        int precision = 8;
        track_sequence(initial_data, precision);
    }
}