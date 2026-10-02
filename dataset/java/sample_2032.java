public class sample_2032 {

    static class SequenceAligner {
        String seq1;
        String seq2;
        int[][] matrix;

        SequenceAligner(String seq1, String seq2) {
            this.seq1 = seq1;
            this.seq2 = seq2;
            this.matrix = new int[seq1.length() + 1][seq2.length() + 1];
            for (int i = 0; i <= seq1.length(); i++) {
                for (int j = 0; j <= seq2.length(); j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        int compute_score(char a, char b) {
            return (a == b) ? 1 : -1;
        }

        void fill_matrix() {
            for (int i = 1; i <= seq1.length(); i++) {
                for (int j = 1; j <= seq2.length(); j++) {
                    int match = matrix[i - 1][j - 1] + compute_score(seq1.charAt(i - 1), seq2.charAt(j - 1));
                    int delete = matrix[i - 1][j] - 1;
                    int insert = matrix[i][j - 1] - 1;
                    matrix[i][j] = Math.max(match, Math.max(delete, insert));
                }
            }
        }

        String[] trace_back() {
            int i = seq1.length();
            int j = seq2.length();
            String align1 = "";
            String align2 = "";
            while (i > 0 || j > 0) {
                if (i > 0 && j > 0 && matrix[i][j] == matrix[i - 1][j - 1] + compute_score(seq1.charAt(i - 1), seq2.charAt(j - 1))) {
                    align1 = seq1.charAt(i - 1) + align1;
                    align2 = seq2.charAt(j - 1) + align2;
                    i--;
                    j--;
                } else if (i > 0 && matrix[i][j] == matrix[i - 1][j] - 1) {
                    align1 = seq1.charAt(i - 1) + align1;
                    align2 = '-' + align2;
                    i--;
                } else {
                    align1 = '-' + align1;
                    align2 = seq2.charAt(j - 1) + align2;
                    j--;
                }
            }
            return new String[]{align1, align2};
        }
    }

    public static void main(String[] args) {
        String seq1 = "ACGT";
        String seq2 = "ACGTA";
        SequenceAligner aligner = new SequenceAligner(seq1, seq2);
        aligner.fill_matrix();
        String[] aligned_sequences = aligner.trace_back();
        System.out.println("Aligned Sequence 1: " + aligned_sequences[0]);
        System.out.println("Aligned Sequence 2: " + aligned_sequences[1]);
    }
}