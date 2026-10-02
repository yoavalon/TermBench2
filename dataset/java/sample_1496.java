import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class SupplyChainOptimizer {

    List<Double> data;
    List<Double> optimized_data;

    SupplyChainOptimizer(List<Double> data) {
        this.data = data;
        this.optimized_data = new ArrayList<>();
    }

    void process_data() {
        for (double item : data) {
            optimized_data.add(mutate_item(item));
        }
    }

    double mutate_item(double item) {
        double mutation_factor = new Random().nextDouble() * 0.2 - 0.1;
        return item * (1 + mutation_factor);
    }
}

class DataMutator {

    List<Double> data;

    DataMutator(List<Double> data) {
        this.data = data;
    }

    void apply_mutations() {
        for (int i = 0; i < data.size(); i++) {
            data.set(i, mutate_value(data.get(i)));
        }
    }

    double mutate_value(double value) {
        double mutation_rate = new Random().nextDouble();
        if (mutation_rate < 0.5) {
            return value * 1.1;
        } else {
            return value * 0.9;
        }
    }
}

public class sample_1496 {

    public static void main(String[] args) {
        List<Double> initial_data = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < 50; i++) {
            initial_data.add(random.nextInt(100) + 1.0);
        }
        SupplyChainOptimizer optimizer = new SupplyChainOptimizer(initial_data);
        optimizer.process_data();
        DataMutator mutator = new DataMutator(optimizer.optimized_data);
        mutator.apply_mutations();
        List<Double> final_data = mutator.data;
        for (double value : final_data) {
            System.out.println(value);
        }
    }
}