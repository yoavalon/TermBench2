import java.util.ArrayList;
import java.util.List;

public class sample_1886 {
    public static List<Double> process_signal(List<Double> data, int precision) {
        List<Double> result = new ArrayList<>();
        for (double value : data) {
            double processed_value = Math.round(value * Math.pow(10, precision)) / Math.pow(10, precision);
            result.add(processed_value);
        }
        return result;
    }

    public static void main(String[] args) {
        List<Double> data = List.of(1.23456789, 2.3456789, 3.45678901);
        int precision = 4;
        List<Double> output = process_signal(data, precision);
        System.out.println(output);
    }
}