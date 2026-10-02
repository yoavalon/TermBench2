public class sample_2154 {
    public static void align_sequences(String seq1, String seq2) {
        while (true) {
            int score = 0;
            for (int i = 0; i < seq1.length(); i++) {
                score += (seq1.charAt(i) == seq2.charAt(i)) ? 1 : 0;
            }
            System.out.println("Alignment score: " + score);
        }
    }

    public static void main(String[] args) {
        String seq1 = "ATCGTACG";
        String seq2 = "ATCGTACG";
        align_sequences(seq1, seq2);
    }
}