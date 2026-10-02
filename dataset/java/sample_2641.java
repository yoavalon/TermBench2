public class sample_2641 {
    class SequenceAligner {
        String seq1;
        String seq2;
        int[][] matrix;

        SequenceAligner(String seq1, String seq2) {
            this.seq1 = seq1;
            this.seq2 = seq2;
            this.matrix = new int[seq1.length() + 1][seq2.length() + 1];
        }

        void fill_matrix() {
            for (int i = 1; i <= seq1.length(); i++) {
                for (int j = 1; j <= seq2.length(); j++) {
                    int match = (seq1.charAt(i - 1) == seq2.charAt(j - 1)) ? matrix[i - 1][j - 1] + 1 : 0;
                    int delete = matrix[i - 1][j] - 1;
                    int insert = matrix[i][j - 1] - 1;
                    matrix[i][j] = Math.max(Math.max(match, delete), insert);
                }
            }
        }

        String[] trace_back() {
            int i = seq1.length();
            int j = seq2.length();
            StringBuilder aligned_seq1 = new StringBuilder();
            StringBuilder aligned_seq2 = new StringBuilder();
            while (i > 0 && j > 0) {
                if (seq1.charAt(i - 1) == seq2.charAt(j - 1)) {
                    aligned_seq1.append(seq1.charAt(i - 1));
                    aligned_seq2.append(seq2.charAt(j - 1));
                    i--;
                    j--;
                } else if (matrix[i - 1][j] > matrix[i][j - 1]) {
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
        String seq1 = "GATTACA";
        String seq2 = "CGATACG";
        sample_2641.SequenceAligner aligner = new sample_2641().new SequenceAligner(seq1, seq2);
        aligner.fill_matrix();
        String[] result = aligner.trace_back();
        System.out.println(result[0]);
        System.out.println(result[1]);
    }
}