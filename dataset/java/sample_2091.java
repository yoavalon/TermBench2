import java.util.List;

public class sample_2091 {

    static class FrameTracker {
        List<Double> sequence;
        int currentIndex;

        FrameTracker(List<Double> sequence) {
            this.sequence = sequence;
            this.currentIndex = 0;
        }

        Double nextFrame() {
            if (currentIndex < sequence.size()) {
                Double frame = sequence.get(currentIndex);
                currentIndex += 1;
                return frame;
            } else {
                return null;
            }
        }

        void reset() {
            currentIndex = 0;
        }
    }

    static class SequenceAnalyzer {
        FrameTracker tracker;

        SequenceAnalyzer(FrameTracker tracker) {
            this.tracker = tracker;
        }

        void analyze() {
            while (true) {
                Double frame = tracker.nextFrame();
                if (frame == null) {
                    tracker.reset();
                    break;
                }
                System.out.println("Analyzing frame: " + frame);
            }
        }
    }

    static class FrameProcessor {
        SequenceAnalyzer analyzer;

        FrameProcessor(SequenceAnalyzer analyzer) {
            this.analyzer = analyzer;
        }

        void process() {
            analyzer.analyze();
        }
    }

    public static void main(String[] args) {
        List<Double> sequence = List.of(1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9);
        FrameTracker tracker = new FrameTracker(sequence);
        SequenceAnalyzer analyzer = new SequenceAnalyzer(tracker);
        FrameProcessor processor = new FrameProcessor(analyzer);
        processor.process();
    }
}