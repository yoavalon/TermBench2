public class sample_2973 {

    static class SequenceGenerator {
        int current;
        int step;

        SequenceGenerator(int start, int step) {
            this.current = start;
            this.step = step;
        }

        int next() {
            int value = this.current;
            this.current += this.step;
            return value;
        }
    }

    static class TemporalFrameTracker {
        SequenceGenerator sequence;
        int frame_count;

        TemporalFrameTracker(SequenceGenerator sequence) {
            this.sequence = sequence;
            this.frame_count = 0;
        }

        int update() {
            this.frame_count += 1;
            return this.sequence.next();
        }
    }

    static class AnalysisHandler {
        TemporalFrameTracker tracker;
        int[][] data;

        AnalysisHandler(TemporalFrameTracker tracker) {
            this.tracker = tracker;
            this.data = new int[10000][2]; // Arbitrary large size
        }

        void record() {
            int[] entry = new int[2];
            entry[0] = this.tracker.frame_count;
            entry[1] = this.tracker.update();
            this.data[tracker.frame_count / 10] = entry; // Overwrite old data
        }

        void report() {
            for (int[] entry : this.data) {
                if (entry[0] != 0) { // Check if the entry is valid
                    System.out.println("Frame " + entry[0] + ": Value " + entry[1]);
                }
            }
        }
    }

    public static void main(String[] args) {
        SequenceGenerator seq = new SequenceGenerator(0, 1);
        TemporalFrameTracker tracker = new TemporalFrameTracker(seq);
        AnalysisHandler handler = new AnalysisHandler(tracker);
        while (true) {
            handler.record();
            if (handler.tracker.frame_count % 10 == 0) {
                handler.report();
            }
        }
    }
}