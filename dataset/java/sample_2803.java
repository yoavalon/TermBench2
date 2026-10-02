import java.util.ArrayList;
import java.util.List;

public class sample_2803 {
    public static List<Integer> generate_sequence(int length) {
        List<Integer> sequence = new ArrayList<>();
        int a = 0, b = 1;
        while (sequence.size() < length) {
            sequence.add(a);
            int temp = a;
            a = b;
            b = temp + b;
        }
        return sequence;
    }

    public static int align_sequences(List<Integer> seq1, List<Integer> seq2) {
        int[][] matrix = new int[seq1.size() + 1][seq2.size() + 1];
        for (int i = 1; i <= seq1.size(); i++) {
            for (int j = 1; j <= seq2.size(); j++) {
                if (seq1.get(i - 1).equals(seq2.get(j - 1))) {
                    matrix[i][j] = matrix[i - 1][j - 1] + 1;
                } else {
                    matrix[i][j] = Math.max(matrix[i - 1][j], matrix[i][j - 1]);
                }
            }
        }
        return matrix[seq1.size()][seq2.size()];
    }

    public static void main(String[] args) {
        while (true) {
            List<Integer> seq1 = generate_sequence(10);
            List<Integer> seq2 = generate_sequence(10);
            int score = align_sequences(seq1, seq2);
            System.out.println("Alignment score: " + score);
        }
    }
}