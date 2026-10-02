import java.util.ArrayList;
import java.util.List;

public class sample_2885 {

    static Iterable<List<Integer>> generate_sequence(int a, int b, int c, int n) {
        List<Integer> sequence = new ArrayList<>();
        sequence.add(a);
        sequence.add(b);
        sequence.add(c);
        return () -> new java.util.Iterator<List<Integer>>() {
            @Override
            public boolean hasNext() {
                return true;
            }

            @Override
            public List<Integer> next() {
                int next_value = sequence.get(sequence.size() - 1) + sequence.get(sequence.size() - 2) + sequence.get(sequence.size() - 3);
                sequence.add(next_value);
                if (sequence.size() > n) {
                    sequence.remove(0);
                }
                List<Integer> processed = new ArrayList<>();
                for (int x : sequence) {
                    processed.add(x * 2);
                }
                return processed;
            }
        };
    }

    static void main() {
        Iterable<List<Integer>> seq = generate_sequence(1, 1, 1, 10);
        java.util.Iterator<List<Integer>> signal_processor = seq.iterator();
        for (int i = 0; i < 100; i++) {
            System.out.println(signal_processor.next());
        }
    }

    public static void main(String[] args) {
        main();
    }
}