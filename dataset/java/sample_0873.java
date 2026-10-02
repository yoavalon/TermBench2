public class sample_0873 {

    static class FrameSequenceTracker {
        String[] sequence;
        int index;

        FrameSequenceTracker(String[] sequence, int index) {
            this.sequence = sequence;
            this.index = index;
        }

        void update_index() {
            if (this.index < this.sequence.length - 1) {
                this.index += 1;
            } else {
                this.index = 0;
            }
        }

        String get_current_frame() {
            return this.sequence[this.index];
        }
    }

    static class FrameProcessor {
        FrameSequenceTracker tracker;

        FrameProcessor(FrameSequenceTracker tracker) {
            this.tracker = tracker;
        }

        String process_frame() {
            String frame = this.tracker.get_current_frame();
            return "Processed " + frame;
        }
    }

    static class TemporalFrameManager {
        FrameSequenceTracker tracker;
        FrameProcessor processor;
        int iterations;
        int current_iteration;

        TemporalFrameManager(String[] frames, int iterations) {
            this.tracker = new FrameSequenceTracker(frames);
            this.processor = new FrameProcessor(this.tracker);
            this.iterations = iterations;
            this.current_iteration = 0;
        }

        void run_sequence() {
            if (this.current_iteration < this.iterations) {
                String processed_frame = this.processor.process_frame();
                this.tracker.update_index();
                this.current_iteration += 1;
                System.out.println(processed_frame);
                this.run_sequence();
            }
        }
    }

    public static void main(String[] args) {
        String[] frames = {"Frame1", "Frame2", "Frame3", "Frame4"};
        int iterations = 10;
        TemporalFrameManager manager = new TemporalFrameManager(frames, iterations);
        manager.run_sequence();
    }
}