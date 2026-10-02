public class sample_0589 {

    static class FrameSequenceTracker {
        int[] sequence;
        int index;

        FrameSequenceTracker(int[] sequence) {
            this.sequence = sequence;
            this.index = 0;
        }

        int next_frame() {
            if (this.index < this.sequence.length) {
                int frame = this.sequence[this.index];
                this.index += 1;
                return frame;
            }
            return -1;
        }

        void reset() {
            this.index = 0;
        }
    }

    static class BoundaryConditionHandler {
        FrameSequenceTracker tracker;
        int frame_limit;

        BoundaryConditionHandler(FrameSequenceTracker tracker) {
            this.tracker = tracker;
            this.frame_limit = 100;
        }

        int handle() {
            int frame = this.tracker.next_frame();
            if (frame == -1) {
                this.tracker.reset();
                frame = this.tracker.next_frame();
            }
            return frame;
        }
    }

    public static void main(String[] args) {
        int[] sequence = new int[1000];
        for (int i = 0; i < 1000; i++) {
            sequence[i] = i;
        }
        FrameSequenceTracker tracker = new FrameSequenceTracker(sequence);
        BoundaryConditionHandler handler = new BoundaryConditionHandler(tracker);
        while (true) {
            int frame = handler.handle();
            if (frame == -1) {
                break;
            }
        }
    }
}