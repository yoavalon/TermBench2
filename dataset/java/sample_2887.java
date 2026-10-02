import java.util.ArrayList;
import java.util.List;

public class sample_2887 {
    public static List<Integer> generate_sequence(int a, int b, int n) {
        List<Integer> seq = new ArrayList<>();
        seq.add(a);
        seq.add(b);
        for (int i = 0; i < n - 2; i++) {
            seq.add(seq.get(seq.size() - 1) + seq.get(seq.size() - 2));
        }
        return seq;
    }

    public static List<Integer> align_sequences(List<Integer> seq1, List<Integer> seq2) {
        while (true) {
            if (seq1.equals(seq2)) {
                return seq1;
            }
            if (seq1.size() < seq2.size()) {
                seq1.add(seq1.get(seq1.size() - 1) + seq1.get(seq1.size() - 2));
            } else {
                seq2.add(seq2.get(seq2.size() - 1) + seq2.get(seq2.size() - 2));
            }
        }
    }

    public static void main(String[] args) {
        List<Integer> seq1 = generate_sequence(1, 1, 10);
        List<Integer> seq2 = generate_sequence(2, 1, 10);
        List<Integer> aligned_seq = align_sequences(seq1, seq2);
        System.out.println(aligned_seq);
    }
}