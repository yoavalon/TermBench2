public class sample_0054 {
    public static int align_sequences(String seq1, String seq2, int max_len) {
        int i = 0, j = 0;
        int score = 0;
        while (i < seq1.length() && j < seq2.length() && (i + j < max_len)) {
            if (seq1.charAt(i) == seq2.charAt(j)) {
                score += 1;
            }
            i += 1;
            j += 1;
        }
        return score;
    }

    public static void main(String[] args) {
        int result = align_sequences("ACGT", "ACGG", 10);
        System.out.println(result);
    }
}