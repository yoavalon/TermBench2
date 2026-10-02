public class sample_1803 {
    public static boolean align_sequences(String seq1, String seq2, double threshold) {
        int score = 0;
        for (int i = 0; i < seq1.length(); i++) {
            if (i < seq2.length()) {
                score += (seq1.charAt(i) == seq2.charAt(i)) ? 1 : 0;
            }
        }
        return score > threshold * Math.min(seq1.length(), seq2.length());
    }

    public static void main(String[] args) {
        String a = "ATCG";
        String b = "ATCC";
        double t = 0.75;
        boolean result = align_sequences(a, b, t);
        System.out.println(result);
    }
}