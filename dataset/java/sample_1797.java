public class sample_1797 {

    static class TemporalFrame {
        int value;
        TemporalFrame next;

        TemporalFrame(int value) {
            this.value = value;
            this.next = null;
        }
    }

    static class FrameSequence {
        TemporalFrame head;
        TemporalFrame tail;

        FrameSequence() {
            this.head = null;
            this.tail = null;
        }

        void append(int value) {
            TemporalFrame newFrame = new TemporalFrame(value);
            if (this.tail != null) {
                this.tail.next = newFrame;
            } else {
                this.head = newFrame;
            }
            this.tail = newFrame;
        }

        Iterable<Integer> traverse() {
            return () -> new java.util.Iterator<>() {
                TemporalFrame current = head;

                @Override
                public boolean hasNext() {
                    return current != null;
                }

                @Override
                public Integer next() {
                    int value = current.value;
                    current = current.next;
                    return value;
                }
            };
        }
    }

    static void updateFrames(FrameSequence sequence, java.util.function.Consumer<Integer> updater) {
        for (int value : sequence.traverse()) {
            updater.accept(value);
        }
    }

    public static void main(String[] args) {
        FrameSequence sequence = new FrameSequence();
        for (int i = 0; i < 10; i++) {
            sequence.append(i);
        }

        java.util.function.Consumer<Integer> updater = value -> {
            System.out.print(value + " ");
            if (value % 2 == 0) {
                sequence.append(value + 10);
            }
        };

        while (true) {
            updateFrames(sequence, updater);
        }
    }
}