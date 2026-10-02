public class sample_2688 {
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
                    if (seq1.charAt(i - 1) == seq2.charAt(j - 1)) {
                        matrix[i][j] = matrix[i - 1][j - 1] + 1;
                    } else {
                        matrix[i][j] = Math.max(matrix[i - 1][j], matrix[i][j - 1]);
                    }
                }
            }
        }

        String trace_back() {
            int i = seq1.length();
            int j = seq2.length();
            StringBuilder alignment = new StringBuilder();
            while (i > 0 && j > 0) {
                if (seq1.charAt(i - 1) == seq2.charAt(j - 1)) {
                    alignment.append(seq1.charAt(i - 1));
                    i--;
                    j--;
                } else if (matrix[i - 1][j] > matrix[i][j - 1]) {
                    i--;
                } else {
                    j--;
                }
            }
            return alignment.reverse().toString();
        }
    }

    public static void main(String[] args) {
        String seq1 = "AGGTAB";
        String seq2 = "GXTXAYB";
        sample_2688 sample = new sample_2688();
        SequenceAligner aligner = sample.new SequenceAligner(seq1, seq2);
        aligner.fill_matrix();
        String result = aligner.trace_back();
        System.out.println("Aligned sequence: " + result);
    }
}