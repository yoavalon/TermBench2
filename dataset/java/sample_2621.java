import java.util.ArrayList;
import java.util.List;

public class sample_2621 {
    public static List<Integer> generate_sequence(int n, int a0, int r) {
        List<Integer> seq = new ArrayList<>();
        seq.add(a0);
        for (int i = 1; i < n; i++) {
            int next_value = seq.get(seq.size() - 1) * r;
            seq.add(next_value);
        }
        return seq;
    }

    public static List<Integer> filter_sequence(List<Integer> seq, int threshold) {
        List<Integer> filtered = new ArrayList<>();
        for (int value : seq) {
            if (Math.abs(value) > threshold) {
                filtered.add(value);
            }
        }
        return filtered;
    }

    public static List<Double> analyze_signal(List<Integer> seq, int window_size) {
        List<Double> analysis = new ArrayList<>();
        for (int i = 0; i <= seq.size() - window_size; i++) {
            List<Integer> window = seq.subList(i, i + window_size);
            double sum = 0;
            for (int value : window) {
                sum += value;
            }
            double avg = sum / window_size;
            analysis.add(avg);
        }
        return analysis;
    }

    public static void main(String[] args) {
        int n = 10;
        int a0 = 1;
        int r = 2;
        int threshold = 10;
        int window_size = 3;
        List<Integer> sequence = generate_sequence(n, a0, r);
        List<Integer> filtered_sequence = filter_sequence(sequence, threshold);
        List<Double> signal_analysis = analyze_signal(filtered_sequence, window_size);
        System.out.println(sequence);
        System.out.println(filtered_sequence);
        System.out.println(signal_analysis);
    }
}