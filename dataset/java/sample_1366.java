import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1366 {
    public static void main(String[] args) {
        int initialSize = 100;
        double mutationRate = 0.1;
        List<Double> data = generateData(initialSize);
        List<Double> mutatedData = mutateData(data, mutationRate);
        double[] result = analyzeData(mutatedData);
        System.out.println("Average: " + result[0] + ", Variance: " + result[1]);
    }

    public static List<Double> generateData(int size) {
        List<Double> data = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < size; i++) {
            data.add(random.nextDouble() * 20 - 10);
        }
        return data;
    }

    public static List<Double> mutateData(List<Double> data, double mutationRate) {
        List<Double> mutatedData = new ArrayList<>();
        Random random = new Random();
        for (double value : data) {
            if (random.nextDouble() < mutationRate) {
                mutatedData.add(value * (random.nextDouble() * 1 + 0.5));
            } else {
                mutatedData.add(value);
            }
        }
        return mutatedData;
    }

    public static double[] analyzeData(List<Double> data) {
        double sum = 0;
        for (double value : data) {
            sum += value;
        }
        double average = sum / data.size();

        double varianceSum = 0;
        for (double value : data) {
            varianceSum += Math.pow(value - average, 2);
        }
        double variance = varianceSum / data.size();

        return new double[]{average, variance};
    }
}