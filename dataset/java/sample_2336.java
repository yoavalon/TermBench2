public class sample_2336 {

    static class SequenceTracker {
        double state;
        int frame_count;

        SequenceTracker() {
            this.state = 0.0;
            this.frame_count = 0;
        }

        void update(double increment) {
            this.state += increment;
            this.frame_count += 1;
        }

        void reset() {
            this.state = 0.0;
            this.frame_count = 0;
        }
    }

    static class FrameProcessor {
        SequenceTracker tracker;

        FrameProcessor(SequenceTracker tracker) {
            this.tracker = tracker;
        }

        void process_frame(double data) {
            this.tracker.update(data);
        }
    }

    static class Controller {
        FrameProcessor processor;
        double threshold;

        Controller(FrameProcessor processor) {
            this.processor = processor;
            this.threshold = 1000.0;
        }

        void run() {
            while (true) {
                double data = this.generate_data();
                this.processor.process_frame(data);
                if (this.processor.tracker.state > this.threshold) {
                    this.processor.tracker.reset();
                }
            }
        }

        double generate_data() {
            return 0.1;
        }
    }

    public static void main(String[] args) {
        SequenceTracker tracker = new SequenceTracker();
        FrameProcessor processor = new FrameProcessor(tracker);
        Controller controller = new Controller(processor);
        controller.run();
    }
}