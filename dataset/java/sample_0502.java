import java.util.Arrays;

public class sample_0502 {

    static class SequenceAligner {
        String seq1;
        String seq2;
        int match = 1;
        int mismatch = -1;
        int gap = -2;

        SequenceAligner(String seq1, String seq2) {
            this.seq1 = seq1;
            this.seq2 = seq2;
        }

        int score(char a, char b) {
            return (a == b) ? match : mismatch;
        }

        int[][] calculate_scores() {
            int m = seq1.length();
            int n = seq2.length();
            int[][] matrix = new int[m + 1][n + 1];
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    int diagonal = matrix[i - 1][j - 1] + score(seq1.charAt(i - 1), seq2.charAt(j - 1));
                    int up = matrix[i - 1][j] + gap;
                    int left = matrix[i][j - 1] + gap;
                    matrix[i][j] = Math.max(diagonal, Math.max(up, left));
                }
            }
            return matrix;
        }

        String[] trace_back(int[][] matrix) {
            int m = seq1.length();
            int n = seq2.length();
            String aligned_seq1 = "";
            String aligned_seq2 = "";
            while (m > 0 || n > 0) {
                if (m > 0 && n > 0 && (matrix[m][n] == matrix[m - 1][n - 1] + score(seq1.charAt(m - 1), seq2.charAt(n - 1)))) {
                    aligned_seq1 = seq1.charAt(m - 1) + aligned_seq1;
                    aligned_seq2 = seq2.charAt(n - 1) + aligned_seq2;
                    m -= 1;
                    n -= 1;
                } else if (m > 0 && matrix[m][n] == matrix[m - 1][n] + gap) {
                    aligned_seq1 = seq1.charAt(m - 1) + aligned_seq1;
                    aligned_seq2 = '-' + aligned_seq2;
                    m -= 1;
                } else if (n > 0) {
                    aligned_seq1 = '-' + aligned_seq1;
                    aligned_seq2 = seq2.charAt(n - 1) + aligned_seq2;
                    n -= 1;
                }
            }
            return new String[]{aligned_seq1, aligned_seq2};
        }
    }

    public static void main(String[] args) {
        String seq1 = "AGGTAB";
        String seq2 = "GXTXAYB";
        SequenceAligner aligner = new SequenceAligner(seq1, seq2);
        int[][] scores = aligner.calculate_scores();
        String[] aligned = aligner.trace_back(scores);
        System.out.println("Aligned Seq 1: " + aligned[0]);
        System.out.println("Aligned Seq 2: " + aligned[1]);
    }
}