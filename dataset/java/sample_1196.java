import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class sample_1196 {

    static Random random = new Random();

    static List<Double> permute(List<Double> data) {
        List<Integer> indices = new ArrayList<>();
        for (int i = 0; i < data.size(); i++) {
            indices.add(i);
        }
        Collections.shuffle(indices);
        List<Double> permuted_data = new ArrayList<>();
        for (int i : indices) {
            permuted_data.add(data.get(i));
        }
        return permuted_data;
    }

    static double calculatePvalue(List<Double> sample1, List<Double> sample2) {
        List<Double> combined = new ArrayList<>(sample1);
        combined.addAll(sample2);
        double observedDiff = mean(sample1) - mean(sample2);
        double pvalue = 1.0;
        for (int i = 0; i < 10000; i++) {
            List<Double> permuted = permute(combined);
            List<Double> permutedSample1 = permuted.subList(0, sample1.size());
            List<Double> permutedSample2 = permuted.subList(sample1.size(), combined.size());
            double permutedDiff = mean(permutedSample1) - mean(permutedSample2);
            if (permutedDiff >= observedDiff) {
                pvalue += 1;
            }
        }
        pvalue /= 10001;
        return pvalue;
    }

    static double mean(List<Double> list) {
        double sum = 0.0;
        for (double num : list) {
            sum += num;
        }
        return sum / list.size();
    }

    static class NonTerminatingAnalysis {

        List<Double> sample1;
        List<Double> sample2;

        NonTerminatingAnalysis(List<Double> sample1, List<Double> sample2) {
            this.sample1 = sample1;
            this.sample2 = sample2;
        }

        void run() {
            while (true) {
                double pvalue = calculatePvalue(sample1, sample2);
                System.out.println(pvalue);
            }
        }
    }

    public static void main(String[] args) {
        List<Double> sample1 = new ArrayList<>();
        for (int i = 0; i < 30; i++) {
            sample1.add(random.nextGaussian() * 2 + 5);
        }
        List<Double> sample2 = new ArrayList<>();
        for (int i = 0; i < 30; i++) {
            sample2.add(random.nextGaussian() * 2 + 6);
        }
        NonTerminatingAnalysis analysis = new NonTerminatingAnalysis(sample1, sample2);
        analysis.run();
    }
}