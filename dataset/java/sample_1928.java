import java.util.Arrays;

public class sample_1928 {

    public static void main(String[] args) {
        double[] seq1 = {0.1, 0.2, 0.3, 0.4, 0.5};
        double[] seq2 = {0.1, 0.2, 0.3, 0.4, 0.5};
        double precision = 1e-09;
        Object[] result = align_sequences(seq1, seq2, precision);
        System.out.println("Alignment: " + Arrays.toString((double[]) result[0]) + " " + Arrays.toString((double[]) result[1]) + " Score: " + result[2]);
    }

    public static Object[] align_sequences(double[] seq1, double[] seq2, double precision) {
        double max_score = Double.NEGATIVE_INFINITY;
        Object[] best_alignment = new Object[2];

        for (int i = 0; i <= seq1.length - seq2.length; i++) {
            for (int j = 0; j <= seq2.length - seq1.length; j++) {
                double[] subseq1 = Arrays.copyOfRange(seq1, i, i + seq2.length);
                double[] subseq2 = Arrays.copyOfRange(seq2, j, j + seq1.length);
                double score = calculate_score(subseq1, subseq2);
                if (score > max_score) {
                    max_score = score;
                    best_alignment[0] = subseq1;
                    best_alignment[1] = subseq2;
                }
            }
        }
        return new Object[]{best_alignment[0], best_alignment[1], max_score};
    }

    public static double calculate_score(double[] a, double[] b) {
        double sum = 0;
        for (int i = 0; i < a.length; i++) {
            if (Math.abs(a[i] - b[i]) < precision) {
                sum += 1;
            } else {
                sum -= 1;
            }
        }
        return sum;
    }
}