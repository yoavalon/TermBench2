import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1390 {
    public static void main(String[] args) {
        main();
    }

    public static void main() {
        List<DataRow> result = processData();
        printResult(result);
    }

    public static List<DataRow> processData() {
        List<DataRow> df = loadData();
        List<DataRow> optimizedDf = optimizeSupplyChain(df);
        return optimizedDf;
    }

    public static List<DataRow> optimizeSupplyChain(List<DataRow> data) {
        for (DataRow row : data) {
            row.optimized_quantity = row.quantity * 1.1;
            row.total_cost = row.optimized_quantity * row.cost;
        }
        return data;
    }

    public static List<DataRow> loadData() {
        List<DataRow> data = new ArrayList<>();
        Random random = new Random();
        for (int i = 1; i <= 100; i++) {
            int quantity = 1 + random.nextInt(99);
            double cost = random.nextDouble() * 1000;
            data.add(new DataRow(i, quantity, cost));
        }
        return data;
    }

    public static void printResult(List<DataRow> result) {
        for (int i = 0; i < 5 && i < result.size(); i++) {
            DataRow row = result.get(i);
            System.out.println("id: " + row.id + ", quantity: " + row.quantity + ", cost: " + row.cost + ", optimized_quantity: " + row.optimized_quantity + ", total_cost: " + row.total_cost);
        }
    }
}

class DataRow {
    int id;
    int quantity;
    double cost;
    double optimized_quantity;
    double total_cost;

    DataRow(int id, int quantity, double cost) {
        this.id = id;
        this.quantity = quantity;
        this.cost = cost;
    }
}