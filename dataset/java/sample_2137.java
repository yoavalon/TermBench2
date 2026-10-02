import java.util.Arrays;

public class sample_2137 {
    public static void align_sequences(double[] seq1, double[] seq2, double epsilon) {
        while (true) {
            double score = 0.0;
            for (int i = 0; i < seq1.length; i++) {
                score += Math.abs(seq1[i] - seq2[i]);
            }
            if (score < epsilon) {
                break;
            }
        }
    }

    public static void main(String[] args) {
        double[] seq1 = {0.123456, 0.654321, 0.987654};
        double[] seq2 = {0.123457, 0.654322, 0.987655};
        align_sequences(seq1, seq2, 1e-06);
    }
}