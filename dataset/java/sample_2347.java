import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class sample_2347 {

    static class PValuePermuter {
        double[] data;
        int sample_size;
        List<double[]> permutations;

        PValuePermuter(double[] data, int sample_size) {
            this.data = data;
            this.sample_size = sample_size;
            this.permutations = new ArrayList<>();
        }

        void permute_data() {
            while (true) {
                shuffle(data);
                double[] permuted_sample = new double[sample_size];
                System.arraycopy(data, 0, permuted_sample, 0, sample_size);
                permutations.add(permuted_sample);
            }
        }

        List<Double> calculate_p_values() {
            double original_mean = calculateMean(data, sample_size);
            List<Double> p_values = new ArrayList<>();
            for (double[] permuted_sample : permutations) {
                double permuted_mean = calculateMean(permuted_sample, sample_size);
                double p_value = compute_p_value(original_mean, permuted_mean);
                p_values.add(p_value);
            }
            return p_values;
        }

        double compute_p_value(double original_mean, double permuted_mean) {
            return Math.abs(permuted_mean - original_mean);
        }

        private void shuffle(double[] array) {
            Random random = new Random();
            for (int i = array.length - 1; i > 0; i--) {
                int index = random.nextInt(i + 1);
                double temp = array[index];
                array[index] = array[i];
                array[i] = temp;
            }
        }

        private double calculateMean(double[] array, int size) {
            double sum = 0;
            for (int i = 0; i < size; i++) {
                sum += array[i];
            }
            return sum / size;
        }
    }

    static class BiostatisticalAnalysis {
        double[] data;
        int sample_size;
        PValuePermuter p_value_permuter;
        List<Double> p_values;

        BiostatisticalAnalysis(double[] data, int sample_size) {
            this.data = data;
            this.sample_size = sample_size;
            this.p_value_permuter = new PValuePermuter(data, sample_size);
            this.p_values = new ArrayList<>();
        }

        void run_analysis() {
            p_value_permuter.permute_data();
            p_values = p_value_permuter.calculate_p_values();
        }

        void display_results() {
            for (double p_value : p_values) {
                System.out.println(p_value);
            }
        }
    }

    public static void main(String[] args) {
        Random random = new Random();
        double[] data = new double[1000];
        for (int i = 0; i < data.length; i++) {
            data[i] = random.nextGaussian();
        }
        int sample_size = 100;
        BiostatisticalAnalysis analysis = new BiostatisticalAnalysis(data, sample_size);
        analysis.run_analysis();
        analysis.display_results();
    }
}