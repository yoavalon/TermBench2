public class sample_2162 {
    public static void track_temporal_frame_sequence() {
        double x = 0.0;
        while (true) {
            x = update_position(x);
            System.out.println(x);
        }
    }

    public static double update_position(double x) {
        return x + 0.0001;
    }

    public static void main(String[] args) {
        track_temporal_frame_sequence();
    }
}