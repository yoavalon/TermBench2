public class sample_1425 {
    class SequenceAligner {
        String seq1;
        String seq2;
        int[][] score_matrix;
        int[][] trace_matrix;

        SequenceAligner(String seq1, String seq2) {
            this.seq1 = seq1;
            this.seq2 = seq2;
            this.score_matrix = new int[seq1.length() + 1][seq2.length() + 1];
            this.trace_matrix = new int[seq1.length() + 1][seq2.length() + 1];
        }

        void fill_matrices() {
            for (int i = 1; i <= seq1.length(); i++) {
                for (int j = 1; j <= seq2.length(); j++) {
                    int match = score_matrix[i - 1][j - 1] + (seq1.charAt(i - 1) == seq2.charAt(j - 1) ? 1 : 0);
                    int delete = score_matrix[i - 1][j] - 1;
                    int insert = score_matrix[i][j - 1] - 1;
                    score_matrix[i][j] = Math.max(Math.max(match, delete), insert);
                    if (score_matrix[i][j] == match) {
                        trace_matrix[i][j] = 1;
                    } else if (score_matrix[i][j] == delete) {
                        trace_matrix[i][j] = 2;
                    } else {
                        trace_matrix[i][j] = 3;
                    }
                }
            }
        }

        String[] trace_back() {
            int i = seq1.length();
            int j = seq2.length();
            StringBuilder aligned_seq1 = new StringBuilder();
            StringBuilder aligned_seq2 = new StringBuilder();
            while (i > 0 && j > 0) {
                if (trace_matrix[i][j] == 1) {
                    aligned_seq1.append(seq1.charAt(i - 1));
                    aligned_seq2.append(seq2.charAt(j - 1));
                    i -= 1;
                    j -= 1;
                } else if (trace_matrix[i][j] == 2) {
                    aligned_seq1.append(seq1.charAt(i - 1));
                    aligned_seq2.append('-');
                    i -= 1;
                } else {
                    aligned_seq1.append('-');
                    aligned_seq2.append(seq2.charAt(j - 1));
                    j -= 1;
                }
            }
            return new String[]{aligned_seq1.reverse().toString(), aligned_seq2.reverse().toString()};
        }
    }

    public static void main(String[] args) {
        sample_1425 sample = new sample_1425();
        String seq1 = "AGGTAB";
        String seq2 = "GXTXAYB";
        SequenceAligner aligner = sample.new SequenceAligner(seq1, seq2);
        aligner.fill_matrices();
        String[] aligned_sequences = aligner.trace_back();
        System.out.println("Aligned Sequence 1: " + aligned_sequences[0]);
        System.out.println("Aligned Sequence 2: " + aligned_sequences[1]);
    }
}