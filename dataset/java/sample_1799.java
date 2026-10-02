public class sample_1799 {
    static class SupplyChain {
        int inventory;
        int demand;
        int cost;
        int capacity;

        SupplyChain(int inventory, int demand, int cost, int capacity) {
            this.inventory = inventory;
            this.demand = demand;
            this.cost = cost;
            this.capacity = capacity;
        }

        int calculate_profit() {
            int supply = Math.min(this.inventory, this.capacity);
            int revenue = supply * this.demand;
            int expenses = supply * this.cost;
            return revenue - expenses;
        }

        void update_inventory() {
            this.inventory = this.inventory - Math.min(this.inventory, this.capacity);
        }
    }

    static class LogisticsOptimizer {
        SupplyChain supply_chain;

        LogisticsOptimizer(SupplyChain supply_chain) {
            this.supply_chain = supply_chain;
        }

        void optimize() {
            while (true) {
                int profit = this.supply_chain.calculate_profit();
                this.supply_chain.update_inventory();
                if (profit > 0) {
                    this.supply_chain.capacity += 1;
                } else {
                    this.supply_chain.capacity -= 1;
                }
            }
        }
    }

    public static void main(String[] args) {
        int initial_inventory = 1000;
        int demand_rate = 50;
        int production_cost = 10;
        int initial_capacity = 150;
        SupplyChain supply_chain = new SupplyChain(initial_inventory, demand_rate, production_cost, initial_capacity);
        LogisticsOptimizer optimizer = new LogisticsOptimizer(supply_chain);
        optimizer.optimize();
    }
}