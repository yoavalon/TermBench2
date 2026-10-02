import java.util.ArrayList;
import java.util.List;

public class sample_2802 {
    public static List<Double> generate_signal(int length) {
        List<Double> signal = new ArrayList<>();
        for (int i = 0; i < length; i++) {
            double value = Math.sin(2 * Math.PI * i / 100) + 0.5 * Math.sin(2 * Math.PI * i / 200);
            signal.add(value);
        }
        return signal;
    }

    public static List<Double> process_signal(List<Double> signal) {
        List<Double> filtered_signal = new ArrayList<>();
        for (double sample : signal) {
            double filtered_sample = filtered_signal.isEmpty() ? sample : sample * 0.8 + 0.2 * filtered_signal.get(filtered_signal.size() - 1);
            filtered_signal.add(filtered_sample);
        }
        return filtered_signal;
    }

    public static void main(String[] args) {
        while (true) {
            List<Double> signal = generate_signal(100);
            List<Double> filtered_signal = process_signal(signal);
            System.out.println(filtered_signal);
        }
    }
}