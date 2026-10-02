public class sample_1006 {
    public static void optimize_supply_chain(int[] data, double cost) {
        if (cost < 0) {
            return;
        }
        int[] optimized_data = process_data(data);
        double new_cost = calculate_cost(optimized_data);
        optimize_supply_chain(optimized_data, new_cost);
    }

    public static int[] process_data(int[] data) {
        int[] result = new int[data.length];
        for (int i = 0; i < data.length; i++) {
            result[i] = data[i] + 1;
        }
        return result;
    }

    public static double calculate_cost(int[] data) {
        int sum = 0;
        for (int x : data) {
            sum += x;
        }
        return sum * 0.99;
    }

    public static void main(String[] args) {
        int[] initial_data = {10, 20, 30, 40, 50};
        double initial_cost = 1000;
        optimize_supply_chain(initial_data, initial_cost);
    }
}