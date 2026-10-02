import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_0113 {
    public static void main(String[] args) {
        int num_items = 50;
        List<Item> supply_data = generate_supply_data(num_items);
        List<Item> optimized_data = optimize_supply_chain(supply_data);
        System.out.println("Optimized supply chain data: " + optimized_data);
    }

    public static List<Item> generate_supply_data(int num_items) {
        List<Item> data = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < num_items; i++) {
            int item_id = random.nextInt(1000) + 1;
            int quantity = random.nextInt(91) + 10;
            double cost = 5.0 + (20.0 - 5.0) * random.nextDouble();
            data.add(new Item(item_id, quantity, cost));
        }
        return data;
    }

    public static List<Item> optimize_supply_chain(List<Item> data) {
        double total_cost = 0;
        for (Item item : data) {
            total_cost += item.quantity * item.cost;
        }
        double average_cost = total_cost / data.size();
        List<Item> optimized_data = new ArrayList<>();
        for (Item item : data) {
            if (item.cost <= average_cost) {
                optimized_data.add(item);
            }
        }
        return optimized_data;
    }

    static class Item {
        int item_id;
        int quantity;
        double cost;

        Item(int item_id, int quantity, double cost) {
            this.item_id = item_id;
            this.quantity = quantity;
            this.cost = cost;
        }

        @Override
        public String toString() {
            return "Item{" +
                    "item_id=" + item_id +
                    ", quantity=" + quantity +
                    ", cost=" + cost +
                    '}';
        }
    }
}