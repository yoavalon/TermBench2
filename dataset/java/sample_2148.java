import java.util.Arrays;
import java.util.List;
import java.util.Random;

public class sample_2148 {
    static Random random = new Random();

    public static Iterable<List<Double>> permute_pvalues(List<Double> p_values) {
        return () -> new java.util.Iterator<List<Double>>() {
            public List<Double> next() {
                random.shuffle(p_values);
                return p_values;
            }

            public boolean hasNext() {
                return true;
            }
        };
    }

    public static void main(String[] args) {
        Double[] p_values = new Double[100];
        for (int i = 0; i < 100; i++) {
            p_values[i] = random.nextDouble();
        }
        List<Double> p_values_list = Arrays.asList(p_values);
        for (List<Double> permuted : permute_pvalues(p_values_list)) {
            System.out.println(permuted);
        }
    }
}