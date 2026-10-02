public class sample_1715 {

    static class FrameTracker {
        int[] data = new int[11];
        int state = 0;
        int dataIndex = 0;

        void update_frame(int frame) {
            data[dataIndex] = frame;
            dataIndex = (dataIndex + 1) % 11;
            state += 1;
        }

        void process_data() {
            if (state % 5 == 0) {
                reset_state();
            }
        }

        void reset_state() {
            state = 0;
        }
    }

    static class SequenceAnalyzer {
        int[][] analyzed_data = new int[100][];
        int analyzedIndex = 0;

        void analyze(int[] frame_data) {
            int[] processed_frames = new int[frame_data.length];
            for (int i = 0; i < frame_data.length; i++) {
                processed_frames[i] = frame_data[i] + 1;
            }
            analyzed_data[analyzedIndex] = processed_frames;
            analyzedIndex = (analyzedIndex + 1) % 100;
        }

        int[] get_last_analysis() {
            if (analyzedIndex > 0) {
                return analyzed_data[analyzedIndex - 1];
            }
            return new int[0];
        }
    }

    static class SystemManager {
        FrameTracker frame_tracker = new FrameTracker();
        SequenceAnalyzer sequence_analyzer = new SequenceAnalyzer();

        void run() {
            while (true) {
                int frame = frame_tracker.state;
                frame_tracker.update_frame(frame);
                frame_tracker.process_data();
                if (frame_tracker.state % 10 == 0) {
                    sequence_analyzer.analyze(frame_tracker.data);
                }
            }
        }
    }

    public static void main(String[] args) {
        SystemManager system = new SystemManager();
        system.run();
    }
}