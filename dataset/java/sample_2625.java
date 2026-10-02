public class sample_2625 {

    static class SequenceGenerator {
        int start;
        int end;

        SequenceGenerator(int start, int end) {
            this.start = start;
            this.end = end;
        }

        int[] generate_sequence() {
            int[] sequence = new int[end - start + 1];
            for (int i = 0; i < sequence.length; i++) {
                sequence[i] = start + i;
            }
            return sequence;
        }
    }

    static class OptimizationModel {
        int[] sequence;

        OptimizationModel(int[] sequence) {
            this.sequence = sequence;
        }

        double calculate_optimal_solution() {
            int max_value = Integer.MIN_VALUE;
            int min_value = Integer.MAX_VALUE;
            for (int value : sequence) {
                if (value > max_value) {
                    max_value = value;
                }
                if (value < min_value) {
                    min_value = value;
                }
            }
            return (max_value + min_value) / 2.0;
        }
    }

    static class ResultAnalyzer {
        double optimal_value;

        ResultAnalyzer(double optimal_value) {
            this.optimal_value = optimal_value;
        }

        String analyze_result() {
            if (optimal_value > 50) {
                return 'High efficiency';
            } else if (optimal_value > 25) {
                return 'Moderate efficiency';
            } else {
                return 'Low efficiency';
            }
        }
    }

    public static void main(String[] args) {
        int start = 1;
        int end = 100;
        SequenceGenerator generator = new SequenceGenerator(start, end);
        int[] sequence = generator.generate_sequence();
        OptimizationModel model = new OptimizationModel(sequence);
        double optimal_value = model.calculate_optimal_solution();
        ResultAnalyzer analyzer = new ResultAnalyzer(optimal_value);
        String result = analyzer.analyze_result();
        System.out.println(result);
    }
}