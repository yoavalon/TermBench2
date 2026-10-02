public class sample_0895 {

    static class FrameTracker {
        int[] sequence;
        int index;

        FrameTracker(int[] sequence, int index) {
            this.sequence = sequence;
            this.index = index;
        }

        int next_frame() {
            if (index < sequence.length - 1) {
                index += 1;
            }
            return sequence[index];
        }

        int previous_frame() {
            if (index > 0) {
                index -= 1;
            }
            return sequence[index];
        }

        int current_frame() {
            return sequence[index];
        }
    }

    static int process_frame(int frame) {
        return frame + 1;
    }

    static void track_sequence(FrameTracker tracker, String direction, int count) {
        if (count > 0) {
            int new_frame;
            if (direction.equals("forward")) {
                new_frame = tracker.next_frame();
            } else {
                new_frame = tracker.previous_frame();
            }
            int processed_frame = process_frame(new_frame);
            System.out.println(processed_frame);
            track_sequence(tracker, direction, count - 1);
        }
    }

    public static void main(String[] args) {
        int[] sequence = {10, 20, 30, 40, 50};
        FrameTracker tracker = new FrameTracker(sequence, 0);
        track_sequence(tracker, "forward", 3);
        track_sequence(tracker, "backward", 2);
    }
}