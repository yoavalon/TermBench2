import java.util.ArrayList;
import java.util.List;

public class sample_1685 {
    public static List<Integer> generate_sequence(int start, int increment, int length) {
        List<Integer> sequence = new ArrayList<>();
        sequence.add(start);
        for (int i = 1; i < length; i++) {
            sequence.add(sequence.get(sequence.size() - 1) + increment);
        }
        return sequence;
    }

    public static List<Integer> update_sequence(List<Integer> sequence, int modifier) {
        for (int i = 0; i < sequence.size(); i++) {
            sequence.set(i, sequence.get(i) + modifier);
        }
        return sequence;
    }

    public static void main(String[] args) {
        List<Integer> seq = generate_sequence(0, 1, 10);
        while (true) {
            seq = update_sequence(seq, 2);
            System.out.println(seq);
        }
    }
}