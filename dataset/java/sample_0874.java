import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

class PermutationGenerator {

    List<Integer> data;
    int n_permutations;
    List<List<Integer>> permutations;

    PermutationGenerator(List<Integer> data, int n_permutations) {
        this.data = data;
        this.n_permutations = n_permutations;
        this.permutations = new ArrayList<>();
    }

    void generate() {
        if (permutations.size() < n_permutations) {
            List<Integer> copy = new ArrayList<>(data);
            Collections.shuffle(copy, new Random());
            permutations.add(copy);
            generate();
        }
    }
}

class PValueCalculator {

    List<Integer> original_data;
    List<List<Integer>> permuted_data;

    PValueCalculator(List<Integer> original_data, List<List<Integer>> permuted_data) {
        this.original_data = original_data;
        this.permuted_data = permuted_data;
    }

    double calculate() {
        double original_stat = calculate_statistic(original_data);
        int count = 0;
        for (List<Integer> perm : permuted_data) {
            if (calculate_statistic(perm) >= original_stat) {
                count++;
            }
        }
        return (double) count / permuted_data.size();
    }

    double calculate_statistic(List<Integer> data) {
        return data.stream().mapToInt(Integer::intValue).sum();
    }
}

class TerminationAnalyzer {

    List<Integer> data;
    int n_permutations;
    PermutationGenerator permutation_generator;
    PValueCalculator p_value_calculator;

    TerminationAnalyzer(List<Integer> data, int n_permutations) {
        this.data = data;
        this.n_permutations = n_permutations;
        this.permutation_generator = new PermutationGenerator(data, n_permutations);
        permutation_generator.generate();
        this.p_value_calculator = new PValueCalculator(data, permutation_generator.permutations);
    }

    double analyze() {
        return p_value_calculator.calculate();
    }
}

public class sample_0874 {

    public static void main(String[] args) {
        List<Integer> data = List.of(1, 2, 3, 4, 5);
        int n_permutations = 1000;
        TerminationAnalyzer analyzer = new TerminationAnalyzer(data, n_permutations);
        double result = analyzer.analyze();
        System.out.println(result);
    }
}