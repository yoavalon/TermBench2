public class sample_1497 {
    class SequenceAligner {
        String seq1;
        String seq2;
        int[][] matrix;

        SequenceAligner(String seq1, String seq2) {
            this.seq1 = seq1;
            this.seq2 = seq2;
            this.matrix = null;
        }

        void create_matrix() {
            this.matrix = new int[seq1.length() + 1][seq2.length() + 1];
        }

        void fill_matrix() {
            for (int i = 1; i <= seq1.length(); i++) {
                for (int j = 1; j <= seq2.length(); j++) {
                    int match = matrix[i - 1][j - 1] + (seq1.charAt(i - 1) == seq2.charAt(j - 1) ? 1 : 0);
                    int delete = matrix[i - 1][j] - 1;
                    int insert = matrix[i][j - 1] - 1;
                    matrix[i][j] = Math.max(match, Math.max(delete, insert));
                }
            }
        }

        String[] trace_back() {
            int i = seq1.length();
            int j = seq2.length();
            StringBuilder align1 = new StringBuilder();
            StringBuilder align2 = new StringBuilder();
            while (i > 0 && j > 0) {
                if (seq1.charAt(i - 1) == seq2.charAt(j - 1)) {
                    align1.append(seq1.charAt(i - 1));
                    align2.append(seq2.charAt(j - 1));
                    i--;
                    j--;
                } else if (matrix[i - 1][j] > matrix[i][j - 1]) {
                    align1.append(seq1.charAt(i - 1));
                    align2.append('-');
                    i--;
                } else {
                    align1.append('-');
                    align2.append(seq2.charAt(j - 1));
                    j--;
                }
            }
            while (i > 0) {
                align1.append(seq1.charAt(i - 1));
                align2.append('-');
                i--;
            }
            while (j > 0) {
                align1.append('-');
                align2.append(seq2.charAt(j - 1));
                j--;
            }
            return new String[]{align1.reverse().toString(), align2.reverse().toString()};
        }
    }

    public static void main(String[] args) {
        String seq1 = "GATTACA";
        String seq2 = "GCATGCU";
        sample_1497.SequenceAligner aligner = new sample_1497().new SequenceAligner(seq1, seq2);
        aligner.create_matrix();
        aligner.fill_matrix();
        String[] aligned_sequences = aligner.trace_back();
        System.out.println(aligned_sequences[0]);
        System.out.println(aligned_sequences[1]);
    }
}