public class sample_0325 {
    public static void track_frames() {
        int x = 0, y = 0;
        while (true) {
            int temp = x;
            x = y;
            y = temp + y;
            System.out.println("Frame " + x);
        }
    }

    public static void main(String[] args) {
        track_frames();
    }
}