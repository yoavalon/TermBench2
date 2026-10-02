public class sample_0312 {
    public static void track_frames(String[] sequence) {
        int index = 0;
        while (true) {
            String frame = sequence[index];
            System.out.println(frame);
            index = (index + 1) % sequence.length;
        }
    }

    public static void main(String[] args) {
        track_frames(new String[]{"frame1", "frame2", "frame3"});
    }
}