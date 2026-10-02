public class sample_0206 {
    class SequenceAligner {
        String seq1;
        String seq2;
        int[][] matrix;

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

        public void compute_similarity() {
            for (int i = 1; i <= seq1.length(); i++) {
                for (int j = 1; j <= seq2.length(); j++) {
                    int match = matrix[i - 1][j - 1] + (seq1.charAt(i - 1) == seq2.charAt(j - 1) ? 0 : 1);
                    int delete = matrix[i - 1][j] + 1;
                    int insert = matrix[i][j - 1] + 1;
                    matrix[i][j] = Math.min(match, Math.min(delete, insert));
                }
            }
        }

        public String[] trace_back() {
            int i = seq1.length();
            int j = seq2.length();
            StringBuilder aligned_seq1 = new StringBuilder();
            StringBuilder aligned_seq2 = new StringBuilder();
            while (i > 0 || j > 0) {
                if (i > 0 && j > 0 && matrix[i][j] == matrix[i - 1][j - 1] + (seq1.charAt(i - 1) == seq2.charAt(j - 1) ? 0 : 1)) {
                    aligned_seq1.append(seq1.charAt(i - 1));
                    aligned_seq2.append(seq2.charAt(j - 1));
                    i--;
                    j--;
                } else if (i > 0 && matrix[i][j] == matrix[i - 1][j] + 1) {
                    aligned_seq1.append(seq1.charAt(i - 1));
                    aligned_seq2.append('-');
                    i--;
                } else {
                    aligned_seq1.append('-');
                    aligned_seq2.append(seq2.charAt(j - 1));
                    j--;
                }
            }
            return new String[]{aligned_seq1.reverse().toString(), aligned_seq2.reverse().toString()};
        }
    }

    public static void main(String[] args) {
        String seq1 = "AGGTAB";
        String seq2 = "GXTXAYB";
        sample_0206.SequenceAligner aligner = new sample_0206().new SequenceAligner(seq1, seq2);
        aligner.initialize_matrix();
        aligner.compute_similarity();
        String[] aligned_sequences = aligner.trace_back();
        System.out.println("Aligned Sequence 1: " + aligned_sequences[0]);
        System.out.println("Aligned Sequence 2: " + aligned_sequences[1]);
    }
}