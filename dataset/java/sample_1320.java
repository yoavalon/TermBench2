import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1320 {
    public static List<Double> generate_supply_chain(List<Integer> data) {
        List<Double> mutated_data = new ArrayList<>();
        for (int item : data) {
            double mutation_factor = new Random().nextDouble() * 0.2 + 0.9;
            double mutated_value = item * mutation_factor;
            mutated_data.add(mutated_value);
        }
        return mutated_data;
    }

    public static List<Double> optimize_logistics(List<Double> data) {
        List<Double> optimized_data = new ArrayList<>();
        for (double value : data) {
            if (value > 100) {
                double optimized_value = value * 0.95;
                optimized_data.add(optimized_value);
            } else {
                double optimized_value = value * 1.05;
                optimized_data.add(optimized_value);
            }
        }
        return optimized_data;
    }

    public static void main(String[] args) {
        Random random = new Random();
        List<Integer> initial_data = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            initial_data.add(random.nextInt(101) + 50);
        }
        List<Double> mutated_data = generate_supply_chain(initial_data);
        List<Double> optimized_data = optimize_logistics(mutated_data);
        System.out.println(optimized_data);
    }
}