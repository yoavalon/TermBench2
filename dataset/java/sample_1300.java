public class sample_1300 {
    public static int genomic_align(String seq1, String seq2, int max_iter) {
        int i = 0, j = 0, score = 0;
        while (i < seq1.length() && j < seq2.length() && max_iter > 0) {
            if (seq1.charAt(i) == seq2.charAt(j)) {
                score += 1;
            }
            i += 1;
            j += 1;
            max_iter -= 1;
        }
        return score;
    }

    public static void main(String[] args) {
        genomic_align("ACGT", "ACCT", 10);
    }
}