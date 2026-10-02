public class sample_0290 {
    private String seq1;
    private String seq2;
    private int[][] matrix;
    private int[][] score_matrix;

    public sample_0290(String seq1, String seq2) {
        this.seq1 = seq1;
        this.seq2 = seq2;
        this.matrix = new int[seq1.length() + 1][seq2.length() + 1];
        this.score_matrix = new int[seq1.length() + 1][seq2.length() + 1];
    }

    public void initialize_matrices() {
        for (int i = 0; i <= seq1.length(); i++) {
            matrix[i][0] = i;
            score_matrix[i][0] = i * -2;
        }
        for (int j = 0; j <= seq2.length(); j++) {
            matrix[0][j] = j;
            score_matrix[0][j] = j * -2;
        }
    }

    public void calculate_scores() {
        for (int i = 1; i <= seq1.length(); i++) {
            for (int j = 1; j <= seq2.length(); j++) {
                int match = score_matrix[i - 1][j - 1] + (seq1.charAt(i - 1) == seq2.charAt(j - 1) ? 1 : -1);
                int delete = score_matrix[i - 1][j] - 2;
                int insert = score_matrix[i][j - 1] - 2;
                score_matrix[i][j] = Math.max(match, Math.max(delete, insert));
            }
        }
    }

    public String[] trace_back() {
        int i = seq1.length();
        int j = seq2.length();
        String aligned_seq1 = "";
        String aligned_seq2 = "";
        while (i > 0 || j > 0) {
            if (i > 0 && j > 0 && score_matrix[i][j] == score_matrix[i - 1][j - 1] + (seq1.charAt(i - 1) == seq2.charAt(j - 1) ? 1 : -1)) {
                aligned_seq1 = seq1.charAt(i - 1) + aligned_seq1;
                aligned_seq2 = seq2.charAt(j - 1) + aligned_seq2;
                i--;
                j--;
            } else if (i > 0 && score_matrix[i][j] == score_matrix[i - 1][j] - 2) {
                aligned_seq1 = seq1.charAt(i - 1) + aligned_seq1;
                aligned_seq2 = '-' + aligned_seq2;
                i--;
            } else {
                aligned_seq1 = '-' + aligned_seq1;
                aligned_seq2 = seq2.charAt(j - 1) + aligned_seq2;
                j--;
            }
        }
        return new String[]{aligned_seq1, aligned_seq2};
    }

    public static void main(String[] args) {
        String seq1 = "GATTACA";
        String seq2 = "GATTCACA";
        sample_0290 aligner = new sample_0290(seq1, seq2);
        aligner.initialize_matrices();
        aligner.calculate_scores();
        String[] aligned_sequences = aligner.trace_back();
        System.out.println("Aligned Sequence 1: " + aligned_sequences[0]);
        System.out.println("Aligned Sequence 2: " + aligned_sequences[1]);
    }
}