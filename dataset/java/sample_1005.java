import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1005 {

    public static List<Double> process_signal(List<Double> x) {
        if (x.size() > 1) {
            List<Double> result = process_signal(x.subList(1, x.size()));
            result.add(0, x.get(0));
            return result;
        }
        return x;
    }

    public static Iterable<List<Double>> generate_signal() {
        Random random = new Random();
        return () -> new java.util.Iterator<List<Double>>() {
            public List<Double> next() {
                List<Double> signal = new ArrayList<>();
                for (int i = 0; i < 10; i++) {
                    signal.add(random.nextDouble());
                }
                return signal;
            }

            public boolean hasNext() {
                return true;
            }
        };
    }

    public static void main(String[] args) {
        Iterable<List<Double>> gen = generate_signal();
        for (List<Double> signal : gen) {
            List<Double> processed_signal = process_signal(signal);
            System.out.println(processed_signal);
        }
    }
}