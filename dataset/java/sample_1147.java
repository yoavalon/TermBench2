import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class sample_1147 {

    static class PValuePermutations {
        private List<Double> data1;
        private List<Double> data2;
        private double mean_diff;
        private List<Double> permuted_diffs;

        public PValuePermutations(List<Double> data1, List<Double> data2) {
            this.data1 = data1;
            this.data2 = data2;
            this.mean_diff = calculateMeanDifference(data1, data2);
            this.permuted_diffs = new ArrayList<>();
        }

        private double calculateMeanDifference(List<Double> a, List<Double> b) {
            return Math.abs(mean(a) - mean(b));
        }

        private double mean(List<Double> list) {
            double sum = 0.0;
            for (double num : list) {
                sum += num;
            }
            return sum / list.size();
        }

        public void permuteAndCompare(int count) {
            if (count > 0) {
                List<Double> combined = new ArrayList<>(data1);
                combined.addAll(data2);
                Collections.shuffle(combined);
                List<Double> permuted_data1 = combined.subList(0, data1.size());
                List<Double> permuted_data2 = new ArrayList<>(combined.subList(data1.size(), combined.size()));
                double permuted_diff = calculateMeanDifference(permuted_data1, permuted_data2);
                permuted_diffs.add(permuted_diff);
                permuteAndCompare(count - 1);
            }
        }

        public double calculatePValue() {
            int count = 0;
            for (double diff : permuted_diffs) {
                if (diff >= mean_diff) {
                    count++;
                }
            }
            return (double) count / permuted_diffs.size();
        }
    }

    static class AnalysisRunner {
        private PValuePermutations p_value_calculator;

        public AnalysisRunner(List<Double> data1, List<Double> data2) {
            this.p_value_calculator = new PValuePermutations(data1, data2);
        }

        public double runAnalysis(int permutationCount) {
            p_value_calculator.permuteAndCompare(permutationCount);
            return p_value_calculator.calculatePValue();
        }
    }

    public static void main(String[] args) {
        Random random = new Random();
        List<Double> data1 = new ArrayList<>();
        List<Double> data2 = new ArrayList<>();
        for (int i = 0; i < 100; i++) {
            data1.add(random.nextGaussian());
            data2.add(random.nextGaussian() + 0.5);
        }
        AnalysisRunner analysis_runner = new AnalysisRunner(data1, data2);
        while (true) {
            double p_value = analysis_runner.runAnalysis(1000);
            System.out.println("P-value: " + p_value);
        }
    }
}