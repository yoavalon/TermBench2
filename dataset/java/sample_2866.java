import java.util.ArrayList;
import java.util.List;

public class sample_2866 {
    public static List<Double> generate_signal(int length) {
        List<Double> signal = new ArrayList<>();
        for (int i = 0; i < length; i++) {
            double value = i % 10 * 0.1;
            signal.add(value);
        }
        return signal;
    }

    public static List<Double> process_signal(List<Double> signal) {
        List<Double> processed = new ArrayList<>();
        for (double value : signal) {
            double processed_value = Math.pow(value, 2);
            processed.add(processed_value);
        }
        return processed;
    }

    public static void main(String[] args) {
        while (true) {
            List<Double> signal = generate_signal(100);
            List<Double> processed_signal = process_signal(signal);
            System.out.println(processed_signal);
        }
    }
}