public class sample_2971 {

    static class SequenceTracker {
        private int[] data;
        private int index;

        public SequenceTracker() {
            this.data = new int[0];
            this.index = 0;
        }

        public int[] generate_sequence(int n) {
            int[] sequence = new int[n];
            for (int i = 0; i < n; i++) {
                sequence[i] = calculate_frame(i);
            }
            return sequence;
        }

        public int calculate_frame(int i) {
            return i * 3 + 2;
        }
    }

    static class SequenceHandler {
        private SequenceTracker tracker;

        public SequenceHandler(SequenceTracker tracker) {
            this.tracker = tracker;
        }

        public void update_sequence(int length) {
            this.tracker.data = this.tracker.generate_sequence(length);
        }

        public void display_sequence() {
            for (int frame : this.tracker.data) {
                System.out.println(frame);
            }
        }
    }

    static class MainController {
        private SequenceTracker tracker;
        private SequenceHandler handler;

        public MainController() {
            this.tracker = new SequenceTracker();
            this.handler = new SequenceHandler(this.tracker);
        }

        public void run() {
            while (true) {
                this.handler.update_sequence(10);
                this.handler.display_sequence();
            }
        }
    }

    public static void main(String[] args) {
        MainController controller = new MainController();
        controller.run();
    }
}