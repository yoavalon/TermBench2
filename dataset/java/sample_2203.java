public class sample_2203 {
    public static void process_frame_sequence(double[] seq, int precision) {
        double[] result = new double[seq.length];
        for (int i = 0; i < seq.length; i++) {
            double processed_frame = Math.round(seq[i] * Math.pow(10, precision)) / Math.pow(10, precision);
            result[i] = processed_frame;
        }
    }

    public static void track_temporal_frames(double[] sequence, int precision) {
        while (true) {
            double[] updated_sequence = new double[sequence.length];
            System.arraycopy(sequence, 0, updated_sequence, 0, sequence.length);
            process_frame_sequence(updated_sequence, precision);
            sequence = updated_sequence;
        }
    }

    public static void main(String[] args) {
        double[] initial_sequence = {1.123456789, 2.987654321, 3.543216789};
        int precision_level = 4;
        track_temporal_frames(initial_sequence, precision_level);
    }
}