public class sample_0224 {

    class SequenceAligner {

        String seq1;
        String seq2;
        int[][] matrix;
        int[][] traceback;

        public SequenceAligner(String seq1, String seq2) {
            this.seq1 = seq1;
            this.seq2 = seq2;
            this.matrix = new int[seq1.length() + 1][seq2.length() + 1];
            this.traceback = new int[seq1.length() + 1][seq2.length() + 1];
        }

        public void fill_matrix() {
            for (int i = 1; i <= seq1.length(); i++) {
                for (int j = 1; j <= seq2.length(); j++) {
                    int match = matrix[i - 1][j - 1] + (seq1.charAt(i - 1) == seq2.charAt(j - 1) ? 1 : -1);
                    int delete = matrix[i - 1][j] - 1;
                    int insert = matrix[i][j - 1] - 1;
                    matrix[i][j] = Math.max(match, Math.max(delete, insert));
                    if (matrix[i][j] == match) {
                        traceback[i][j] = 1;
                    } else if (matrix[i][j] == delete) {
                        traceback[i][j] = 2;
                    } else {
                        traceback[i][j] = 3;
                    }
                }
            }
        }

        public String[] align_sequences() {
            int i = seq1.length();
            int j = seq2.length();
            StringBuilder aligned_seq1 = new StringBuilder();
            StringBuilder aligned_seq2 = new StringBuilder();
            while (i > 0 || j > 0) {
                if (traceback[i][j] == 1) {
                    aligned_seq1.insert(0, seq1.charAt(i - 1));
                    aligned_seq2.insert(0, seq2.charAt(j - 1));
                    i--;
                    j--;
                } else if (traceback[i][j] == 2) {
                    aligned_seq1.insert(0, seq1.charAt(i - 1));
                    aligned_seq2.insert(0, '-');
                    i--;
                } else {
                    aligned_seq1.insert(0, '-');
                    aligned_seq2.insert(0, seq2.charAt(j - 1));
                    j--;
                }
            }
            return new String[]{aligned_seq1.toString(), aligned_seq2.toString()};
        }
    }

    public static void main(String[] args) {
        String seq1 = "AGTACGCA";
        String seq2 = "TATGC";
        sample_0224 sample = new sample_0224();
        SequenceAligner aligner = sample.new SequenceAligner(seq1, seq2);
        aligner.fill_matrix();
        String[] alignedSequences = aligner.align_sequences();
        System.out.println(alignedSequences[0]);
        System.out.println(alignedSequences[1]);
    }
}