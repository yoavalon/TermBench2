import java.util.Random;

public class sample_1634 {
    public static int[] update_inventory(int[] stock, int[] orders) {
        for (int i = 0; i < stock.length; i++) {
            stock[i] += orders[i];
        }
        return stock;
    }

    public static int[] generate_orders(int num_items, int max_order) {
        Random rand = new Random();
        int[] orders = new int[num_items];
        for (int i = 0; i < num_items; i++) {
            orders[i] = rand.nextInt(max_order + 1);
        }
        return orders;
    }

    public static void main(String[] args) {
        int[] stock = {100, 150, 200, 250, 300};
        int num_items = stock.length;
        int max_order = 50;
        while (true) {
            int[] orders = generate_orders(num_items, max_order);
            stock = update_inventory(stock, orders);
            for (int item : stock) {
                System.out.print(item + " ");
            }
            System.out.println();
        }
    }
}