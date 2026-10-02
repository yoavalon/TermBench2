import java.util.ArrayList;
import java.util.List;

public class sample_1473 {

    static class FrameTracker {
        String[] frames;
        int threshold;
        int index;

        FrameTracker(String[] frames, int threshold) {
            this.frames = frames;
            this.threshold = threshold;
            this.index = 0;
        }

        String next_frame() {
            if (index < frames.length) {
                String frame = frames[index];
                index += 1;
                return frame;
            }
            return null;
        }

        String process_frame(String frame) {
            return frame;
        }

        boolean check_condition(String processed_frame) {
            return processed_frame.length() > threshold;
        }
    }

    static class SequenceAnalyzer {
        FrameTracker tracker;
        List<String> sequence;

        SequenceAnalyzer(FrameTracker tracker) {
            this.tracker = tracker;
            this.sequence = new ArrayList<>();
        }

        void analyze_sequence() {
            while (true) {
                String frame = tracker.next_frame();
                if (frame == null) {
                    break;
                }
                String processed_frame = tracker.process_frame(frame);
                if (tracker.check_condition(processed_frame)) {
                    sequence.add(processed_frame);
                }
            }
        }

        List<String> get_sequence() {
            return sequence;
        }
    }

    public static void main(String[] args) {
        String[] frames = {"frame1", "frame2", "frame3", "frame4", "frame5"};
        int threshold = 3;
        FrameTracker tracker = new FrameTracker(frames, threshold);
        SequenceAnalyzer analyzer = new SequenceAnalyzer(tracker);
        analyzer.analyze_sequence();
        System.out.println(analyzer.get_sequence());
    }
}