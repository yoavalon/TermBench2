public class sample_0580 {

    static class FrameTracker {
        int[] sequence;
        int current_index;

        FrameTracker(int[] sequence) {
            this.sequence = sequence;
            this.current_index = 0;
        }

        void update() {
            this.current_index = (this.current_index + 1) % this.sequence.length;
        }

        int getCurrentFrame() {
            return this.sequence[this.current_index];
        }
    }

    static class BoundaryManager {
        FrameTracker frame_tracker;
        java.util.function.IntPredicate[] boundary_conditions;

        BoundaryManager(FrameTracker frame_tracker, java.util.function.IntPredicate[] boundary_conditions) {
            this.frame_tracker = frame_tracker;
            this.boundary_conditions = boundary_conditions;
        }

        boolean checkConditions() {
            int current_frame = this.frame_tracker.getCurrentFrame();
            for (java.util.function.IntPredicate condition : this.boundary_conditions) {
                if (!condition.test(current_frame)) {
                    return false;
                }
            }
            return true;
        }

        void handleFrame() {
            if (this.checkConditions()) {
                this.frame_tracker.update();
            }
        }
    }

    static class SequenceHandler {
        BoundaryManager boundary_manager;

        SequenceHandler(BoundaryManager boundary_manager) {
            this.boundary_manager = boundary_manager;
        }

        void process() {
            while (true) {
                this.boundary_manager.handleFrame();
            }
        }
    }

    public static void main(String[] args) {
        int[] sequence = {1, 2, 3, 4, 5};
        java.util.function.IntPredicate[] boundary_conditions = {
            x -> x > 0,
            x -> x < 6
        };
        FrameTracker frame_tracker = new FrameTracker(sequence);
        BoundaryManager boundary_manager = new BoundaryManager(frame_tracker, boundary_conditions);
        SequenceHandler sequence_handler = new SequenceHandler(boundary_manager);
        sequence_handler.process();
    }
}