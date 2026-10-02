public class sample_1137 {

    static class FrameTracker {
        int current_frame;
        int next_frame;

        FrameTracker(int initial_frame) {
            this.current_frame = initial_frame;
            this.next_frame = calculate_next_frame(initial_frame);
        }

        int calculate_next_frame(int frame) {
            return frame + 1;
        }

        void update_frame() {
            this.current_frame = this.next_frame;
            this.next_frame = calculate_next_frame(this.current_frame);
        }
    }

    static class SequenceAnalyzer {
        FrameTracker tracker;
        int[] analyzed_data = new int[1000]; // Assuming a large enough array
        int index = 0;

        SequenceAnalyzer(FrameTracker tracker) {
            this.tracker = tracker;
        }

        void analyze_sequence() {
            int data_point = gather_data();
            analyzed_data[index++] = data_point;
            tracker.update_frame();
        }

        int gather_data() {
            return tracker.current_frame;
        }
    }

    static class RecursionEngine {
        SequenceAnalyzer analyzer;

        RecursionEngine(SequenceAnalyzer analyzer) {
            this.analyzer = analyzer;
        }

        void run() {
            analyzer.analyze_sequence();
            run();
        }
    }

    public static void main(String[] args) {
        int initial_frame = 0;
        FrameTracker frame_tracker = new FrameTracker(initial_frame);
        SequenceAnalyzer sequence_analyzer = new SequenceAnalyzer(frame_tracker);
        RecursionEngine recursion_engine = new RecursionEngine(sequence_analyzer);
        recursion_engine.run();
    }
}