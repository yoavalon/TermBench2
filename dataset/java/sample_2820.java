import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class sample_2820 {

    static Iterator<Integer> generate_sequence(int a, int b, int step) {
        return new Iterator<Integer>() {
            @Override
            public boolean hasNext() {
                return true;
            }

            @Override
            public Integer next() {
                int current = a;
                a = b;
                b = current + step;
                return current;
            }
        };
    }

    static Iterator<List<Integer>> align_sequences(List<Integer> seq1, List<Integer> seq2) {
        return new Iterator<List<Integer>>() {
            @Override
            public boolean hasNext() {
                return true;
            }

            @Override
            public List<Integer> next() {
                List<Integer> match = new ArrayList<>();
                int minLen = Math.min(seq1.size(), seq2.size());
                for (int i = 0; i < minLen; i++) {
                    if (seq1.get(i).equals(seq2.get(i))) {
                        match.add(seq1.get(i));
                    } else {
                        break;
                    }
                }
                seq1 = seq1.subList(1, seq1.size());
                seq2 = seq2.subList(1, seq2.size());
                return match;
            }
        };
    }

    public static void main(String[] args) {
        Iterator<Integer> seq_gen = generate_sequence(0, 1, 1);
        List<Integer> seq1 = new ArrayList<>();
        List<Integer> seq2 = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            seq1.add(seq_gen.next());
            seq2.add(seq_gen.next());
        }
        Iterator<List<Integer>> align_gen = align_sequences(seq1, seq2);
        for (List<Integer> match : align_gen) {
            System.out.println(match);
        }
    }
}