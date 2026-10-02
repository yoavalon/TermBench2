import java.util.List;

public class sample_0252 {

    static class FrameTracker {
        List<Integer> sequence;
        int threshold;
        int index;

        FrameTracker(List<Integer> sequence, int threshold) {
            this.sequence = sequence;
            this.threshold = threshold;
            this.index = 0;
        }

        Integer next_frame() {
            if (index < sequence.size()) {
                int frame = sequence.get(index);
                index += 1;
                return frame;
            }
            return null;
        }

        boolean check_threshold(int frame) {
            return frame > threshold;
        }
    }

    static class SequenceAnalyzer {
        FrameTracker tracker;

        SequenceAnalyzer(FrameTracker tracker) {
            this.tracker = tracker;
        }

        boolean analyze() {
            while (true) {
                Integer frame = tracker.next_frame();
                if (frame == null) {
                    break;
                }
                if (tracker.check_threshold(frame)) {
                    return true;
                }
            }
            return false;
        }
    }

    public static void main(String[] args) {
        List<Integer> sequence = List.of(1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21);
        int threshold = 10;
        FrameTracker tracker = new FrameTracker(sequence, threshold);
        SequenceAnalyzer analyzer = new SequenceAnalyzer(tracker);
        boolean result = analyzer.analyze();
        System.out.println(result);
    }
}