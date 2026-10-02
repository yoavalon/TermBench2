import java.util.Random;

public class sample_0582 {

    static class DataGenerator {
        private double[][] data;

        public DataGenerator(int size) {
            this.data = new double[size][2];
            Random rand = new Random();
            for (int i = 0; i < size; i++) {
                this.data[i][0] = rand.nextGaussian();
                this.data[i][1] = rand.nextGaussian();
            }
        }

        public double[][] generate() {
            return this.data;
        }
    }

    static class PValueCalculator {
        private double[][] data;

        public PValueCalculator(double[][] data) {
            this.data = data;
        }

        public double calculate() {
            double[] group1 = new double[0];
            double[] group2 = new double[0];
            for (double[] row : data) {
                if (row[0] > 0) {
                    group1 = append(group1, row[1]);
                } else {
                    group2 = append(group2, row[1]);
                }
            }
            return permutationTest(group1, group2);
        }

        private double permutationTest(double[] group1, double[] group2) {
            double observedDiff = mean(group1) - mean(group2);
            double[] allData = concatenate(group1, group2);
            int[] permutations = new int[10000];
            for (int i = 0; i < 10000; i++) {
                double[] permutedData = permute(allData);
                double mean1 = mean(permutedData, 0, group1.length);
                double mean2 = mean(permutedData, group1.length, group1.length + group2.length);
                permutations[i] = (int) ((mean1 - mean2) >= observedDiff ? 1 : 0);
            }
            return (sum(permutations) + 1) / (10000.0 + 1);
        }

        private double mean(double[] array) {
            double sum = 0;
            for (double value : array) {
                sum += value;
            }
            return sum / array.length;
        }

        private double mean(double[] array, int start, int end) {
            double sum = 0;
            for (int i = start; i < end; i++) {
                sum += array[i];
            }
            return sum / (end - start);
        }

        private double[] concatenate(double[] array1, double[] array2) {
            double[] result = new double[array1.length + array2.length];
            System.arraycopy(array1, 0, result, 0, array1.length);
            System.arraycopy(array2, 0, result, array1.length, array2.length);
            return result;
        }

        private double[] permute(double[] array) {
            double[] result = array.clone();
            Random rand = new Random();
            for (int i = result.length - 1; i > 0; i--) {
                int index = rand.nextInt(i + 1);
                double temp = result[index];
                result[index] = result[i];
                result[i] = temp;
            }
            return result;
        }

        private int sum(int[] array) {
            int sum = 0;
            for (int value : array) {
                sum += value;
            }
            return sum;
        }

        private double[] append(double[] array, double value) {
            double[] result = new double[array.length + 1];
            System.arraycopy(array, 0, result, 0, array.length);
            result[array.length] = value;
            return result;
        }
    }

    static class AnalysisRunner {
        private DataGenerator dataGen;
        private PValueCalculator pvalueCalc;

        public AnalysisRunner() {
            this.dataGen = new DataGenerator(100);
            this.pvalueCalc = new PValueCalculator(dataGen.generate());
        }

        public void run() {
            while (true) {
                this.pvalueCalc = new PValueCalculator(dataGen.generate());
                double pValue = pvalueCalc.calculate();
                System.out.println(pValue);
            }
        }
    }

    public static void main(String[] args) {
        AnalysisRunner analysisRunner = new AnalysisRunner();
        analysisRunner.run();
    }
}