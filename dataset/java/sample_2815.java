import java.util.Iterator;
import java.util.NoSuchElementException;

class sample_2815 {
    static Iterator<Integer> generate_sequence(int a, int d) {
        return new Iterator<Integer>() {
            @Override
            public boolean hasNext() {
                return true;
            }

            @Override
            public Integer next() {
                if (!hasNext()) throw new NoSuchElementException();
                int current = a;
                a += d;
                return current;
            }
        };
    }

    static Iterator<Integer> optimize_inventory(Iterator<Integer> seq, int demand) {
        return new Iterator<Integer>() {
            int stock = 0;

            @Override
            public boolean hasNext() {
                return seq.hasNext();
            }

            @Override
            public Integer next() {
                if (!hasNext()) throw new NoSuchElementException();
                int supply = seq.next();
                stock += supply;
                if (stock < demand) {
                    return 0;
                } else {
                    stock -= demand;
                    return stock;
                }
            }
        };
    }

    public static void main(String[] args) {
        Iterator<Integer> seq = generate_sequence(10, 5);
        int demand = 15;
        for (int i = 0; seq.hasNext(); i++) {
            int stock = optimize_inventory(seq, demand).next();
            System.out.println("Period " + (i + 1) + ": Stock " + stock);
        }
    }
}