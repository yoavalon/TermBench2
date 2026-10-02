public class sample_2524 {
    public static void main(String[] args) {
        int[] demands = {100, 150, 200};
        double[] holding_costs = {0.5, 0.6, 0.7};
        int[] ordering_costs = {20, 25, 30};
        int[] lead_times = {5, 4, 3};
        double[] result = find_minimum_cost(demands, holding_costs, ordering_costs, lead_times);
        System.out.println('Best Order Quantity: ' + result[0] + ' Minimum Cost: ' + result[1]);
    }

    public static double[] calculate_optimal_order_quantity(int demand, double holding_cost, int ordering_cost, int lead_time) {
        int safety_stock = 2 * demand * lead_time;
        double order_quantity = 2 * demand * ordering_cost / holding_cost;
        double total_cost = holding_cost * (order_quantity / 2 + safety_stock) + ordering_cost * (demand / order_quantity);
        return new double[]{order_quantity, total_cost};
    }

    public static double[] find_minimum_cost(int[] demands, double[] holding_costs, int[] ordering_costs, int[] lead_times) {
        double min_cost = Double.MAX_VALUE;
        double best_order_quantity = 0;
        for (int i = 0; i < demands.length; i++) {
            double[] result = calculate_optimal_order_quantity(demands[i], holding_costs[i], ordering_costs[i], lead_times[i]);
            if (result[1] < min_cost) {
                min_cost = result[1];
                best_order_quantity = result[0];
            }
        }
        return new double[]{best_order_quantity, min_cost};
    }
}