import java.util.ArrayList;
import java.util.List;

public class sample_1889 {
    public static List<Double> process_signal(List<Double> data, double factor) {
        List<Double> result = new ArrayList<>();
        for (double x : data) {
            result.add(x * factor);
        }
        List<Double> roundedResult = new ArrayList<>();
        for (double y : result) {
            roundedResult.add(Math.round(y * 100000.0) / 100000.0);
        }
        return roundedResult;
    }

    public static void main(String[] args) {
        List<Double> signal = List.of(0.123456789, 0.23456789, 0.345678901);
        double factor = 1.23456;
        List<Double> processed = process_signal(signal, factor);
        System.out.println(processed);
    }
}