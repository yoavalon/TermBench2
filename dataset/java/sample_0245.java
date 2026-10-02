import java.util.ArrayList;
import java.util.List;

public class sample_0245 {
    class GenomicAligner {
        String seq1;
        String seq2;
        int[][] matrix;

        GenomicAligner(String seq1, String seq2) {
            this.seq1 = seq1;
            this.seq2 = seq2;
            this.matrix = new int[seq1.length() + 1][seq2.length() + 1];
        }

        private void _fill_matrix() {
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

        private List<Character>[] _traceback() {
            List<Character> alignment1 = new ArrayList<>();
            List<Character> alignment2 = new ArrayList<>();
            int i = seq1.length();
            int j = seq2.length();
            while (i > 0 && j > 0) {
                if (seq1.charAt(i - 1) == seq2.charAt(j - 1)) {
                    alignment1.add(seq1.charAt(i - 1));
                    alignment2.add(seq2.charAt(j - 1));
                    i--;
                    j--;
                } else if (matrix[i - 1][j] > matrix[i][j - 1]) {
                    alignment1.add(seq1.charAt(i - 1));
                    alignment2.add('-');
                    i--;
                } else {
                    alignment1.add('-');
                    alignment2.add(seq2.charAt(j - 1));
                    j--;
                }
            }
            java.util.Collections.reverse(alignment1);
            java.util.Collections.reverse(alignment2);
            return new List[]{alignment1, alignment2};
        }

        public List<Character>[] align() {
            _fill_matrix();
            return _traceback();
        }
    }

    public static void main(String[] args) {
        String seq1 = "AGTACGCA";
        String seq2 = "TGACGTCA";
        sample_0245 sample = new sample_0245();
        GenomicAligner aligner = sample.new GenomicAligner(seq1, seq2);
        List<Character>[] result = aligner.align();
        System.out.print("Alignment 1: ");
        for (Character c : result[0]) {
            System.out.print(c);
        }
        System.out.println();
        System.out.print("Alignment 2: ");
        for (Character c : result[1]) {
            System.out.print(c);
        }
        System.out.println();
    }
}