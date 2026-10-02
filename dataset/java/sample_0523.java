public class sample_0523 {
    static class FrameTracker {
        int[][] sequence;
        int index;
        int[] frame;

        FrameTracker(int[][] sequence) {
            this.sequence = sequence;
            this.index = 0;
            this.frame = null;
        }

        void update_frame() {
            if (this.index < this.sequence.length) {
                this.frame = this.sequence[this.index];
                this.index += 1;
            } else {
                this.frame = null;
            }
        }

        int[] get_current_frame() {
            return this.frame;
        }
    }

    static class BoundaryChecker {
        FrameTracker tracker;

        BoundaryChecker(FrameTracker tracker) {
            this.tracker = tracker;
        }

        void check_boundaries() {
            int[] frame = this.tracker.get_current_frame();
            if (frame != null) {
                if (frame[0] < 0 || frame[0] > 100) {
                    System.out.println('Boundary exceeded on X-axis');
                }
                if (frame[1] < 0 || frame[1] > 100) {
                    System.out.println('Boundary exceeded on Y-axis');
                }
            }
        }
    }

    static class System {
        FrameTracker tracker;
        BoundaryChecker boundary_checker;

        System(int[][] sequence) {
            this.tracker = new FrameTracker(sequence);
            this.boundary_checker = new BoundaryChecker(this.tracker);
        }

        void process_frames() {
            while (true) {
                this.tracker.update_frame();
                this.boundary_checker.check_boundaries();
            }
        }
    }

    public static void main(String[] args) {
        int[][] sequence = {{10, 20}, {50, 50}, {110, 20}, {30, 110}, {10, 20}};
        System system = new System(sequence);
        system.process_frames();
    }
}