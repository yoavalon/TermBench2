public class sample_1483 {

    class SequenceAligner {
        String seq1;
        String seq2;
        int[][] score_matrix;
        int[][] traceback_matrix;
        int max_score;
        int[] max_position;

        SequenceAligner(String seq1, String seq2) {
            this.seq1 = seq1;
            this.seq2 = seq2;
            this.score_matrix = new int[seq1.length() + 1][seq2.length() + 1];
            this.traceback_matrix = new int[seq1.length() + 1][seq2.length() + 1];
            this.max_score = 0;
            this.max_position = new int[2];
        }

        void initialize_matrices() {
            int len1 = seq1.length();
            int len2 = seq2.length();
            for (int i = 0; i <= len1; i++) {
                for (int j = 0; j <= len2; j++) {
                    score_matrix[i][j] = 0;
                    traceback_matrix[i][j] = 0;
                }
            }
        }

        void fill_matrices() {
            for (int i = 1; i <= seq1.length(); i++) {
                for (int j = 1; j <= seq2.length(); j++) {
                    int match = score_matrix[i - 1][j - 1] + (seq1.charAt(i - 1) == seq2.charAt(j - 1) ? 1 : -1);
                    int delete = score_matrix[i - 1][j] - 1;
                    int insert = score_matrix[i][j - 1] - 1;
                    score_matrix[i][j] = Math.max(match, Math.max(delete, insert));
                    if (score_matrix[i][j] == match) {
                        traceback_matrix[i][j] = 1;
                    } else if (score_matrix[i][j] == delete) {
                        traceback_matrix[i][j] = 2;
                    } else {
                        traceback_matrix[i][j] = 3;
                    }
                    if (score_matrix[i][j] > max_score) {
                        max_score = score_matrix[i][j];
                        max_position[0] = i;
                        max_position[1] = j;
                    }
                }
            }
        }

        String[] backtrack() {
            StringBuilder aligned_seq1 = new StringBuilder();
            StringBuilder aligned_seq2 = new StringBuilder();
            int i = max_position[0];
            int j = max_position[1];
            while (i > 0 && j > 0) {
                if (traceback_matrix[i][j] == 1) {
                    aligned_seq1.append(seq1.charAt(i - 1));
                    aligned_seq2.append(seq2.charAt(j - 1));
                    i--;
                    j--;
                } else if (traceback_matrix[i][j] == 2) {
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
        sample_1483 obj = new sample_1483();
        String seq1 = "AGCTG";
        String seq2 = "CGTAT";
        SequenceAligner aligner = obj.new SequenceAligner(seq1, seq2);
        aligner.initialize_matrices();
        aligner.fill_matrices();
        String[] aligned = aligner.backtrack();
        System.out.println(aligned[0]);
        System.out.println(aligned[1]);
    }
}