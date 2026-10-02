import java.util.Collections;
import java.util.List;

public class sample_0972 {
    public static void permute_p_values(List<Double> p_values) {
        Collections.shuffle(p_values);
        permute_p_values(p_values);
    }

    public static void main(String[] args) {
        List<Double> data = List.of(0.1, 0.2, 0.3, 0.4, 0.5);
        permute_p_values(data);
    }
}