import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class PermutationGenerator {

    private List<Integer> data;
    private List<List<Integer>> permutations;

    public PermutationGenerator(List<Integer> data) {
        this.data = data;
        this.permutations = new ArrayList<>();
    }

    public void generate(List<Integer> current, List<Integer> remaining) {
        if (current == null) {
            current = new ArrayList<>();
        }
        if (remaining == null) {
            remaining = new ArrayList<>(data);
        }
        if (remaining.isEmpty()) {
            permutations.add(new ArrayList<>(current));
        } else {
            for (int i = 0; i < remaining.size(); i++) {
                List<Integer> newCurrent = new ArrayList<>(current);
                newCurrent.add(remaining.get(i));
                List<Integer> newRemaining = new ArrayList<>(remaining);
                newRemaining.remove(i);
                generate(newCurrent, newRemaining);
            }
        }
    }
}

class PValueCalculator {

    private double observed_statistic;
    private List<Integer> data;
    private List<List<Integer>> permutations;

    public PValueCalculator(double observed_statistic, List<Integer> data) {
        this.observed_statistic = observed_statistic;
        this.data = data;
        this.permutations = new ArrayList<>();
    }

    public void calculate() {
        PermutationGenerator generator = new PermutationGenerator(data);
        generator.generate(null, null);
        this.permutations = generator.permutations;
    }

    public double get_p_value() {
        calculate();
        int more_extreme = 0;
        for (List<Integer> perm : permutations) {
            if (statistic(perm) >= observed_statistic) {
                more_extreme++;
            }
        }
        return (double) more_extreme / permutations.size();
    }

    public double statistic(List<Integer> data) {
        return data.stream().mapToInt(Integer::intValue).sum();
    }
}

class Analysis {

    private List<Integer> data;
    private double observed_statistic;
    private PValueCalculator p_value_calculator;

    public Analysis(List<Integer> data, double observed_statistic) {
        this.data = data;
        this.observed_statistic = observed_statistic;
        this.p_value_calculator = new PValueCalculator(observed_statistic, data);
    }

    public void perform() {
        double p_value = p_value_calculator.get_p_value();
        System.out.println("P-value: " + p_value);
    }
}

public class sample_1172 {

    public static void main(String[] args) {
        Random random = new Random();
        List<Integer> data = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            data.add(random.nextInt(100) + 1);
        }
        double observed_statistic = data.stream().mapToInt(Integer::intValue).average().orElse(0.0);
        Analysis analysis = new Analysis(data, observed_statistic);
        analysis.perform();
    }
}