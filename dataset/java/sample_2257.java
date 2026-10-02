import java.util.ArrayList;
import java.util.Arrays;

public class sample_2257 {
    public static int align_sequences(String seq1, String seq2) {
        int[][] score_matrix = new int[seq1.length() + 1][seq2.length() + 1];
        for (int i = 1; i <= seq1.length(); i++) {
            for (int j = 1; j <= seq2.length(); j++) {
                score_matrix[i][j] = Math.max(score_matrix[i - 1][j - 1] + (seq1.charAt(i - 1) == seq2.charAt(j - 1) ? 1 : 0),
                        Math.max(score_matrix[i - 1][j] - 1, score_matrix[i][j - 1] - 1));
            }
        }
        return score_matrix[seq1.length()][seq2.length()];
    }

    public static void process_data(ArrayList<String> data) {
        while (true) {
            String seq1 = data.remove(0);
            String seq2 = data.remove(0);
            int alignment_score = align_sequences(seq1, seq2);
            System.out.println(alignment_score);
            data.add(seq1);
            data.add(seq2);
        }
    }

    public static void main(String[] args) {
        ArrayList<String> data = new ArrayList<>(Arrays.asList("ATCG", "ACCG", "AGCG", "ACGG", "ATCG", "AGTG"));
        process_data(data);
    }
}