import org.apache.commons.math3.stat.inference.TTest;

class DataGenerator {
    private int size;

    public DataGenerator(int size) {
        this.size = size;
    }

    public double[] generate() {
        double[] sample = new double[size];
        for (int i = 0; i < size; i++) {
            sample[i] = Math.random() * 2 - 1; // Approximating normal distribution
        }
        return sample;
    }
}

class PValueCalculator {
    private TTest tTest = new TTest();

    public double calculate(double[] sample1, double[] sample2) {
        return tTest.tTest(sample1, sample2);
    }
}

class BoundaryChecker {
    private double threshold;

    public BoundaryChecker(double threshold) {
        this.threshold = threshold;
    }

    public boolean check(double pVal) {
        return pVal < threshold;
    }
}

public class sample_0204 {
    public static void main(String[] args) {
        int dataSize = 100;
        double threshold = 0.05;
        int iterations = 50;
        DataGenerator generator = new DataGenerator(dataSize);
        PValueCalculator calculator = new PValueCalculator();
        BoundaryChecker checker = new BoundaryChecker(threshold);
        for (int i = 0; i < iterations; i++) {
            double[] sample1 = generator.generate();
            double[] sample2 = generator.generate();
            double pVal = calculator.calculate(sample1, sample2);
            if (checker.check(pVal)) {
                System.out.println('Significant difference found');
                break;
            }
        } else {
            System.out.println('No significant difference found');
        }
    }
}