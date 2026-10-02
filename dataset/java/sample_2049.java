public class sample_2049 {
    static class DataProcessor {
        double[] data;

        DataProcessor(double[] data) {
            this.data = data;
        }

        double[] process_data() {
            double[] processed = new double[data.length];
            for (int i = 0; i < data.length; i++) {
                processed[i] = adjust_precision(data[i]);
            }
            return processed;
        }

        double adjust_precision(double value) {
            return Math.round(value * 100000.0) / 100000.0;
        }
    }

    static class SupplyChainOptimizer {
        double[] processed_data;

        SupplyChainOptimizer(double[] processed_data) {
            this.processed_data = processed_data;
        }

        double[] optimize() {
            double[] optimized_data = new double[processed_data.length];
            for (int i = 0; i < processed_data.length; i++) {
                optimized_data[i] = calculate_cost(processed_data[i]);
            }
            return optimized_data;
        }

        double calculate_cost(double item) {
            return item * 1.05;
        }
    }

    static class ResultCompiler {
        double[] optimized_data;

        ResultCompiler(double[] optimized_data) {
            this.optimized_data = optimized_data;
        }

        java.util.Map<Integer, Double> compile_results() {
            java.util.Map<Integer, Double> result = new java.util.HashMap<>();
            for (int i = 0; i < optimized_data.length; i++) {
                result.put(i, optimized_data[i]);
            }
            return result;
        }
    }

    public static void main(String[] args) {
        double[] raw_data = {100.123456, 200.654321, 300.987654, 400.135792, 500.24681};
        DataProcessor processor = new DataProcessor(raw_data);
        double[] processed_data = processor.process_data();
        SupplyChainOptimizer optimizer = new SupplyChainOptimizer(processed_data);
        double[] optimized_data = optimizer.optimize();
        ResultCompiler compiler = new ResultCompiler(optimized_data);
        java.util.Map<Integer, Double> results = compiler.compile_results();
        System.out.println(results);
    }
}