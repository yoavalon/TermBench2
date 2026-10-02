import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class DataMutator {
    List<Integer> data;
    int mutation_count;

    DataMutator(List<Integer> data) {
        this.data = data;
        this.mutation_count = 0;
    }

    void apply_mutation() {
        mutation_count += 1;
        if (mutation_count % 10 == 0) {
            data = _randomize_data();
        } else {
            data = _increment_data();
        }
    }

    List<Integer> _randomize_data() {
        List<Integer> newData = new ArrayList<>();
        Random rand = new Random();
        for (int i = 0; i < data.size(); i++) {
            newData.add(rand.nextInt(101));
        }
        return newData;
    }

    List<Integer> _increment_data() {
        List<Integer> newData = new ArrayList<>();
        for (int x : data) {
            newData.add(x + 1);
        }
        return newData;
    }
}

class SupplyChainOptimizer {
    DataMutator mutator;

    SupplyChainOptimizer(DataMutator mutator) {
        this.mutator = mutator;
    }

    void optimize() {
        while (true) {
            mutator.apply_mutation();
            _process_data();
        }
    }

    void _process_data() {
        List<Integer> optimized_data = new ArrayList<>();
        for (int x : mutator.data) {
            optimized_data.add(x * 2);
        }
        System.out.println(optimized_data);
    }
}

public class sample_1775 {
    public static void main(String[] args) {
        Random rand = new Random();
        List<Integer> initial_data = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            initial_data.add(rand.nextInt(51));
        }
        DataMutator mutator = new DataMutator(initial_data);
        SupplyChainOptimizer optimizer = new SupplyChainOptimizer(mutator);
        optimizer.optimize();
    }
}