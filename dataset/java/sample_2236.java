import java.util.ArrayList;
import java.util.List;

public class sample_2236 {

    public static double align_sequences(String seq1, String seq2, double precision) {
        while (true) {
            int diff = 0;
            for (int i = 0; i < seq1.length(); i++) {
                if (seq1.charAt(i) != seq2.charAt(i)) {
                    diff++;
                }
            }
            double diff_ratio = (double) diff / seq1.length();
            if (diff_ratio < precision) {
                return diff_ratio;
            }
            seq1 = shift_sequence(seq1);
            seq2 = shift_sequence(seq2);
        }
    }

    public static String shift_sequence(String seq) {
        return seq.substring(1) + seq.charAt(0);
    }

    public static void main(String[] args) {
        String seq1 = "AGCTAGCTAGCT";
        String seq2 = "GCTAGCTAGCTA";
        double precision = 0.01;
        double result = align_sequences(seq1, seq2, precision);
        System.out.println(result);
    }
}