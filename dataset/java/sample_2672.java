import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import org.apache.commons.math3.stat.inference.TTest;

public class sample_2672 {

    static class BiostatisticalAnalysis {
        double[] data1;
        double[] data2;

        BiostatisticalAnalysis(double[] data1, double[] data2) {
            this.data1 = data1;
            this.data2 = data2;
        }

        List<Double> calculate_p_values() {
            List<Double> p_values = new ArrayList<>();
            List<Integer> indices = IntStream.range(0, data1.length + data2.length).boxed().collect(Collectors.toList());
            for (List<Integer> perm : permutations(indices)) {
                List<Double> perm_data1 = new ArrayList<>();
                List<Double> perm_data2 = new ArrayList<>();
                for (int i : perm) {
                    if (i < data1.length) {
                        perm_data1.add(data1[i]);
                    } else {
                        perm_data2.add(data2[i - data1.length]);
                    }
                }
                for (int i : perm) {
                    if (i >= data1.length) {
                        perm_data2.add(data2[i - data1.length]);
                    } else {
                        perm_data1.add(data1[i]);
                    }
                }
                TTest tTest = new TTest();
                double p_value = tTest.tTest(perm_data1.stream().mapToDouble(Double::doubleValue).toArray(),
                        perm_data2.stream().mapToDouble(Double::doubleValue).toArray());
                p_values.add(p_value);
            }
            return p_values;
        }

        double[] analyze() {
            List<Double> p_values = calculate_p_values();
            double mean = p_values.stream().mapToDouble(Double::doubleValue).average().orElse(0.0);
            double median = p_values.stream().sorted().get(p_values.size() / 2);
            double std_dev = Math.sqrt(p_values.stream().mapToDouble(d -> Math.pow(d - mean, 2)).average().orElse(0.0));
            return new double[]{mean, median, std_dev};
        }
    }

    static class DataGenerator {
        int size1;
        int size2;

        DataGenerator(int size1, int size2) {
            this.size1 = size1;
            this.size2 = size2;
        }

        double[][] generate_data() {
            Random random = new Random();
            double[] data1 = IntStream.range(0, size1).mapToDouble(i -> random.nextGaussian()).toArray();
            double[] data2 = IntStream.range(0, size2).mapToDouble(i -> random.nextGaussian() + 0.5).toArray();
            return new double[][]{data1, data2};
        }
    }

    static List<List<Integer>> permutations(List<Integer> list) {
        if (list.size() == 0) {
            List<List<Integer>> result = new ArrayList<>();
            result.add(new ArrayList<>());
            return result;
        }
        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < list.size(); i++) {
            List<Integer> remaining = new ArrayList<>(list);
            Integer element = remaining.remove(i);
            for (List<Integer> permutation : permutations(remaining)) {
                permutation.add(0, element);
                result.add(permutation);
            }
        }
        return result;
    }

    public static void main(String[] args) {
        DataGenerator data_gen = new DataGenerator(30, 30);
        double[][] data = data_gen.generate_data();
        BiostatisticalAnalysis biostat_analysis = new BiostatisticalAnalysis(data[0], data[1]);
        double[] results = biostat_analysis.analyze();
        System.out.printf("Mean: %.4f, Median: %.4f, Standard Deviation: %.4f%n", results[0], results[1], results[2]);
    }
}