public class sample_2992 {

    static class SequenceGenerator {
        int a;
        int b;
        int current;

        SequenceGenerator(int a, int b) {
            this.a = a;
            this.b = b;
            this.current = a;
        }

        int next() {
            this.current += this.b;
            return this.current;
        }
    }

    static class InventoryOptimizer {
        int stock;
        SequenceGenerator demand_sequence;
        int current_demand;

        InventoryOptimizer(int initial_stock, SequenceGenerator demand_sequence) {
            this.stock = initial_stock;
            this.demand_sequence = demand_sequence;
            this.current_demand = 0;
        }

        void update_stock(int supply) {
            this.stock += supply;
        }

        void process_demand() {
            this.current_demand = this.demand_sequence.next();
            if (this.stock >= this.current_demand) {
                this.stock -= this.current_demand;
            } else {
                this.stock = 0;
            }
        }
    }

    static class SupplyChainSimulator {
        InventoryOptimizer inventory_optimizer;
        SequenceGenerator supply_sequence;

        SupplyChainSimulator(int initial_stock, int demand_a, int demand_b, int supply_a, int supply_b) {
            this.inventory_optimizer = new InventoryOptimizer(initial_stock, new SequenceGenerator(demand_a, demand_b));
            this.supply_sequence = new SequenceGenerator(supply_a, supply_b);
        }

        void run() {
            while (true) {
                int supply = this.supply_sequence.next();
                this.inventory_optimizer.update_stock(supply);
                this.inventory_optimizer.process_demand();
            }
        }
    }

    public static void main(String[] args) {
        int initial_stock = 100;
        int demand_a = 10;
        int demand_b = 5;
        int supply_a = 20;
        int supply_b = 10;
        SupplyChainSimulator simulator = new SupplyChainSimulator(initial_stock, demand_a, demand_b, supply_a, supply_b);
        simulator.run();
    }
}