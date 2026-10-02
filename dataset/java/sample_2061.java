public class sample_2061 {
    class Simulation {
        double a;
        double b;
        double c;

        Simulation(double a, double b, double c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }

        double calculate(double x) {
            return this.a * Math.pow(x, 2) + this.b * x + this.c;
        }
    }

    class PrecisionAnalyzer {
        Simulation simulation;

        PrecisionAnalyzer(Simulation simulation) {
            this.simulation = simulation;
        }

        double[] analyze(double[] x_values) {
            double[] results = new double[x_values.length];
            for (int i = 0; i < x_values.length; i++) {
                results[i] = this.simulation.calculate(x_values[i]);
            }
            return results;
        }
    }

    class DataProcessor {
        PrecisionAnalyzer analyzer;

        DataProcessor(PrecisionAnalyzer analyzer) {
            this.analyzer = analyzer;
        }

        double[] process(double[] x_values) {
            double[] raw_data = this.analyzer.analyze(x_values);
            double[] processed_data = format_data(raw_data);
            return processed_data;
        }

        double[] format_data(double[] data) {
            double[] formatted = new double[data.length];
            for (int i = 0; i < data.length; i++) {
                formatted[i] = Math.round(data[i] * 100000.0) / 100000.0;
            }
            return formatted;
        }
    }

    public static void main(String[] args) {
        sample_2061 sample = new sample_2061();
        Simulation sim = sample.new Simulation(2.0, 3.0, 1.0);
        PrecisionAnalyzer analyzer = sample.new PrecisionAnalyzer(sim);
        DataProcessor processor = sample.new DataProcessor(analyzer);
        double[] x_values = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
        double[] processed_results = processor.process(x_values);
        for (int i = 0; i < processed_results.length; i++) {
            System.out.println("X: " + x_values[i] + ", Result: " + processed_results[i]);
        }
    }
}