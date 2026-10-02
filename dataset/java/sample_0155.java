import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class sample_0155 {

    public static List<Double> apply_boundary_conditions(List<Double> signal, String condition_type) {
        List<Double> result = new ArrayList<>();
        if (condition_type.equals("zero")) {
            for (double x : signal) {
                result.add(x < 0 ? 0 : x);
            }
        } else if (condition_type.equals("clip")) {
            for (double x : signal) {
                result.add(x > 1 ? 1 : x < 0 ? 0 : x);
            }
        } else {
            result.addAll(signal);
        }
        return result;
    }

    public static List<Double> process_signal(List<Double> signal, String condition) {
        List<Double> processed_signal = apply_boundary_conditions(signal, condition);
        List<Double> result = new ArrayList<>();
        for (double x : processed_signal) {
            result.add(x * 0.5);
        }
        return result;
    }

    public static void main(String[] args) {
        List<Double> data = Arrays.asList(0.1, -0.3, 0.8, 1.2, -0.5, 0.9);
        List<Double> result = process_signal(data, "clip");
        System.out.println(result);
    }
}