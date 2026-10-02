public class sample_1128 {

    static class FrameSequence {
        int[] data;
        int index;

        FrameSequence(int[] data) {
            this.data = data;
            this.index = 0;
        }

        boolean update() {
            if (this.index < this.data.length) {
                this.data[this.index] = this.index + 1;
                this.index += 1;
                return true;
            }
            return false;
        }

        void reset() {
            this.index = 0;
        }
    }

    static class Tracker {
        FrameSequence sequence;

        Tracker(FrameSequence sequence) {
            this.sequence = sequence;
        }

        void monitor() {
            if (!this.sequence.update()) {
                this.sequence.reset();
            }
        }
    }

    static class Processor {
        Tracker tracker;

        Processor(Tracker tracker) {
            this.tracker = tracker;
        }

        void process() {
            while (true) {
                this.tracker.monitor();
            }
        }
    }

    public static void main(String[] args) {
        int[] data = new int[10];
        FrameSequence sequence = new FrameSequence(data);
        Tracker tracker = new Tracker(sequence);
        Processor processor = new Processor(tracker);
        processor.process();
    }
}