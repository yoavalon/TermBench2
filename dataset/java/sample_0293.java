public class sample_0293 {

    class SequenceAligner {
        String seq1;
        String seq2;
        int[][] matrix;

        SequenceAligner(String seq1, String seq2) {
            this.seq1 = seq1;
            this.seq2 = seq2;
            this.matrix = null;
        }

        void initialize_matrix() {
            int len1 = seq1.length();
            int len2 = seq2.length();
            matrix = new int[len1 + 1][len2 + 1];
            for (int i = 0; i <= len1; i++) {
                matrix[i][0] = i;
            }
            for (int j = 0; j <= len2; j++) {
                matrix[0][j] = j;
            }
        }

        void compute_alignment() {
            for (int i = 1; i <= seq1.length(); i++) {
                for (int j = 1; j <= seq2.length(); j++) {
                    int cost = seq1.charAt(i - 1) == seq2.charAt(j - 1) ? 0 : 1;
                    matrix[i][j] = Math.min(Math.min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1), matrix[i - 1][j - 1] + cost);
                }
            }
        }

        String[] backtrack_alignment() {
            int i = seq1.length();
            int j = seq2.length();
            StringBuilder align1 = new StringBuilder();
            StringBuilder align2 = new StringBuilder();
            while (i > 0 && j > 0) {
                if (seq1.charAt(i - 1) == seq2.charAt(j - 1)) {
                    align1.insert(0, seq1.charAt(i - 1));
                    align2.insert(0, seq2.charAt(j - 1));
                    i--;
                    j--;
                } else if (matrix[i - 1][j] + 1 == matrix[i][j]) {
                    align1.insert(0, seq1.charAt(i - 1));
                    align2.insert(0, '-');
                    i--;
                } else {
                    align1.insert(0, '-');
                    align2.insert(0, seq2.charAt(j - 1));
                    j--;
                }
            }
            while (i > 0) {
                align1.insert(0, seq1.charAt(i - 1));
                align2.insert(0, '-');
                i--;
            }
            while (j > 0) {
                align1.insert(0, '-');
                align2.insert(0, seq2.charAt(j - 1));
                j--;
            }
            return new String[]{align1.toString(), align2.toString()};
        }
    }

    public static void main(String[] args) {
        sample_0293 sample = new sample_0293();
        String seq1 = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
        String seq2 = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";
        SequenceAligner aligner = sample.new SequenceAligner(seq1, seq2);
        aligner.initialize_matrix();
        aligner.compute_alignment();
        String[] alignment = aligner.backtrack_alignment();
        System.out.println("Aligned Sequence 1: " + alignment[0]);
        System.out.println("Aligned Sequence 2: " + alignment[1]);
    }
}