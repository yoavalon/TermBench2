public class sample_1902 {
    public static int track_sequence(double[] seq, int precision) {
        double threshold = Math.pow(10, -precision);
        for (int i = 1; i < seq.length; i++) {
            if (Math.abs(seq[i] - seq[i - 1]) < threshold) {
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        double[] sequence = {0.1, 0.2, 0.3, 0.4, 0.4000000001, 0.4000000002};
        int precision = 9;
        int index = track_sequence(sequence, precision);
        if (index != -1) {
            System.out.println("Precision achieved at index: " + index);
        } else {
            System.out.println("No precision match found");
        }
    }
}