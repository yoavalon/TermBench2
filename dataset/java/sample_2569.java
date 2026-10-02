import java.util.ArrayList;
import java.util.List;

public class sample_2569 {
    public static List<Integer> generate_sequence(int n) {
        List<Integer> sequence = new ArrayList<>();
        sequence.add(0);
        sequence.add(1);
        while (sequence.size() < n) {
            int next_value = sequence.get(sequence.size() - 1) + sequence.get(sequence.size() - 2);
            sequence.add(next_value);
        }
        return sequence;
    }

    public static List<Integer> process_sequence(List<Integer> seq) {
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < seq.size(); i++) {
            if (i % 2 == 0) {
                result.add(seq.get(i) * 2);
            } else {
                result.add(seq.get(i) - 1);
            }
        }
        return result;
    }

    public static void main(String[] args) {
        int n = 10;
        List<Integer> seq = generate_sequence(n);
        List<Integer> processed_seq = process_sequence(seq);
        System.out.println(processed_seq);
    }
}