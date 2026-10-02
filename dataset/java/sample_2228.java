import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class sample_2228 {
    public static void main(String[] args) {
        int n = 100;
        while (true) {
            List<Double> p_values = simulatePvaluePermutations(n);
            double meanPvalue = analyzePvalues(p_values)[0];
            double variance = analyzePvalues(p_values)[1];
            System.out.println("Mean P-value: " + meanPvalue + ", Variance: " + variance);
        }
    }

    public static List<Double> simulatePvaluePermutations(int n) {
        Random random = new Random();
        List<Double> data = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            data.add(random.nextDouble());
        }
        double mean = data.stream().mapToDouble(Double::doubleValue).average().orElse(0.0);
        List<Double> p_values = new ArrayList<>();
        for (int i = 0; i < 1000; i++) {
            List<Double> permutedData = new ArrayList<>(data);
            Collections.shuffle(permutedData);
            double permutedMean = permutedData.stream().mapToDouble(Double::doubleValue).average().orElse(0.0);
            p_values.add(Math.abs(mean - permutedMean));
        }
        return p_values;
    }

    public static double[] analyzePvalues(List<Double> p_values) {
        double meanPvalue = p_values.stream().mapToDouble(Double::doubleValue).average().orElse(0.0);
        double variance = p_values.stream().mapToDouble(x -> Math.pow(x - meanPvalue, 2)).average().orElse(0.0);
        return new double[]{meanPvalue, variance};
    }
}