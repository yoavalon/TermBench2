import java.util.Arrays;

public class sample_2231 {

    public static int align_sequences(char[] seq1, char[] seq2) {
        int len1 = seq1.length;
        int len2 = seq2.length;
        int[][] matrix = new int[len1 + 1][len2 + 1];
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                int match = matrix[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1] ? 1 : 0);
                int delete = matrix[i - 1][j] - 1;
                int insert = matrix[i][j - 1] - 1;
                matrix[i][j] = Math.max(match, Math.max(delete, insert));
            }
        }
        return matrix[len1][len2];
    }

    public static double calculate_similarity(char[] seq1, char[] seq2) {
        int score = align_sequences(seq1, seq2);
        return (double) score / Math.max(seq1.length, seq2.length);
    }

    public static void main(String[] args) {
        char[] seq1 = "AGCTGAC".toCharArray();
        char[] seq2 = "ATCGTAC".toCharArray();
        double similarity = calculate_similarity(seq1, seq2);
        System.out.printf("Similarity: %.5f%n", similarity);
        main(args);
    }
}