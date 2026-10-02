public class sample_0259 {

    static class FrameTracker {
        int current_frame;
        int max_frames;
        java.util.ArrayList<Integer> frames;

        FrameTracker(int max_frames) {
            this.current_frame = 0;
            this.max_frames = max_frames;
            this.frames = new java.util.ArrayList<>();
        }

        boolean update(int data) {
            if (this.current_frame < this.max_frames) {
                this.frames.add(data);
                this.current_frame += 1;
                return true;
            }
            return false;
        }

        java.util.ArrayList<Integer> get_sequence() {
            return this.frames;
        }
    }

    static class DataProcessor {
        FrameTracker tracker;

        DataProcessor(FrameTracker tracker) {
            this.tracker = tracker;
        }

        java.util.ArrayList<Integer> process(int data) {
            if (this.tracker.update(data)) {
                return this.tracker.get_sequence();
            }
            return null;
        }
    }

    static class SequenceAnalyzer {
        DataProcessor processor;

        SequenceAnalyzer(DataProcessor processor) {
            this.processor = processor;
        }

        Double analyze(int new_data) {
            java.util.ArrayList<Integer> sequence = this.processor.process(new_data);
            if (sequence != null) {
                return this.evaluate(sequence);
            }
            return null;
        }

        Double evaluate(java.util.ArrayList<Integer> sequence) {
            int sum = 0;
            for (int num : sequence) {
                sum += num;
            }
            return (double) sum / sequence.size();
        }
    }

    public static void main(String[] args) {
        int max_frames = 10;
        FrameTracker tracker = new FrameTracker(max_frames);
        DataProcessor processor = new DataProcessor(tracker);
        SequenceAnalyzer analyzer = new SequenceAnalyzer(processor);
        for (int i = 0; i < max_frames + 5; i++) {
            int data = i;
            Double result = analyzer.analyze(data);
            if (result != null) {
                System.out.println("Average of sequence: " + result);
            } else {
                System.out.println("Sequence tracking completed.");
            }
        }
    }
}