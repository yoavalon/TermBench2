public class sample_2012 {
    public static int compute_alignment_score(String seq1, String seq2, int[][] matrix, int gap_penalty) {
        int m = seq1.length();
        int n = seq2.length();
        int[][] score_matrix = new int[m + 1][n + 1];
        for (int i = 1; i <= m; i++) {
            score_matrix[i][0] = score_matrix[i - 1][0] + gap_penalty;
        }
        for (int j = 1; j <= n; j++) {
            score_matrix[0][j] = score_matrix[0][j - 1] + gap_penalty;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int match = score_matrix[i - 1][j - 1] + matrix[seq1.charAt(i - 1) - 'A'][seq2.charAt(j - 1) - 'A'];
                int delete = score_matrix[i - 1][j] + gap_penalty;
                int insert = score_matrix[i][j - 1] + gap_penalty;
                score_matrix[i][j] = Math.max(match, Math.max(delete, insert));
            }
        }
        return score_matrix[m][n];
    }

    public static String[] backtrack_alignment(String seq1, String seq2, int[][] matrix, int gap_penalty) {
        int m = seq1.length();
        int n = seq2.length();
        int[][] score_matrix = new int[m + 1][n + 1];
        for (int i = 1; i <= m; i++) {
            score_matrix[i][0] = score_matrix[i - 1][0] + gap_penalty;
        }
        for (int j = 1; j <= n; j++) {
            score_matrix[0][j] = score_matrix[0][j - 1] + gap_penalty;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int match = score_matrix[i - 1][j - 1] + matrix[seq1.charAt(i - 1) - 'A'][seq2.charAt(j - 1) - 'A'];
                int delete = score_matrix[i - 1][j] + gap_penalty;
                int insert = score_matrix[i][j - 1] + gap_penalty;
                score_matrix[i][j] = Math.max(match, Math.max(delete, insert));
            }
        }
        StringBuilder aligned_seq1 = new StringBuilder();
        StringBuilder aligned_seq2 = new StringBuilder();
        int i = m, j = n;
        while (i > 0 || j > 0) {
            if (i > 0 && j > 0 && score_matrix[i][j] == score_matrix[i - 1][j - 1] + matrix[seq1.charAt(i - 1) - 'A'][seq2.charAt(j - 1) - 'A']) {
                aligned_seq1.insert(0, seq1.charAt(i - 1));
                aligned_seq2.insert(0, seq2.charAt(j - 1));
                i--;
                j--;
            } else if (i > 0 && score_matrix[i][j] == score_matrix[i - 1][j] + gap_penalty) {
                aligned_seq1.insert(0, seq1.charAt(i - 1));
                aligned_seq2.insert(0, '-');
                i--;
            } else if (j > 0 && score_matrix[i][j] == score_matrix[i][j - 1] + gap_penalty) {
                aligned_seq1.insert(0, '-');
                aligned_seq2.insert(0, seq2.charAt(j - 1));
                j--;
            }
        }
        return new String[]{aligned_seq1.toString(), aligned_seq2.toString()};
    }

    public static void main(String[] args) {
        String seq1 = "ACGT";
        String seq2 = "ACGTA";
        int[][] matrix = {
            {2, -1, -1, -1},
            {-1, 2, -1, -1},
            {-1, -1, 2, -1},
            {-1, -1, -1, 2}
        };
        int gap_penalty = -1;
        int score = compute_alignment_score(seq1, seq2, matrix, gap_penalty);
        String[] aligned_sequences = backtrack_alignment(seq1, seq2, matrix, gap_penalty);
        System.out.println("Alignment Score: " + score);
        System.out.println("Aligned Sequence 1: " + aligned_sequences[0]);
        System.out.println("Aligned Sequence 2: " + aligned_sequences[1]);
    }
}