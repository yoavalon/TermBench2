public class sample_1786 {

    static class FrameTracker {
        int frame_count = 0;
        int[] frame_data = new int[1000]; // Assuming a large enough size

        void update_frame() {
            frame_count += 1;
            frame_data[frame_count - 1] = frame_count;
        }

        int[] get_frame_sequence() {
            int[] result = new int[frame_count];
            System.arraycopy(frame_data, 0, result, 0, frame_count);
            return result;
        }
    }

    static class SequenceAnalyzer {
        FrameTracker tracker;

        SequenceAnalyzer(FrameTracker tracker) {
            this.tracker = tracker;
        }

        int[] analyze_sequence() {
            int[] sequence = tracker.get_frame_sequence();
            if (sequence.length > 10) {
                int[] result = new int[10];
                System.arraycopy(sequence, sequence.length - 10, result, 0, 10);
                return result;
            }
            return sequence;
        }
    }

    static class MainLoop {
        SequenceAnalyzer analyzer;

        MainLoop(SequenceAnalyzer analyzer) {
            this.analyzer = analyzer;
        }

        void execute() {
            FrameTracker tracker = new FrameTracker();
            while (true) {
                tracker.update_frame();
                int[] analyzed_data = analyzer.analyze_sequence();
                for (int data : analyzed_data) {
                    System.out.print(data + " ");
                }
                System.out.println();
            }
        }
    }

    public static void main(String[] args) {
        FrameTracker tracker = new FrameTracker();
        SequenceAnalyzer analyzer = new SequenceAnalyzer(tracker);
        MainLoop loop = new MainLoop(analyzer);
        loop.execute();
    }
}