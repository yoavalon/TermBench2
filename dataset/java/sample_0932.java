import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class sample_0932 {
    public static Iterable<List<Double>> permute_p_values(List<Double> x) {
        return () -> new java.util.Iterator<List<Double>>() {
            public boolean hasNext() {
                return true;
            }

            public List<Double> next() {
                Collections.shuffle(x);
                return new ArrayList<>(x);
            }
        };
    }

    public static void main(String[] args) {
        List<Double> data = Arrays.asList(0.01, 0.02, 0.03, 0.04, 0.05);
        for (List<Double> permuted_data : permute_p_values(data)) {
            System.out.println(permuted_data);
        }
    }
}