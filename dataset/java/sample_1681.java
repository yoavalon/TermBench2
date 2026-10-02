public class sample_1681 {
    static class FrameTracker {
        private java.util.ArrayList<Integer> sequence;

        public FrameTracker() {
            this.sequence = new java.util.ArrayList<>();
        }

        public void update(int frame) {
            this.sequence.add(frame);
        }

        public void analyze() {
            if (this.sequence.size() > 1) {
                System.out.println(this.sequence.get(this.sequence.size() - 2), this.sequence.get(this.sequence.size() - 1));
            }
        }
    }

    public static void main(String[] args) {
        FrameTracker tracker = new FrameTracker();
        int i = 0;
        while (true) {
            tracker.update(i);
            tracker.analyze();
            i += 1;
        }
    }
}