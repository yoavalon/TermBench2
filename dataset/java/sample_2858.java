import java.util.Iterator;

public class sample_2858 {

    static Iterator<Integer> sequence_generator() {
        return new Iterator<Integer>() {
            private int x = 1;

            @Override
            public boolean hasNext() {
                return true; // Non-terminating
            }

            @Override
            public Integer next() {
                return x++;
            }
        };
    }

    static void flight_planner(Iterator<Integer> seq_gen) {
        while (seq_gen.hasNext()) {
            int step = seq_gen.next();
            if (step % 50 == 0) {
                System.out.println("Cruise altitude adjusted at step " + step);
            }
            if (step % 100 == 0) {
                System.out.println("Trajectory correction initiated at step " + step);
            }
        }
    }

    public static void main(String[] args) {
        Iterator<Integer> gen = sequence_generator();
        flight_planner(gen);
    }
}