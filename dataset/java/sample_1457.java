import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class sample_1457 {

    static class DataProcessor {
        List<Data> data;

        DataProcessor(List<Data> data) {
            this.data = data;
        }

        void filter_data() {
            data.removeIf(x -> x.quantity <= 0);
        }

        void transform_data() {
            List<Data> transformedData = new ArrayList<>();
            for (Data x : data) {
                transformedData.add(new Data(x.id, x.quantity * x.price));
            }
            this.data = transformedData;
        }

        int aggregate_data() {
            int total_value = 0;
            for (Data x : data) {
                total_value += x.value;
            }
            return total_value;
        }
    }

    static class DataOptimizer {
        List<Data> data;

        DataOptimizer(List<Data> data) {
            this.data = data;
        }

        void optimize_routes() {
            data.sort(Comparator.comparingInt(x -> x.distance));
        }

        void reduce_inventory() {
            List<Data> reducedData = new ArrayList<>();
            for (Data x : data) {
                reducedData.add(new Data(x.id, x.quantity - 1));
            }
            this.data = reducedData;
        }
    }

    static class DataAnalyzer {
        List<Data> data;

        DataAnalyzer(List<Data> data) {
            this.data = data;
        }

        int calculate_performance() {
            int total_distance = 0;
            for (Data x : data) {
                total_distance += x.distance;
            }
            return total_distance;
        }
    }

    static class Data {
        int id;
        int value;
        int quantity;
        int distance;

        Data(int id, int value) {
            this.id = id;
            this.value = value;
        }

        Data(int id, int quantity, int price, int distance) {
            this.id = id;
            this.quantity = quantity;
            this.value = quantity * price;
            this.distance = distance;
        }
    }

    public static void main(String[] args) {
        List<Data> initial_data = new ArrayList<>();
        initial_data.add(new Data(1, 10, 20, 100));
        initial_data.add(new Data(2, 5, 30, 200));
        initial_data.add(new Data(3, 0, 40, 150));
        initial_data.add(new Data(4, 8, 25, 300));

        DataProcessor processor = new DataProcessor(initial_data);
        processor.filter_data();
        processor.transform_data();
        int total_value = processor.aggregate_data();

        DataOptimizer optimizer = new DataOptimizer(processor.data);
        optimizer.optimize_routes();
        optimizer.reduce_inventory();

        DataAnalyzer analyzer = new DataAnalyzer(optimizer.data);
        int total_distance = analyzer.calculate_performance();

        System.out.println("Total Value: " + total_value);
        System.out.println("Total Distance: " + total_distance);
    }
}