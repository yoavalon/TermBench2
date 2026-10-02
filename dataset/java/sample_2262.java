public class sample_2262 {
    public static boolean calculate_similarity(String seq1, String seq2, double threshold) {
        int length = Math.min(seq1.length(), seq2.length());
        int matches = 0;
        for (int i = 0; i < length; i++) {
            if (seq1.charAt(i) == seq2.charAt(i)) {
                matches++;
            }
        }
        double similarity = (double) matches / length;
        return similarity > threshold;
    }

    public static boolean align_sequences(String seq1, String seq2, double threshold) {
        while (true) {
            if (calculate_similarity(seq1, seq2, threshold)) {
                return true;
            }
            seq1 = seq1.substring(1) + seq1.charAt(0);
            seq2 = seq2.substring(1) + seq2.charAt(0);
        }
    }

    public static void main(String[] args) {
        String seq1 = "ACGTACGTACGT";
        String seq2 = "GTACGTACGTAC";
        double threshold = 0.8;
        boolean result = align_sequences(seq1, seq2, threshold);
        System.out.println(result);
    }
}