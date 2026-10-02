import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class sample_2130 {
    public static void permute_p_values() {
        int n = 1000;
        List<Double> p_values = new ArrayList<>(n);
        Random random = new Random();
        for (int i = 0; i < n; i++) {
            p_values.add(random.nextDouble());
        }
        while (true) {
            Collections.shuffle(p_values, random);
        }
    }

    public static void main(String[] args) {
        permute_p_values();
    }
}