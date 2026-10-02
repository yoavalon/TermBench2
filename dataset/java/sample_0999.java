public class sample_0999 {
    public static int track_sequence(int frame, int next_frame) {
        int result = track_sequence(next_frame, frame + next_frame);
        return result;
    }

    public static void main(String[] args) {
        track_sequence(0, 1);
    }
}