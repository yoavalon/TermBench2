public class sample_0214 {
    static class SequenceAligner {
        String seq1;
        String seq2;
        int[][] matrix;
        int[][] traceback;

        SequenceAligner(String seq1, String seq2) {
            this.seq1 = seq1;
            this.seq2 = seq2;
            this.matrix = new int[seq1.length() + 1][seq2.length() + 1];
            this.traceback = new int[seq1.length() + 1][seq2.length() + 1];
        }

        void fill_matrix() {
            for (int i = 1; i <= seq1.length(); i++) {
                for (int j = 1; j <= seq2.length(); j++) {
                    int match = (seq1.charAt(i - 1) == seq2.charAt(j - 1)) ? matrix[i - 1][j - 1] + 1 : matrix[i - 1][j - 1] - 1;
                    int delete = matrix[i - 1][j] - 1;
                    int insert = matrix[i][j - 1] - 1;
                    matrix[i][j] = Math.max(Math.max(match, delete), insert);
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

        String[] trace_alignment() {
            int i = seq1.length();
            int j = seq2.length();
            String aligned_seq1 = "";
            String aligned_seq2 = "";
            while (i > 0 && j > 0) {
                if (traceback[i][j] == 1) {
                    aligned_seq1 = seq1.charAt(i - 1) + aligned_seq1;
                    aligned_seq2 = seq2.charAt(j - 1) + aligned_seq2;
                    i--;
                    j--;
                } else if (traceback[i][j] == 2) {
                    aligned_seq1 = seq1.charAt(i - 1) + aligned_seq1;
                    aligned_seq2 = "-" + aligned_seq2;
                    i--;
                } else {
                    aligned_seq1 = "-" + aligned_seq1;
                    aligned_seq2 = seq2.charAt(j - 1) + aligned_seq2;
                    j--;
                }
            }
            while (i > 0) {
                aligned_seq1 = seq1.charAt(i - 1) + aligned_seq1;
                aligned_seq2 = "-" + aligned_seq2;
                i--;
            }
            while (j > 0) {
                aligned_seq1 = "-" + aligned_seq1;
                aligned_seq2 = seq2.charAt(j - 1) + aligned_seq2;
                j--;
            }
            return new String[]{aligned_seq1, aligned_seq2};
        }
    }

    public static void main(String[] args) {
        String seq1 = "AGCTG";
        String seq2 = "ACGT";
        SequenceAligner aligner = new SequenceAligner(seq1, seq2);
        aligner.fill_matrix();
        String[] aligned = aligner.trace_alignment();
        System.out.println("Aligned Sequence 1: " + aligned[0]);
        System.out.println("Aligned Sequence 2: " + aligned[1]);
    }
}