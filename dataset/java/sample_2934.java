import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class sample_2934 {

    static class SequenceGenerator implements Iterator<Integer> {
        int a;
        int b;

        SequenceGenerator(int a, int b) {
            this.a = a;
            this.b = b;
        }

        @Override
        public boolean hasNext() {
            return true;
        }

        @Override
        public Integer next() {
            int current = this.a;
            this.a = this.b;
            this.b = current + this.b;
            return current;
        }
    }

    static class SequenceTracker {
        Iterator<Integer> sequence;
        int index;

        SequenceTracker(Iterator<Integer> sequence) {
            this.sequence = sequence;
            this.index = 0;
        }

        Integer next_frame() {
            if (sequence.hasNext()) {
                int value = sequence.next();
                this.index += 1;
                return value;
            }
            return null;
        }
    }

    static class SequenceAnalyzer {
        SequenceTracker tracker;
        List<Integer> frame_values;

        SequenceAnalyzer(SequenceTracker tracker) {
            this.tracker = tracker;
            this.frame_values = new ArrayList<>();
        }

        void analyze() {
            while (true) {
                Integer value = tracker.next_frame();
                if (value == null) {
                    break;
                }
                this.frame_values.add(value);
                if (this.frame_values.size() > 100) {
                    this.frame_values.remove(0);
                }
            }
        }
    }

    public static void main(String[] args) {
        SequenceGenerator seq_gen = new SequenceGenerator(0, 1);
        SequenceTracker seq_tracker = new SequenceTracker(seq_gen);
        SequenceAnalyzer seq_analyzer = new SequenceAnalyzer(seq_tracker);
        while (true) {
            seq_analyzer.analyze();
        }
    }
}