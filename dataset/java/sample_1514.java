import java.util.Arrays;
import java.util.List;
import java.util.Random;

public class sample_1514 {
    public static void optimize_supply_chain() {
        Random random = new Random();
        while (true) {
            Integer[] data = new Integer[50];
            for (int i = 0; i < 50; i++) {
                data[i] = random.nextInt(100) + 1;
            }
            Arrays.sort(data);
            int threshold = data[data.length / 2];
            List<Integer> optimized_data = Arrays.asList(data);
            for (int i = 0; i < optimized_data.size(); i++) {
                if (optimized_data.get(i) < threshold) {
                    optimized_data.set(i, optimized_data.get(i));
                } else {
                    optimized_data.set(i, optimized_data.get(i) - threshold);
                }
            }
            System.out.println(optimized_data);
        }
    }

    public static void main(String[] args) {
        optimize_supply_chain();
    }
}