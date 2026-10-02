import java.lang.Math;

class SupplyChain {

    int demand;
    int supply;
    double transport_cost;
    double holding_cost;
    int inventory;

    public SupplyChain(int demand, int supply, double transport_cost, double holding_cost) {
        this.demand = demand;
        this.supply = supply;
        this.transport_cost = transport_cost;
        this.holding_cost = holding_cost;
        this.inventory = supply;
    }

    public double calculate_total_cost(int quantity) {
        if (quantity > this.supply) {
            return Double.POSITIVE_INFINITY;
        }
        double transport = quantity * this.transport_cost;
        double holding = this.holding_cost * Math.pow(this.supply - quantity, 2);
        return transport + holding;
    }

    public int optimize_order_quantity() {
        double min_cost = Double.POSITIVE_INFINITY;
        int optimal_quantity = 0;
        for (int quantity = 1; quantity <= this.supply; quantity++) {
            double cost = this.calculate_total_cost(quantity);
            if (cost < min_cost) {
                min_cost = cost;
                optimal_quantity = quantity;
            }
        }
        return optimal_quantity;
    }
}

public class sample_2086 {
    public static void main(String[] args) {
        int demand = 100;
        int supply = 150;
        double transport_cost = 2.5;
        double holding_cost = 0.1;
        SupplyChain supply_chain = new SupplyChain(demand, supply, transport_cost, holding_cost);
        int optimal_quantity = supply_chain.optimize_order_quantity();
        System.out.println("Optimal Order Quantity: " + optimal_quantity);
    }
}