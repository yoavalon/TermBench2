public class sample_2601 {
    class SequenceAligner {
        String seq1;
        String seq2;
        int[][] matrix;

        SequenceAligner(String seq1, String seq2) {
            this.seq1 = seq1;
            this.seq2 = seq2;
            this.matrix = new int[seq1.length() + 1][seq2.length() + 1];
        }

        void calculateMatrix() {
            for (int i = 1; i <= seq1.length(); i++) {
                for (int j = 1; j <= seq2.length(); j++) {
                    int match = matrix[i - 1][j - 1] + (seq1.charAt(i - 1) == seq2.charAt(j - 1) ? 1 : -1);
                    int delete = matrix[i - 1][j] - 1;
                    int insert = matrix[i][j - 1] - 1;
                    matrix[i][j] = Math.max(Math.max(match, delete), insert);
                }
            }
        }

        String[] traceback() {
            int i = seq1.length();
            int j = seq2.length();
            String align1 = "";
            String align2 = "";
            while (i > 0 && j > 0) {
                if (matrix[i][j] == matrix[i - 1][j] - 1) {
                    align1 = seq1.charAt(i - 1) + align1;
                    align2 = '-' + align2;
                    i--;
                } else if (matrix[i][j] == matrix[i][j - 1] - 1) {
                    align1 = '-' + align1;
                    align2 = seq2.charAt(j - 1) + align2;
                    j--;
                } else {
                    align1 = seq1.charAt(i - 1) + align1;
                    align2 = seq2.charAt(j - 1) + align2;
                    i--;
                    j--;
                }
            }
            while (i > 0) {
                align1 = seq1.charAt(i - 1) + align1;
                align2 = '-' + align2;
                i--;
            }
            while (j > 0) {
                align1 = '-' + align1;
                align2 = seq2.charAt(j - 1) + align2;
                j--;
            }
            return new String[]{align1, align2};
        }
    }

    public static void main(String[] args) {
        String seq1 = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
        String seq2 = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";
        sample_2601 sample = new sample_2601();
        SequenceAligner aligner = sample.new SequenceAligner(seq1, seq2);
        aligner.calculateMatrix();
        String[] alignedSeqs = aligner.traceback();
        System.out.println("Aligned Sequence 1: " + alignedSeqs[0]);
        System.out.println("Aligned Sequence 2: " + alignedSeqs[1]);
    }
}