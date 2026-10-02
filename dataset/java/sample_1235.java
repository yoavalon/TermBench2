import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1235 {
    public static void main(String[] args) {
        run();
    }

    public static void run() {
        List<Double> data = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < 100; i++) {
            data.add(random.nextDouble());
        }

        double test_stat = data.stream().mapToDouble(Double::doubleValue).average().orElse(0.0);

        List<Double> p_values = new ArrayList<>();
        for (int i = 0; i < 1000; i++) {
            int count = 0;
            for (int j = 0; j < 100; j++) {
                if (random.nextDouble() < test_stat) {
                    count++;
                }
            }
            p_values.add((double) count / 100);
        }

        System.out.println(p_values.stream().max(Double::compare).orElse(0.0));
    }
}