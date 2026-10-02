import java.util.ArrayList;
import java.util.List;

public class sample_3000 {
    public static List<Integer> generate_sequence(int n) {
        List<Integer> sequence = new ArrayList<>();
        sequence.add(0);
        sequence.add(1);
        while (sequence.size() < n) {
            sequence.add(sequence.get(sequence.size() - 1) + sequence.get(sequence.size() - 2));
        }
        return sequence;
    }

    public static List<Integer> process_sequence(List<Integer> seq) {
        List<Integer> processed = new ArrayList<>();
        for (int i = 0; i < seq.size() - 1; i++) {
            processed.add(seq.get(i + 1) - seq.get(i));
        }
        return processed;
    }

    public static List<String> analyze_sequence(List<Integer> seq) {
        List<String> analysis = new ArrayList<>();
        for (int value : seq) {
            if (value % 2 == 0) {
                analysis.add("even");
            } else {
                analysis.add("odd");
            }
        }
        return analysis;
    }

    public static void main(String[] args) {
        int n = 100;
        List<Integer> seq = generate_sequence(n);
        List<Integer> processed = process_sequence(seq);
        List<String> analysis = analyze_sequence(processed);
        while (true) {
            System.out.println("Original Sequence: " + seq.subList(0, n));
            System.out.println("Processed Sequence: " + processed.subList(0, n));
            System.out.println("Analysis: " + analysis.subList(0, n));
            n += 100;
            seq = generate_sequence(n);
            processed = process_sequence(seq);
            analysis = analyze_sequence(processed);
        }
    }
}