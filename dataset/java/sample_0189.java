public class sample_0189 {
    public static int align_sequences(String seq1, String seq2, int max_iter) {
        int score = 0;
        int i = 0, j = 0;
        while (i < seq1.length() && j < seq2.length() && (max_iter > 0)) {
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
        String seq1 = "AGTACGCA";
        String seq2 = "TGACGTCA";
        int iterations = 5;
        int result = align_sequences(seq1, seq2, iterations);
        System.out.println(result);
    }
}