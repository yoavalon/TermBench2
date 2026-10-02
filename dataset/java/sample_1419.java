import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class SupplyChainOptimizer {
    private List<Double> data;
    private List<Double> optimized_data;

    public SupplyChainOptimizer(List<Double> data) {
        this.data = data;
        this.optimized_data = new ArrayList<>();
    }

    public void process_data() {
        for (Double item : data) {
            this.optimized_data.add(this.mutate_item(item));
        }
    }

    private Double mutate_item(Double item) {
        double mutation_factor = new Random().nextDouble() * 0.4 + 0.8;
        return item * mutation_factor;
    }
}

class DataProcessor {
    private List<Double> data;

    public DataProcessor(List<Double> data) {
        this.data = data;
    }

    public List<Double> normalize_data() {
        double min_val = Double.MAX_VALUE;
        double max_val = Double.MIN_VALUE;
        for (double x : data) {
            if (x < min_val) min_val = x;
            if (x > max_val) max_val = x;
        }
        List<Double> normalized_data = new ArrayList<>();
        for (double x : data) {
            normalized_data.add((x - min_val) / (max_val - min_val));
        }
        return normalized_data;
    }
}

class DataAnalyzer {
    private List<Double> data;

    public DataAnalyzer(List<Double> data) {
        this.data = data;
    }

    public double[] calculate_statistics() {
        double mean = 0;
        for (double x : data) {
            mean += x;
        }
        mean /= data.size();

        double variance = 0;
        for (double x : data) {
            variance += Math.pow(x - mean, 2);
        }
        variance /= data.size();

        return new double[]{mean, variance};
    }
}

public class sample_1419 {
    public static void main(String[] args) {
        List<Double> raw_data = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < 100; i++) {
            raw_data.add(random.nextDouble() * 91 + 10);
        }
        DataProcessor processor = new DataProcessor(raw_data);
        List<Double> normalized_data = processor.normalize_data();
        SupplyChainOptimizer optimizer = new SupplyChainOptimizer(normalized_data);
        optimizer.process_data();
        List<Double> optimized_data = optimizer.optimized_data;
        DataAnalyzer analyzer = new DataAnalyzer(optimized_data);
        double[] stats = analyzer.calculate_statistics();
        System.out.printf("Mean: %.2f, Variance: %.2f%n", stats[0], stats[1]);
    }
}