public class sample_0251 {

    class DataProcessor {
        int[] data;

        DataProcessor(int[] data) {
            this.data = data;
        }

        int[] preprocess() {
            int[] processed_data = new int[data.length];
            int index = 0;
            for (int item : data) {
                if (item > 0) {
                    processed_data[index++] = item;
                }
            }
            return java.util.Arrays.copyOf(processed_data, index);
        }

        int calculate(int[] processed_data) {
            int total = 0;
            for (int item : processed_data) {
                total += item * 2;
            }
            return total;
        }
    }

    class Optimizer {
        int result;

        Optimizer(int result) {
            this.result = result;
        }

        int optimize() {
            return (int) (result * 0.95);
        }
    }

    class TerminationAnalyzer {
        int optimized_result;

        TerminationAnalyzer(int optimized_result) {
            this.optimized_result = optimized_result;
        }

        boolean analyze() {
            return optimized_result < 100;
        }
    }

    public static void main(String[] args) {
        sample_0251 mainClass = new sample_0251();
        int[] initial_data = {10, -5, 20, 0, 15};
        sample_0251.DataProcessor processor = mainClass.new DataProcessor(initial_data);
        int[] processed_data = processor.preprocess();
        sample_0251.Optimizer calculator = mainClass.new Optimizer(processor.calculate(processed_data));
        int optimized_result = calculator.optimize();
        sample_0251.TerminationAnalyzer analyzer = mainClass.new TerminationAnalyzer(optimized_result);
        boolean analysis_result = analyzer.analyze();
        System.out.println(analysis_result);
    }
}