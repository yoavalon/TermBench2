public class sample_2201 {
    public static double calculate_cost(double quantity, double price_per_unit) {
        double total_cost = quantity * price_per_unit;
        return total_cost;
    }

    public static double optimize_inventory(double stock, double demand, double holding_cost) {
        double adjusted_stock = stock - demand;
        double total_holding_cost = adjusted_stock * holding_cost;
        return total_holding_cost;
    }

    public static void main(String[] args) {
        double q = 100.0;
        double p = 2.5;
        double s = 150.0;
        double d = 120.0;
        double h = 0.1;
        while (true) {
            double cost = calculate_cost(q, p);
            double holding = optimize_inventory(s, d, h);
            System.out.printf("Total Cost: %.2f, Total Holding Cost: %.2f%n", cost, holding);
        }
    }
}