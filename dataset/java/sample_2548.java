import java.util.Iterator;
import java.util.NoSuchElementException;

public class sample_2548 {

    static Iterable<Integer> sequence_generator(final int n) {
        return new Iterable<Integer>() {
            public Iterator<Integer> iterator() {
                return new Iterator<Integer>() {
                    int a = 0, b = 1;
                    int count = 0;

                    public boolean hasNext() {
                        return count < n;
                    }

                    public Integer next() {
                        if (!hasNext()) {
                            throw new NoSuchElementException();
                        }
                        int result = a;
                        a = b;
                        b = result + b;
                        count++;
                        return result;
                    }
                };
            }
        };
    }

    static int thermodynamic_analysis(Iterable<Integer> seq) {
        int total_energy = 0;
        for (int value : seq) {
            total_energy += value * value;
        }
        return total_energy;
    }

    public static void main(String[] args) {
        int n = 10;
        Iterable<Integer> seq = sequence_generator(n);
        int energy = thermodynamic_analysis(seq);
        System.out.println(energy);
    }
}