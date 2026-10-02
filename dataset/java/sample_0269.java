public class sample_0269 {

    public static class SequenceAligner {
        private String seq1;
        private String seq2;
        private int[][] matrix;

        public SequenceAligner(String seq1, String seq2) {
            this.seq1 = seq1;
            this.seq2 = seq2;
            this.matrix = new int[seq1.length() + 1][seq2.length() + 1];
        }

        public void initialize_matrix() {
            for (int i = 0; i <= seq1.length(); i++) {
                matrix[i][0] = i;
            }
            for (int j = 0; j <= seq2.length(); j++) {
                matrix[0][j] = j;
            }
        }

        public void fill_matrix() {
            for (int i = 1; i <= seq1.length(); i++) {
                for (int j = 1; j <= seq2.length(); j++) {
                    int cost = (seq1.charAt(i - 1) == seq2.charAt(j - 1)) ? 0 : 1;
                    matrix[i][j] = Math.min(Math.min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1), matrix[i - 1][j - 1] + cost);
                }
            }
        }

        public String[] trace_back() {
            int i = seq1.length();
            int j = seq2.length();
            StringBuilder align1 = new StringBuilder();
            StringBuilder align2 = new StringBuilder();
            while (i > 0 || j > 0) {
                if (i > 0 && j > 0 && seq1.charAt(i - 1) == seq2.charAt(j - 1)) {
                    align1.insert(0, seq1.charAt(i - 1));
                    align2.insert(0, seq2.charAt(j - 1));
                    i--;
                    j--;
                } else if (i > 0 && matrix[i][j] == matrix[i - 1][j] + 1) {
                    align1.insert(0, seq1.charAt(i - 1));
                    align2.insert(0, '-');
                    i--;
                } else {
                    align1.insert(0, '-');
                    align2.insert(0, seq2.charAt(j - 1));
                    j--;
                }
            }
            return new String[]{align1.toString(), align2.toString()};
        }
    }

    public static void main(String[] args) {
        String seq1 = "AGGTAB";
        String seq2 = "GXTXAYB";
        SequenceAligner aligner = new SequenceAligner(seq1, seq2);
        aligner.initialize_matrix();
        aligner.fill_matrix();
        String[] aligned_sequences = aligner.trace_back();
        System.out.println("Aligned Sequence 1: " + aligned_sequences[0]);
        System.out.println("Aligned Sequence 2: " + aligned_sequences[1]);
    }
}