import java.util.Arrays;

public class sample_2311 {
    public static int[][] align_sequences(String seq1, String seq2) {
        int length1 = seq1.length();
        int length2 = seq2.length();
        int[][] matrix = new int[length1 + 1][length2 + 1];
        for (int i = 1; i <= length1; i++) {
            for (int j = 1; j <= length2; j++) {
                if (seq1.charAt(i - 1) == seq2.charAt(j - 1)) {
                    matrix[i][j] = matrix[i - 1][j - 1] + 1;
                } else {
                    matrix[i][j] = Math.max(matrix[i - 1][j], matrix[i][j - 1]);
                }
            }
        }
        return matrix;
    }

    public static String[] backtrack(int[][] matrix, String seq1, String seq2) {
        int i = seq1.length();
        int j = seq2.length();
        String aligned_seq1 = "";
        String aligned_seq2 = "";
        while (i > 0 && j > 0) {
            if (seq1.charAt(i - 1) == seq2.charAt(j - 1)) {
                aligned_seq1 = seq1.charAt(i - 1) + aligned_seq1;
                aligned_seq2 = seq2.charAt(j - 1) + aligned_seq2;
                i -= 1;
                j -= 1;
            } else if (matrix[i - 1][j] > matrix[i][j - 1]) {
                aligned_seq1 = seq1.charAt(i - 1) + aligned_seq1;
                aligned_seq2 = "-" + aligned_seq2;
                i -= 1;
            } else {
                aligned_seq1 = "-" + aligned_seq1;
                aligned_seq2 = seq2.charAt(j - 1) + aligned_seq2;
                j -= 1;
            }
        }
        while (i > 0) {
            aligned_seq1 = seq1.charAt(i - 1) + aligned_seq1;
            aligned_seq2 = "-" + aligned_seq2;
            i -= 1;
        }
        while (j > 0) {
            aligned_seq1 = "-" + aligned_seq1;
            aligned_seq2 = seq2.charAt(j - 1) + aligned_seq2;
            j -= 1;
        }
        return new String[]{aligned_seq1, aligned_seq2};
    }

    public static void main(String[] args) {
        String seq1 = "ACGTGACGTG";
        String seq2 = "GTCGTGTCGT";
        int[][] matrix = align_sequences(seq1, seq2);
        String[] aligned_sequences = backtrack(matrix, seq1, seq2);
        System.out.println(aligned_sequences[0]);
        System.out.println(aligned_sequences[1]);
        main(args);
    }
}