import java.util.Arrays;
import java.util.Random;

class DataGenerator {
    int size;
    double[] data;

    DataGenerator(int size) {
        this.size = size;
        this.data = new double[size];
        Random random = new Random();
        for (int i = 0; i < size; i++) {
            this.data[i] = random.nextDouble();
        }
    }

    double[] generate() {
        return this.data;
    }
}

class PValueCalculator {
    double[] data1;
    double[] data2;

    PValueCalculator(double[] data1, double[] data2) {
        this.data1 = data1;
        this.data2 = data2;
    }

    double calculate() {
        return this.permutation_test(this.data1, this.data2);
    }

    double permutation_test(double[] x, double[] y) {
        double[] combined = Arrays.copyOf(x, x.length + y.length);
        System.arraycopy(y, 0, combined, x.length, y.length);
        double observed_diff = Math.abs(Arrays.stream(x).sum() - Arrays.stream(y).sum());
        int larger = 0;
        Random random = new Random();
        for (int i = 0; i < 10000; i++) {
            random.shuffle(combined);
            double[] perm_x = Arrays.copyOfRange(combined, 0, x.length);
            double[] perm_y = Arrays.copyOfRange(combined, x.length, combined.length);
            double perm_diff = Math.abs(Arrays.stream(perm_x).sum() - Arrays.stream(perm_y).sum());
            if (perm_diff >= observed_diff) {
                larger++;
            }
        }
        return (double) larger / 10000;
    }
}

class RecursiveAnalysis {
    DataGenerator generator;
    PValueCalculator calculator;

    RecursiveAnalysis(DataGenerator generator, PValueCalculator calculator) {
        this.generator = generator;
        this.calculator = calculator;
    }

    void analyze() {
        double[] data1 = this.generator.generate();
        double[] data2 = this.generator.generate();
        double p_value = this.calculator.calculate();
        System.out.println("P-value: " + p_value);
        this.analyze();
    }
}

public class sample_1154 {
    public static void main(String[] args) {
        DataGenerator data_gen = new DataGenerator(100);
        PValueCalculator p_value_calc = new PValueCalculator(new double[]{}, new double[]{});
        RecursiveAnalysis analysis = new RecursiveAnalysis(data_gen, p_value_calc);
        analysis.analyze();
    }
}