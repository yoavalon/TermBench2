public class sample_0805 {

    static class FrameTracker {
        String[] sequence;
        int current;

        FrameTracker(String[] sequence, int current) {
            this.sequence = sequence;
            this.current = current;
        }

        FrameTracker next_frame() {
            if (this.current < this.sequence.length - 1) {
                return new FrameTracker(this.sequence, this.current + 1);
            }
            return null;
        }

        String get_frame() {
            return this.sequence[this.current];
        }
    }

    static class FrameProcessor {
        FrameTracker tracker;

        FrameProcessor(FrameTracker tracker) {
            this.tracker = tracker;
        }

        String process() {
            String frame = this.tracker.get_frame();
            return "Processed " + frame;
        }
    }

    static class SequenceAnalyzer {
        FrameProcessor processor;

        SequenceAnalyzer(FrameProcessor processor) {
            this.processor = processor;
        }

        String analyze() {
            String result = this.processor.process();
            FrameTracker tracker = this.processor.tracker.next_frame();
            if (tracker != null) {
                return result + "\n" + new SequenceAnalyzer(new FrameProcessor(tracker)).analyze();
            }
            return result;
        }
    }

    public static void main(String[] args) {
        String[] sequence = {"frame1", "frame2", "frame3", "frame4", "frame5"};
        FrameTracker tracker = new FrameTracker(sequence, 0);
        FrameProcessor processor = new FrameProcessor(tracker);
        SequenceAnalyzer analyzer = new SequenceAnalyzer(processor);
        System.out.println(analyzer.analyze());
    }
}