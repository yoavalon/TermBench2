import java.lang.Math;

public class sample_1962 {
    public static double align_sequences(String seq1, String seq2) {
        int len1 = seq1.length();
        int len2 = seq2.length();
        if (len1 == 0 || len2 == 0) {
            return 0;
        }
        int score = 0;
        for (int i = 0; i < Math.min(len1, len2); i++) {
            if (seq1.charAt(i) == seq2.charAt(i)) {
                score += 1;
            }
        }
        return (double) score / Math.max(len1, len2);
    }

    public static double normalize_score(double score) {
        return Math.floor(score * 100) / 100;
    }

    public static void main(String[] args) {
        String seq1 = "ATCGTACG";
        String seq2 = "ATCGTACC";
        double score = align_sequences(seq1, seq2);
        double normalized_score = normalize_score(score);
        System.out.println(normalized_score);
    }
}