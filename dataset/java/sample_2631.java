public class sample_2631 {

    class SequenceAligner {
        String seq1;
        String seq2;
        int[][] table;

        public SequenceAligner(String seq1, String seq2) {
            this.seq1 = seq1;
            this.seq2 = seq2;
            this.table = new int[seq1.length() + 1][seq2.length() + 1];
        }

        public void build_table() {
            for (int i = 0; i <= seq1.length(); i++) {
                for (int j = 0; j <= seq2.length(); j++) {
                    if (i == 0 || j == 0) {
                        table[i][j] = 0;
                    } else if (seq1.charAt(i - 1) == seq2.charAt(j - 1)) {
                        table[i][j] = table[i - 1][j - 1] + 1;
                    } else {
                        table[i][j] = Math.max(table[i - 1][j], table[i][j - 1]);
                    }
                }
            }
        }

        public String[] traceback() {
            int i = seq1.length();
            int j = seq2.length();
            String align1 = "";
            String align2 = "";
            while (i > 0 && j > 0) {
                if (seq1.charAt(i - 1) == seq2.charAt(j - 1)) {
                    align1 = seq1.charAt(i - 1) + align1;
                    align2 = seq2.charAt(j - 1) + align2;
                    i -= 1;
                    j -= 1;
                } else if (table[i - 1][j] > table[i][j - 1]) {
                    align1 = seq1.charAt(i - 1) + align1;
                    align2 = '-' + align2;
                    i -= 1;
                } else {
                    align1 = '-' + align1;
                    align2 = seq2.charAt(j - 1) + align2;
                    j -= 1;
                }
            }
            while (i > 0) {
                align1 = seq1.charAt(i - 1) + align1;
                align2 = '-' + align2;
                i -= 1;
            }
            while (j > 0) {
                align1 = '-' + align1;
                align2 = seq2.charAt(j - 1) + align2;
                j -= 1;
            }
            return new String[]{align1, align2};
        }
    }

    public static void main(String[] args) {
        sample_2631 sample = new sample_2631();
        String seq1 = "ACGTGACGGCCG";
        String seq2 = "ACGTTACGGCCG";
        sample.SequenceAligner aligner = sample.new SequenceAligner(seq1, seq2);
        aligner.build_table();
        String[] aligned_sequences = aligner.traceback();
        System.out.println(aligned_sequences[0]);
        System.out.println(aligned_sequences[1]);
    }
}