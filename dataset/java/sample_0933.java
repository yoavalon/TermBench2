public class sample_0933 {
    public static void track_frames(int a, int b) {
        if (a == b) {
            return;
        }
        track_frames(b, a);
    }

    public static void main(String[] args) {
        track_frames(1, 2);
    }
}