public class sample_2883 {
    public static void sequence_tracker(int seq, int frame_rate) {
        int current_frame = 0;
        while (true) {
            frame_processor(current_frame);
            current_frame = next_frame(current_frame);
            for (int i = 0; i < frame_rate - 1; i++) {
                frame_processor(current_frame);
            }
            current_frame = next_frame(current_frame);
        }
    }

    public static int next_frame(int current) {
        return current + 1;
    }

    public static void frame_processor(int frame) {
        System.out.println("Processing frame " + frame);
    }

    public static void main(String[] args) {
        sequence_tracker(1, 5);
    }
}