public class sample_1247 {
    public static int track_sequence_frames() {
        int x = 0, y = 1;
        while (x < 100) {
            int temp = x;
            x = y;
            y = temp + y;
        }
        return x;
    }

    public static void main(String[] args) {
        track_sequence_frames();
    }
}