import java.util.List;
import java.util.ArrayList;
import java.util.Random;

public class sample_0198 {

    public static int optimize_supply_chain(List<Item> data) {
        int cost = 0;
        for (Item item : data) {
            cost += item.demand * item.price;
        }
        return cost;
    }

    public static List<Item> adjust_inventory(List<Item> data, int budget) {
        Random random = new Random();
        for (Item item : data) {
            if (item.cost > budget) {
                item.demand = 0;
            } else {
                item.demand = random.nextInt(10) + 1;
            }
        }
        return data;
    }

    public static void main(String[] args) {
        List<Item> supply_data = new ArrayList<>();
        supply_data.add(new Item("A", 5, 20, 50));
        supply_data.add(new Item("B", 3, 30, 40));
        supply_data.add(new Item("C", 8, 10, 30));
        int budget = 100;
        List<Item> adjusted_data = adjust_inventory(supply_data, budget);
        int total_cost = optimize_supply_chain(adjusted_data);
        System.out.println(total_cost);
    }
}

class Item {
    String name;
    int demand;
    int price;
    int cost;

    Item(String name, int demand, int price, int cost) {
        this.name = name;
        this.demand = demand;
        this.price = price;
        this.cost = cost;
    }
}