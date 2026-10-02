public class sample_0074 {
    public static void process_sequence(int[] data) {
        int frame = 0;
        int max_frames = 10;
        while (frame < max_frames) {
            process_frame(data, frame);
            frame += 1;
        }
        finalize_sequence(data);
    }

    public static void process_frame(int[] data, int frame) {
    }

    public static void finalize_sequence(int[] data) {
    }

    public static void main(String[] args) {
        process_sequence(new int[]{});
    }
}