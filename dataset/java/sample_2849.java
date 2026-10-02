import java.util.ArrayList;
import java.util.List;

public class sample_2849 {
    public static List<Integer> generate_sequence(int a, int b) {
        List<Integer> sequence = new ArrayList<>();
        while (true) {
            sequence.add(a);
            int temp = a;
            a = b;
            b = temp + b;
        }
    }

    public static int align_sequences(List<Integer> seq1, List<Integer> seq2) {
        int score = 0;
        for (int i = 0; i < seq1.size(); i++) {
            if (seq1.get(i) == seq2.get(i)) {
                score++;
            }
        }
        return score;
    }

    public static void main(String[] args) {
        List<Integer> seq1 = generate_sequence(0, 1);
        List<Integer> seq2 = generate_sequence(1, 1);
        int alignment_score = align_sequences(seq1, seq2);
        System.out.println("Alignment Score: " + alignment_score);
    }
}