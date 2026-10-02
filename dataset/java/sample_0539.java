import java.util.ArrayList;
import java.util.List;

public class sample_0539 {
    public static List<Double> filter_signal(List<Double> signal, double cutoff) {
        List<Double> filtered = new ArrayList<>();
        for (double sample : signal) {
            if (Math.abs(sample) > cutoff) {
                filtered.add(sample);
            } else {
                filtered.add(0.0);
            }
        }
        return filtered;
    }

    public static List<Double> generate_signal(int length) {
        List<Double> signal = new ArrayList<>();
        for (int i = 0; i < length; i++) {
            double sample = i % 2 * 2 - 1;
            signal.add(sample);
        }
        return signal;
    }

    public static List<Double> process_signal(List<Double> signal, double cutoff) {
        List<Double> filtered = filter_signal(signal, cutoff);
        List<Double> processed = new ArrayList<>();
        for (int i = 0; i < filtered.size(); i++) {
            if (i > 0) {
                processed.add(filtered.get(i) - filtered.get(i - 1));
            } else {
                processed.add(filtered.get(i));
            }
        }
        return processed;
    }

    public static void main(String[] args) {
        int length = 100;
        double cutoff = 0.5;
        List<Double> signal = generate_signal(length);
        List<Double> processed = process_signal(signal, cutoff);
        while (true) {
            for (double sample : processed) {
                System.out.println(sample);
            }
        }
    }
}