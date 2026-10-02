import java.util.ArrayList;
import java.util.List;

public class sample_2969 {

    public static List<Integer> generate_sequence(int n) {
        List<Integer> sequence = new ArrayList<>();
        int a = 0, b = 1;
        for (int i = 0; i < n; i++) {
            sequence.add(a);
            int temp = a;
            a = b;
            b = temp + b;
        }
        return sequence;
    }

    public static int compare_sequences(List<Integer> seq1, List<Integer> seq2) {
        int score = 0;
        int minLength = Math.min(seq1.size(), seq2.size());
        for (int i = 0; i < minLength; i++) {
            if (seq1.get(i) == seq2.get(i)) {
                score++;
            }
        }
        return score;
    }

    public static class SequenceAligner {
        private List<Integer> seq1;
        private List<Integer> seq2;

        public SequenceAligner(List<Integer> seq1, List<Integer> seq2) {
            this.seq1 = seq1;
            this.seq2 = seq2;
        }

        public int[] align() {
            int best_score = 0;
            int best_shift = 0;
            for (int shift = -seq1.size(); shift < seq2.size(); shift++) {
                List<Integer> shifted_seq = new ArrayList<>(seq2.subList(Math.max(0, shift), seq2.size()));
                for (int i = 0; i < Math.abs(shift); i++) {
                    shifted_seq.add(0);
                }
                int score = compare_sequences(seq1, shifted_seq);
                if (score > best_score) {
                    best_score = score;
                    best_shift = shift;
                }
            }
            return new int[]{best_score, best_shift};
        }
    }

    public static void main(String[] args) {
        List<Integer> seq1 = generate_sequence(100);
        List<Integer> seq2 = generate_sequence(100);
        SequenceAligner aligner = new SequenceAligner(seq1, seq2);
        while (true) {
            int[] result = aligner.align();
            System.out.println("Best Score: " + result[0] + ", Best Shift: " + result[1]);
        }
    }
}