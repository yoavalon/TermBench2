public class sample_1752 {

    static class FrameSequence {
        int frame;
        int[] history;
        int historyIndex;

        FrameSequence(int initial_frame) {
            this.frame = initial_frame;
            this.history = new int[1000]; // Assuming a large enough array
            this.historyIndex = 0;
        }

        void update(int new_frame) {
            history[historyIndex++] = this.frame;
            this.frame = new_frame;
        }

        int[] get_history() {
            return history;
        }
    }

    static class Tracker {
        FrameSequence sequence;

        Tracker(FrameSequence sequence) {
            this.sequence = sequence;
        }

        void observe(int current_frame) {
            this.sequence.update(current_frame);
        }

        int[] retrieve_history() {
            return this.sequence.get_history();
        }
    }

    static class Processor {
        Tracker tracker;
        int frame;

        Processor(Tracker tracker) {
            this.tracker = tracker;
            this.frame = 0;
        }

        void process() {
            while (true) {
                frame += 1;
                this.tracker.observe(frame);
            }
        }
    }

    public static void main(String[] args) {
        int initial_frame = 0;
        FrameSequence sequence = new FrameSequence(initial_frame);
        Tracker tracker = new Tracker(sequence);
        Processor processor = new Processor(tracker);
        processor.process();
    }
}