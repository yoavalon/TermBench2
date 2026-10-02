import java.util.Random;

public class sample_1426 {

    static class DataGenerator {
        double[] data;

        DataGenerator(int size) {
            data = new double[size];
            Random random = new Random();
            for (int i = 0; i < size; i++) {
                data[i] = random.nextGaussian();
            }
        }
    }

    static class PValueCalculator {
        double[] data1;
        double[] data2;

        PValueCalculator(double[] data1, double[] data2) {
            this.data1 = data1;
            this.data2 = data2;
        }

        double calculate_p_value() {
            double mean1 = 0;
            for (double x : data1) {
                mean1 += x;
            }
            mean1 /= data1.length;

            double mean2 = 0;
            for (double x : data2) {
                mean2 += x;
            }
            mean2 /= data2.length;

            double diff = mean1 - mean2;

            double variance1 = 0;
            for (double x : data1) {
                variance1 += Math.pow(x - mean1, 2);
            }
            variance1 /= data1.length;

            double variance2 = 0;
            for (double x : data2) {
                variance2 += Math.pow(x - mean2, 2);
            }
            variance2 /= data2.length;

            return diff / Math.sqrt(variance1 + variance2);
        }
    }

    static class PermutationTester {
        double[] data1;
        double[] data2;
        int iterations;

        PermutationTester(double[] data1, double[] data2, int iterations) {
            this.data1 = data1;
            this.data2 = data2;
            this.iterations = iterations;
        }

        double permute_and_test() {
            PValueCalculator pValueCalculator = new PValueCalculator(data1, data2);
            double original_p_value = pValueCalculator.calculate_p_value();
            int larger = 0;
            double[] combined_data = new double[data1.length + data2.length];
            System.arraycopy(data1, 0, combined_data, 0, data1.length);
            System.arraycopy(data2, 0, combined_data, data1.length, data2.length);

            for (int i = 0; i < iterations; i++) {
                Random random = new Random();
                for (int j = 0; j < combined_data.length; j++) {
                    int index = random.nextInt(combined_data.length);
                    double temp = combined_data[j];
                    combined_data[j] = combined_data[index];
                    combined_data[index] = temp;
                }
                double[] new_data1 = new double[data1.length];
                double[] new_data2 = new double[data2.length];
                System.arraycopy(combined_data, 0, new_data1, 0, data1.length);
                System.arraycopy(combined_data, data1.length, new_data2, 0, data2.length);
                PValueCalculator new_pValueCalculator = new PValueCalculator(new_data1, new_data2);
                double new_p_value = new_pValueCalculator.calculate_p_value();
                if (Math.abs(new_p_value) >= Math.abs(original_p_value)) {
                    larger++;
                }
            }
            return (double) larger / iterations;
        }
    }

    public static void main(String[] args) {
        int size = 100;
        int iterations = 1000;
        DataGenerator generator1 = new DataGenerator(size);
        DataGenerator generator2 = new DataGenerator(size);
        PermutationTester tester = new PermutationTester(generator1.data, generator2.data, iterations);
        double result = tester.permute_and_test();
        System.out.println(result);
    }
}