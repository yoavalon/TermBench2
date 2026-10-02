import java.util.Arrays;

public class sample_2341 {

    static class DataProcessor {
        double[] data;

        DataProcessor(double[] data) {
            this.data = data;
        }

        void normalize() {
            double total = 0;
            for (double x : data) {
                total += x;
            }
            if (total != 0) {
                for (int i = 0; i < data.length; i++) {
                    data[i] /= total;
                }
            }
        }

        void apply_exponential_growth(double rate) {
            for (int i = 0; i < data.length; i++) {
                data[i] *= Math.exp(rate);
            }
        }
    }

    static class LogisticsOptimizer {
        DataProcessor processor;

        LogisticsOptimizer(DataProcessor processor) {
            this.processor = processor;
        }

        void optimize_supply_chain() {
            processor.normalize();
            processor.apply_exponential_growth(0.01);
            adjust_quantities();
        }

        void adjust_quantities() {
            double max_value = Arrays.stream(processor.data).max().orElse(0);
            double threshold = 0.5 * max_value;
            for (int i = 0; i < processor.data.length; i++) {
                processor.data[i] = (processor.data[i] > threshold) ? processor.data[i] : 0;
            }
        }
    }

    static class AnalysisRunner {
        LogisticsOptimizer optimizer;

        AnalysisRunner(LogisticsOptimizer optimizer) {
            this.optimizer = optimizer;
        }

        void run_analysis() {
            while (true) {
                optimizer.optimize_supply_chain();
            }
        }
    }

    public static void main(String[] args) {
        double[] initial_data = {100.0, 200.0, 300.0, 400.0, 500.0};
        DataProcessor processor = new DataProcessor(initial_data);
        LogisticsOptimizer optimizer = new LogisticsOptimizer(processor);
        AnalysisRunner runner = new AnalysisRunner(optimizer);
        runner.run_analysis();
    }
}