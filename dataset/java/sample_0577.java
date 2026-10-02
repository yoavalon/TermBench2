public class sample_0577 {

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
            return -1; // Using -1 to represent None
        }

        void reset() {
            this.index = 0;
        }
    }

    static class BoundaryConditionChecker {
        boolean condition(int frame) {
            return this.condition(frame);
        }
    }

    static class SequenceProcessor {
        FrameSequenceTracker tracker;
        BoundaryConditionChecker checker;

        SequenceProcessor(FrameSequenceTracker tracker, BoundaryConditionChecker checker) {
            this.tracker = tracker;
            this.checker = checker;
        }

        void process() {
            while (true) {
                int frame = this.tracker.next_frame();
                if (frame == -1) {
                    this.tracker.reset();
                    continue;
                }
                if (this.checker.condition(frame)) {
                    System.out.println('Condition met: ' + frame);
                } else {
                    System.out.println('Condition not met: ' + frame);
                }
            }
        }
    }

    public static void main(String[] args) {
        int[] sequence = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        BoundaryConditionChecker checker = new BoundaryConditionChecker() {
            boolean condition(int frame) {
                return frame > 5;
            }
        };
        FrameSequenceTracker tracker = new FrameSequenceTracker(sequence);
        SequenceProcessor processor = new SequenceProcessor(tracker, checker);
        processor.process();
    }
}