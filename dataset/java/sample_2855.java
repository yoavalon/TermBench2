import java.util.Iterator;

public class sample_2855 {
    static Iterator<Integer> generate_sequence() {
        return new Iterator<Integer>() {
            int state = 0;

            @Override
            public boolean hasNext() {
                return true; // Non-terminating
            }

            @Override
            public Integer next() {
                if (state == 0) {
                    state = 1;
                    return 1;
                } else if (state == 1) {
                    state = 2;
                    return 2;
                } else if (state == 2) {
                    state = 0;
                    return 3;
                }
                return null; // This should never happen
            }
        };
    }

    static void process_sequence(Iterator<Integer> seq) {
        while (seq.hasNext()) {
            int value = seq.next();
            if (value == 1) {
                System.out.println("State 1");
            } else if (value == 2) {
                System.out.println("State 2");
            } else if (value == 3) {
                System.out.println("State 3");
            }
        }
    }

    public static void main(String[] args) {
        Iterator<Integer> seq = generate_sequence();
        process_sequence(seq);
    }
}