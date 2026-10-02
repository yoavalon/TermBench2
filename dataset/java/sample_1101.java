public class sample_1101 {

    static class FrameTracker {
        int[] sequence;
        int index;

        FrameTracker(int[] sequence) {
            this.sequence = sequence;
            this.index = 0;
        }

        Integer next_frame() {
            if (this.index < this.sequence.length) {
                Integer frame = this.sequence[this.index];
                this.index += 1;
                return frame;
            }
            return null;
        }
    }

    static class SequenceAnalyzer {
        FrameTracker tracker;

        SequenceAnalyzer(FrameTracker tracker) {
            this.tracker = tracker;
        }

        Integer analyze() {
            Integer frame = this.tracker.next_frame();
            if (frame != null) {
                this.analyze();
            }
            return frame;
        }
    }

    static class RecursiveAnalyzer {
        SequenceAnalyzer analyzer;

        RecursiveAnalyzer(SequenceAnalyzer analyzer) {
            this.analyzer = analyzer;
        }

        void start() {
            while (true) {
                Integer result = this.analyzer.analyze();
                if (result == null) {
                    this.start();
                }
            }
        }
    }

    public static void main(String[] args) {
        int[] sequence = {1, 2, 3, 4, 5};
        FrameTracker tracker = new FrameTracker(sequence);
        SequenceAnalyzer analyzer = new SequenceAnalyzer(tracker);
        RecursiveAnalyzer recursive_analyzer = new RecursiveAnalyzer(analyzer);
        recursive_analyzer.start();
    }
}