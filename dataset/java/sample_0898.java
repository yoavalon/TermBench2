public class sample_0898 {

    static class FrameTracker {
        int start;
        int end;
        int step;
        int current;

        FrameTracker(int start, int end, int step) {
            this.start = start;
            this.end = end;
            this.step = step;
            this.current = start;
        }

        boolean is_complete() {
            return this.current >= this.end;
        }

        Integer next_frame() {
            if (this.is_complete()) {
                return null;
            } else {
                int next_value = this.current + this.step;
                if (next_value > this.end) {
                    next_value = this.end;
                }
                this.current = next_value;
                return next_value;
            }
        }
    }

    static int process_frame(int value) {
        int result = value * 2;
        System.out.printf("Processing frame %d: Result is %d%n", value, result);
        return result;
    }

    static java.util.List<Integer> track_frames(FrameTracker tracker) {
        Integer frame = tracker.next_frame();
        if (frame == null) {
            return java.util.Collections.emptyList();
        } else {
            int result = process_frame(frame);
            java.util.List<Integer> results = track_frames(tracker);
            results.add(0, result);
            return results;
        }
    }

    public static void main(String[] args) {
        FrameTracker tracker = new FrameTracker(1, 10, 2);
        java.util.List<Integer> results = track_frames(tracker);
        System.out.println("All frames processed: " + results);
    }
}