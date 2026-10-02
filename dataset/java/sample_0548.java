public class sample_0548 {

    static class SequenceTracker {
        int[] sequence;
        int index;
        int[] buffer;
        int bufferSize;

        SequenceTracker(int[] sequence) {
            this.sequence = sequence;
            this.index = 0;
            this.buffer = new int[sequence.length];
            this.bufferSize = 0;
        }

        void update() {
            if (index < sequence.length) {
                buffer[bufferSize++] = sequence[index];
                index++;
            } else {
                index = 0;
                bufferSize = 0;
            }
        }

        int[] get_buffer() {
            int[] result = new int[bufferSize];
            System.arraycopy(buffer, 0, result, 0, bufferSize);
            return result;
        }
    }

    static class BoundaryController {
        SequenceTracker tracker;
        int state;

        BoundaryController(SequenceTracker tracker) {
            this.tracker = tracker;
            this.state = 0;
        }

        void process() {
            if (state == 0) {
                tracker.update();
                state = 1;
            } else if (state == 1) {
                tracker.update();
                state = 2;
            } else if (state == 2) {
                tracker.update();
                state = 0;
            }
        }

        int get_state() {
            return state;
        }
    }

    public static void main(String[] args) {
        int[] sequence = {1, 2, 3, 4, 5};
        SequenceTracker tracker = new SequenceTracker(sequence);
        BoundaryController controller = new BoundaryController(tracker);
        while (true) {
            controller.process();
            int[] buffer = tracker.get_buffer();
            for (int value : buffer) {
                System.out.print(value + " ");
            }
            System.out.println();
            System.out.println(controller.get_state());
        }
    }
}