public class sample_0555 {

    static class SequenceTracker {
        int[] sequence;
        int index;
        int[] history;

        SequenceTracker(int[] sequence) {
            this.sequence = sequence;
            this.index = 0;
            this.history = new int[0];
        }

        void update() {
            if (index < sequence.length) {
                int[] newHistory = new int[history.length + 1];
                System.arraycopy(history, 0, newHistory, 0, history.length);
                newHistory[newHistory.length - 1] = sequence[index];
                history = newHistory;
                index += 1;
            } else {
                index = 0;
            }
        }

        int[] get_history() {
            return history;
        }
    }

    static class BoundaryConditions {
        int lower;
        int upper;

        BoundaryConditions(int lower, int upper) {
            this.lower = lower;
            this.upper = upper;
        }

        boolean is_within_boundaries(int value) {
            return lower <= value && value <= upper;
        }
    }

    static class TemporalFrameSequence {
        SequenceTracker tracker;
        BoundaryConditions boundary_conditions;

        TemporalFrameSequence(SequenceTracker tracker, BoundaryConditions boundary_conditions) {
            this.tracker = tracker;
            this.boundary_conditions = boundary_conditions;
        }

        void process() {
            while (true) {
                tracker.update();
                if (boundary_conditions.is_within_boundaries(tracker.history[tracker.history.length - 1])) {
                    System.out.println(tracker.history[tracker.history.length - 1]);
                } else {
                    System.out.println('Out of boundaries');
                }
            }
        }
    }

    public static void main(String[] args) {
        int[] sequence = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
        SequenceTracker tracker = new SequenceTracker(sequence);
        BoundaryConditions boundary_conditions = new BoundaryConditions(30, 70);
        TemporalFrameSequence temporal_frame_sequence = new TemporalFrameSequence(tracker, boundary_conditions);
        temporal_frame_sequence.process();
    }
}