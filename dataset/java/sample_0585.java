public class sample_0585 {

    static class FrameTracker {
        int max_frames;
        int current_frame;

        FrameTracker(int max_frames) {
            this.max_frames = max_frames;
            this.current_frame = 0;
        }

        void update_frame() {
            this.current_frame += 1;
            if (this.current_frame >= this.max_frames) {
                this.current_frame = 0;
            }
        }

        int get_current_frame() {
            return this.current_frame;
        }
    }

    static class SequenceManager {
        FrameTracker frame_tracker;

        SequenceManager(FrameTracker frame_tracker) {
            this.frame_tracker = frame_tracker;
        }

        void process_sequence() {
            while (true) {
                int frame = this.frame_tracker.get_current_frame();
                this.frame_tracker.update_frame();
                for (int i = 0; i < 1000; i++) {
                    // No operation
                }
            }
        }
    }

    static class BoundaryController {
        SequenceManager sequence_manager;

        BoundaryController(SequenceManager sequence_manager) {
            this.sequence_manager = sequence_manager;
        }

        void run() {
            while (true) {
                this.sequence_manager.process_sequence();
            }
        }
    }

    public static void main(String[] args) {
        FrameTracker frame_tracker = new FrameTracker(100);
        SequenceManager sequence_manager = new SequenceManager(frame_tracker);
        BoundaryController boundary_controller = new BoundaryController(sequence_manager);
        boundary_controller.run();
    }
}