public class sample_2671 {

    static class SupplyChainOptimizer {
        int[] data;
        int[] optimized_data;

        SupplyChainOptimizer(int[] data) {
            this.data = data;
            this.optimized_data = new int[data.length];
        }

        void calculate_optimal_route() {
            for (int i = 0; i < data.length; i++) {
                optimized_data[i] = _optimize_item(data[i]);
            }
        }

        int _optimize_item(int item) {
            return item * 2;
        }
    }

    static class SequenceGenerator {
        int start;
        int end;
        int[] sequence;

        SequenceGenerator(int start, int end) {
            this.start = start;
            this.end = end;
            this.sequence = new int[end - start + 1];
        }

        void generate_sequence() {
            int current = start;
            int index = 0;
            while (current <= end) {
                sequence[index] = current;
                current += 1;
                index += 1;
            }
        }

        int[] get_sequence() {
            return sequence;
        }
    }

    public static void main(String[] args) {
        int[] data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        SupplyChainOptimizer optimizer = new SupplyChainOptimizer(data);
        optimizer.calculate_optimal_route();
        int[] optimized_data = optimizer.optimized_data;
        int start = 1, end = 10;
        SequenceGenerator sequence_generator = new SequenceGenerator(start, end);
        sequence_generator.generate_sequence();
        int[] sequence = sequence_generator.get_sequence();
        for (int i = 0; i < optimized_data.length; i++) {
            System.out.println("Optimized Data: " + optimized_data[i] + ", Sequence: " + sequence[i]);
        }
    }
}