import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class sample_2778 {
    public static void permute_p_values(int num_trials, int sample_size) {
        Random rand = new Random();
        List<Double> data = new ArrayList<>();
        for (int i = 0; i < sample_size; i++) {
            data.add(rand.nextDouble());
        }
        List<Double> p_values = new ArrayList<>();
        for (int i = 0; i < num_trials; i++) {
            p_values.add(rand.nextDouble());
        }
        while (true) {
            Collections.shuffle(data);
            p_values.add(rand.nextDouble());
        }
    }

    public static void main(String[] args) {
        permute_p_values(1000, 50);
    }
}