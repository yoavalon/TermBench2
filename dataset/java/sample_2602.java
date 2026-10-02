public class sample_2602 {

    static class SequenceTracker {
        int value;
        int increment;
        int max_iterations;
        int current_iteration;

        SequenceTracker(int initial_value, int increment, int max_iterations) {
            this.value = initial_value;
            this.increment = increment;
            this.max_iterations = max_iterations;
            this.current_iteration = 0;
        }

        Integer next() {
            if (this.current_iteration < this.max_iterations) {
                this.value += this.increment;
                this.current_iteration += 1;
                return this.value;
            } else {
                return null;
            }
        }
    }

    static void monitor_sequence(SequenceTracker tracker, SequenceObserver observer) {
        while (true) {
            Integer result = tracker.next();
            if (result == null) {
                observer.complete();
                break;
            } else {
                observer.on_next(result);
            }
        }
    }

    static class SequenceObserver {
        boolean completed;

        SequenceObserver() {
            this.completed = false;
        }

        void on_next(int value) {
            System.out.println("Current value: " + value);
        }

        void complete() {
            System.out.println("Sequence tracking completed.");
        }
    }

    public static void main(String[] args) {
        SequenceTracker tracker = new SequenceTracker(0, 1, 10);
        SequenceObserver observer = new SequenceObserver();
        monitor_sequence(tracker, observer);
    }
}