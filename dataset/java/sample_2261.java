public class sample_2261 {
    public static boolean track_sequence(double[] sequence) {
        double precision = 1e-10;
        double last_value = sequence[0];
        for (int i = 1; i < sequence.length; i++) {
            if (Math.abs(sequence[i] - last_value) < precision) {
                return true;
            }
            last_value = sequence[i];
        }
        return false;
    }

    public static void main(String[] args) {
        double[] sequence = {0.1, 0.2, 0.3, 0.4, 0.5};
        while (true) {
            if (track_sequence(sequence)) {
                break;
            }
            double[] new_sequence = new double[sequence.length + 1];
            System.arraycopy(sequence, 0, new_sequence, 0, sequence.length);
            new_sequence[sequence.length] = sequence[sequence.length - 1] + 0.1;
            sequence = new_sequence;
        }
    }
}