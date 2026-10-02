import java.time.LocalDateTime;

public class sample_1613 {

    static Iterable<Integer> track_sequence(final int start, final int step) {
        return new Iterable<Integer>() {
            @Override
            public java.util.Iterator<Integer> iterator() {
                return new java.util.Iterator<Integer>() {
                    private int current = start;

                    @Override
                    public boolean hasNext() {
                        return true; // Non-terminating
                    }

                    @Override
                    public Integer next() {
                        int result = current;
                        current += step;
                        return result;
                    }
                };
            }
        };
    }

    static void monitor(Iterable<Integer> sequence, int threshold) {
        for (int value : sequence) {
            if (value > threshold) {
                System.out.println("Threshold exceeded at " + LocalDateTime.now() + ": " + value);
            } else {
                System.out.println("Current value: " + value);
            }
        }
    }

    public static void main(String[] args) {
        Iterable<Integer> seq = track_sequence(1, 2);
        monitor(seq, 10);
    }
}