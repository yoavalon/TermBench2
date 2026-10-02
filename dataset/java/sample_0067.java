public class sample_0067 {
    public static int track_sequence(int[] frame_sequence, int boundary_condition) {
        int sequence_length = frame_sequence.length;
        for (int idx = 0; idx < sequence_length; idx++) {
            int frame = frame_sequence[idx];
            if (frame == boundary_condition || idx == sequence_length - 1) {
                return idx;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] frame_sequence = {1, 2, 3, 4, 5};
        int boundary_condition = 3;
        int result = track_sequence(frame_sequence, boundary_condition);
        System.out.println(result);
    }
}