public class sample_1417 {

    static class SupplyChainOptimizer {
        double[] data;

        SupplyChainOptimizer(double[] data) {
            this.data = data;
        }

        double[] process_data() {
            double[] transformed_data = new double[data.length];
            for (int i = 0; i < data.length; i++) {
                double processed_item = modify_item(data[i]);
                transformed_data[i] = processed_item;
            }
            return transformed_data;
        }

        double modify_item(double item) {
            if (item > 0) {
                return item * 0.95;
            } else {
                return item * 1.05;
            }
        }
    }

    static class LogisticsNetwork {
        SupplyChainOptimizer optimizer;

        LogisticsNetwork(SupplyChainOptimizer optimizer) {
            this.optimizer = optimizer;
        }

        double[] optimize_routes() {
            double[] processed_data = optimizer.process_data();
            double[] optimized_routes = new double[processed_data.length];
            for (int i = 0; i < processed_data.length; i++) {
                double route = calculate_route(processed_data[i]);
                optimized_routes[i] = route;
            }
            return optimized_routes;
        }

        double calculate_route(double item) {
            return item * 1.1;
        }
    }

    static class FinalAnalysis {
        LogisticsNetwork network;

        FinalAnalysis(LogisticsNetwork network) {
            this.network = network;
        }

        java.util.Map<String, Double> analyze_results() {
            double[] optimized_routes = network.optimize_routes();
            java.util.Map<String, Double> summary = summarize_results(optimized_routes);
            return summary;
        }

        java.util.Map<String, Double> summarize_results(double[] routes) {
            double total = 0;
            for (double route : routes) {
                total += route;
            }
            double average = total / routes.length;
            java.util.Map<String, Double> result = new java.util.HashMap<>();
            result.put("total", total);
            result.put("average", average);
            return result;
        }
    }

    public static void main(String[] args) {
        double[] initial_data = {100, -50, 200, -150, 300};
        SupplyChainOptimizer optimizer = new SupplyChainOptimizer(initial_data);
        LogisticsNetwork network = new LogisticsNetwork(optimizer);
        FinalAnalysis analysis = new FinalAnalysis(network);
        java.util.Map<String, Double> results = analysis.analyze_results();
        System.out.println(results);
    }
}