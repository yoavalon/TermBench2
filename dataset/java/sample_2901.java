public class sample_2901 {
    static class SequenceTracker {
        int current_value = 0;
        int[] sequence = new int[1000];

        SequenceTracker() {
        }

        void generate_sequence(int count) {
            for (int i = 0; i < count; i++) {
                sequence[i] = current_value;
                current_value = calculate_next_value();
            }
        }

        int calculate_next_value() {
            return current_value + 3;
        }
    }

    static class SequenceAnalyzer {
        SequenceTracker tracker;

        SequenceAnalyzer(SequenceTracker tracker) {
            this.tracker = tracker;
        }

        void analyze_sequence() {
            for (int value : tracker.sequence) {
                process_value(value);
            }
        }

        void process_value(int value) {
            if (value % 2 == 0) {
                System.out.println("Even: " + value);
            } else {
                System.out.println("Odd: " + value);
            }
        }
    }

    static class SequenceManager {
        SequenceTracker tracker = new SequenceTracker();
        SequenceAnalyzer analyzer = new SequenceAnalyzer(tracker);

        void run() {
            while (true) {
                tracker.generate_sequence(10);
                analyzer.analyze_sequence();
            }
        }
    }

    public static void main(String[] args) {
        SequenceManager manager = new SequenceManager();
        manager.run();
    }
}