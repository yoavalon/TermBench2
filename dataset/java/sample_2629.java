public class sample_2629 {

    static class SequenceGenerator {
        int size;
        int[] sequence;

        SequenceGenerator(int size) {
            this.size = size;
            this.sequence = new int[size];
        }

        void generate_fibonacci() {
            int a = 0, b = 1;
            for (int i = 0; i < size; i++) {
                sequence[i] = a;
                int next = a + b;
                a = b;
                b = next;
            }
        }

        void generate_arithmetic(int diff) {
            for (int i = 0; i < size; i++) {
                sequence[i] = diff * i;
            }
        }

        void generate_geometric(int ratio) {
            for (int i = 0; i < size; i++) {
                sequence[i] = (int) Math.pow(ratio, i);
            }
        }
    }

    static class DataProcessor {
        int[] sequence;

        DataProcessor(int[] sequence) {
            this.sequence = sequence;
        }

        double calculate_mean() {
            int sum = 0;
            for (int num : sequence) {
                sum += num;
            }
            return (double) sum / sequence.length;
        }

        double calculate_median() {
            int[] sortedSeq = sequence.clone();
            java.util.Arrays.sort(sortedSeq);
            int mid = sortedSeq.length / 2;
            return sortedSeq.length % 2 == 0 ? (sortedSeq[mid - 1] + sortedSeq[mid]) / 2.0 : sortedSeq[mid];
        }

        double calculate_variance() {
            double mean = calculate_mean();
            double sum = 0;
            for (int num : sequence) {
                sum += Math.pow(num - mean, 2);
            }
            return sum / sequence.length;
        }
    }

    static class Optimizer {
        DataProcessor processor;

        Optimizer(DataProcessor processor) {
            this.processor = processor;
        }

        java.util.Map<String, Double> optimize_supply_chain() {
            double mean = processor.calculate_mean();
            double median = processor.calculate_median();
            double variance = processor.calculate_variance();
            java.util.Map<String, Double> result = new java.util.HashMap<>();
            result.put("mean", mean);
            result.put("median", median);
            result.put("variance", variance);
            return result;
        }
    }

    public static void main(String[] args) {
        int size = 10;
        int diff = 2;
        int ratio = 3;
        SequenceGenerator generator = new SequenceGenerator(size);
        generator.generate_fibonacci();
        DataProcessor processor = new DataProcessor(generator.sequence);
        Optimizer optimizer = new Optimizer(processor);
        java.util.Map<String, Double> result = optimizer.optimize_supply_chain();
        System.out.println(result);
    }
}