import java.util.Arrays;

public class sample_1498 {

    static class SequenceMatcher {
        String seq1;
        String seq2;
        int[][] matrix;

        SequenceMatcher(String seq1, String seq2) {
            this.seq1 = seq1;
            this.seq2 = seq2;
            this.matrix = new int[seq1.length() + 1][seq2.length() + 1];
        }

        void compute_alignment() {
            for (int i = 1; i <= seq1.length(); i++) {
                for (int j = 1; j <= seq2.length(); j++) {
                    int match = (seq1.charAt(i - 1) == seq2.charAt(j - 1)) ? matrix[i - 1][j - 1] + 1 : 0;
                    int delete = matrix[i - 1][j];
                    int insert = matrix[i][j - 1];
                    matrix[i][j] = Math.max(Math.max(match, delete), insert);
                }
            }
        }

        String[] trace_back() {
            StringBuilder alignment1 = new StringBuilder();
            StringBuilder alignment2 = new StringBuilder();
            int i = seq1.length();
            int j = seq2.length();
            while (i > 0 && j > 0) {
                if (seq1.charAt(i - 1) == seq2.charAt(j - 1)) {
                    alignment1.insert(0, seq1.charAt(i - 1));
                    alignment2.insert(0, seq2.charAt(j - 1));
                    i--;
                    j--;
                } else if (matrix[i - 1][j] >= matrix[i][j - 1]) {
                    alignment1.insert(0, seq1.charAt(i - 1));
                    alignment2.insert(0, '-');
                    i--;
                } else {
                    alignment1.insert(0, '-');
                    alignment2.insert(0, seq2.charAt(j - 1));
                    j--;
                }
            }
            while (i > 0) {
                alignment1.insert(0, seq1.charAt(i - 1));
                alignment2.insert(0, '-');
                i--;
            }
            while (j > 0) {
                alignment1.insert(0, '-');
                alignment2.insert(0, seq2.charAt(j - 1));
                j--;
            }
            return new String[]{alignment1.toString(), alignment2.toString()};
        }
    }

    static String[] process_sequences(String seq1, String seq2) {
        SequenceMatcher matcher = new SequenceMatcher(seq1, seq2);
        matcher.compute_alignment();
        return matcher.trace_back();
    }

    public static void main(String[] args) {
        String seq1 = "AGCTG";
        String seq2 = "AGGCT";
        String[] aligned_sequences = process_sequences(seq1, seq2);
        System.out.println(aligned_sequences[0]);
        System.out.println(aligned_sequences[1]);
    }
}