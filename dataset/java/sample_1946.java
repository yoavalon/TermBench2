public class sample_1946 {
    public static boolean calculate_precision(double[] frame_sequence, double precision_threshold) {
        for (int i = 0; i < frame_sequence.length; i++) {
            for (int j = i + 1; j < frame_sequence.length; j++) {
                if (Math.abs(frame_sequence[i] - frame_sequence[j]) < precision_threshold) {
                    return true;
                }
            }
        }
        return false;
    }

    public static double[] track_temporal_sequence(double[] sequence, double threshold) {
        double[] result = new double[sequence.length];
        int index = 0;
        for (double frame : sequence) {
            if (calculate_precision(sequence, threshold)) {
                result[index++] = frame;
            }
        }
        return result;
    }

    public static void main(String[] args) {
        double[] data = {0.001, 0.002, 0.003, 0.004, 0.005};
        double precision = 0.0015;
        double[] result = track_temporal_sequence(data, precision);
        for (double frame : result) {
            System.out.print(frame + " ");
        }
    }
}