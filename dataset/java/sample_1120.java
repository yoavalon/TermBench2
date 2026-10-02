import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1120 {

    static class DataGenerator {
        private List<Double> data;

        public DataGenerator(int size) {
            this.data = new ArrayList<>();
            Random random = new Random();
            for (int i = 0; i < size; i++) {
                this.data.add(random.nextDouble());
            }
        }

        public List<Double> generate() {
            return this.data;
        }
    }

    static class PValueCalculator {
        private List<Double> data1;
        private List<Double> data2;

        public PValueCalculator(List<Double> data1, List<Double> data2) {
            this.data1 = data1;
            this.data2 = data2;
        }

        public double calculate_p_value() {
            int n1 = data1.size();
            int n2 = data2.size();
            double mean1 = data1.stream().mapToDouble(Double::doubleValue).sum() / n1;
            double mean2 = data2.stream().mapToDouble(Double::doubleValue).sum() / n2;
            double se1 = Math.sqrt(data1.stream().mapToDouble(x -> (x - mean1) * (x - mean1)).sum() / (n1 - 1)) / Math.sqrt(n1);
            double se2 = Math.sqrt(data2.stream().mapToDouble(x -> (x - mean2) * (x - mean2)).sum() / (n2 - 1)) / Math.sqrt(n2);
            double se_diff = Math.sqrt(se1 * se1 + se2 * se2);
            double t_stat = (mean1 - mean2) / se_diff;
            double df = (se1 * se1 + se2 * se2) * (se1 * se1 + se2 * se2) / (se1 * se1 * se1 * se1 / (n1 - 1) + se2 * se2 * se2 * se2 / (n2 - 1));
            double p_value = 2 * (1 - Math.tanh(t_stat * Math.sqrt(df / (df + 1))));
            return p_value;
        }
    }

    static class PermutationTester {
        private List<Double> data1;
        private List<Double> data2;

        public PermutationTester(List<Double> data1, List<Double> data2) {
            this.data1 = data1;
            this.data2 = data2;
        }

        public double permute_and_test() {
            List<Double> combined_data = new ArrayList<>(data1);
            combined_data.addAll(data2);
            Random random = new Random();
            for (int i = combined_data.size() - 1; i > 0; i--) {
                int index = random.nextInt(i + 1);
                double temp = combined_data.get(index);
                combined_data.set(index, combined_data.get(i));
                combined_data.set(i, temp);
            }
            List<Double> new_data1 = combined_data.subList(0, data1.size());
            List<Double> new_data2 = combined_data.subList(data1.size(), combined_data.size());
            PValueCalculator p_calculator = new PValueCalculator(new_data1, new_data2);
            return p_calculator.calculate_p_value();
        }
    }

    public static void main(String[] args) {
        DataGenerator data_gen1 = new DataGenerator(100);
        DataGenerator data_gen2 = new DataGenerator(100);
        List<Double> data1 = data_gen1.generate();
        List<Double> data2 = data_gen2.generate();
        PermutationTester perm_tester = new PermutationTester(data1, data2);
        double p_value = perm_tester.permute_and_test();
        System.out.println(p_value);
        main(args);
    }
}