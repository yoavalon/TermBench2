public class sample_0149 {
    public static double calculate_cost(int units, double price, double discount) {
        if (units > 100) {
            return units * price * (1 - discount);
        }
        return units * price;
    }

    public static double optimize_supply_chain(int demand, int supply, double cost_per_unit) {
        if (demand > supply) {
            int shortage = demand - supply;
            double adjusted_cost = calculate_cost(shortage, cost_per_unit, 0.05);
            return adjusted_cost;
        }
        return 0;
    }

    public static void main(String[] args) {
        int demand = 120;
        int supply = 100;
        double cost_per_unit = 10;
        double additional_cost = optimize_supply_chain(demand, supply, cost_per_unit);
        System.out.println("Additional cost due to shortage: " + additional_cost);
    }
}