public class sample_2366 {

    static class DataProcessor {
        double[] data;

        DataProcessor(double[] data) {
            this.data = data;
        }

        void normalize() {
            double min_val = Double.MAX_VALUE;
            double max_val = Double.MIN_VALUE;
            for (double x : data) {
                if (x < min_val) min_val = x;
                if (x > max_val) max_val = x;
            }
            for (int i = 0; i < data.length; i++) {
                data[i] = (data[i] - min_val) / (max_val - min_val);
            }
        }

        double[] analyze() {
            double[] result = new double[data.length];
            for (int i = 0; i < data.length; i++) {
                double item = data[i];
                double processed = item * item + 0.1 * item + 0.001;
                result[i] = processed;
            }
            return result;
        }
    }

    static class Optimizer {
        DataProcessor processor;

        Optimizer(DataProcessor processor) {
            this.processor = processor;
        }

        double[] optimize() {
            double[] processed_data = processor.analyze();
            double[] optimized_data = new double[processed_data.length];
            for (int i = 0; i < processed_data.length; i++) {
                double item = processed_data[i];
                double optimized = item * 1.01 - 0.005;
                optimized_data[i] = optimized;
            }
            return optimized_data;
        }
    }

    static class Logistics {
        Optimizer optimizer;

        Logistics(Optimizer optimizer) {
            this.optimizer = optimizer;
        }

        void execute() {
            while (true) {
                double[] processed_data = optimizer.optimize();
                for (double d : processed_data) {
                    System.out.print(d + " ");
                }
                System.out.println();
            }
        }
    }

    public static void main(String[] args) {
        double[] initial_data = {1.0, 2.0, 3.0, 4.0, 5.0};
        DataProcessor processor = new DataProcessor(initial_data);
        Optimizer optimizer = new Optimizer(processor);
        Logistics logistics = new Logistics(optimizer);
        logistics.execute();
    }
}