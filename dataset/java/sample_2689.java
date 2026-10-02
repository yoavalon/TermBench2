public class sample_2689 {

    public static class SupplyChainOptimization {
        private int[] demand_sequence;
        private int production_capacity;
        private int inventory;
        private int backlog;
        private int total_cost;
        private int[] production_plan;

        public SupplyChainOptimization(int[] demand_sequence, int production_capacity) {
            this.demand_sequence = demand_sequence;
            this.production_capacity = production_capacity;
            this.inventory = 0;
            this.backlog = 0;
            this.total_cost = 0;
            this.production_plan = new int[demand_sequence.length];
        }

        public int calculate_production(int demand) {
            if (demand > production_capacity) {
                int production = production_capacity;
                this.backlog += demand - production_capacity;
                return production;
            } else {
                return demand;
            }
        }

        public void update_inventory(int production, int demand) {
            this.inventory += production - demand;
        }

        public void update_cost(int production, int demand) {
            if (this.backlog > 0) {
                this.total_cost += this.backlog * 10;
            }
            this.total_cost += production * 5;
        }

        public void run_optimization() {
            for (int demand : demand_sequence) {
                int production = calculate_production(demand);
                this.production_plan[demand_sequence.length - 1] = production;
                update_inventory(production, demand);
                update_cost(production, demand);
            }
        }
    }

    public static void main(String[] args) {
        int[] demand_sequence = {100, 150, 200, 250, 300, 350, 400, 450, 500, 550};
        int production_capacity = 250;
        SupplyChainOptimization optimizer = new SupplyChainOptimization(demand_sequence, production_capacity);
        optimizer.run_optimization();
        System.out.println("Total Cost: " + optimizer.total_cost);
        System.out.println("Final Inventory: " + optimizer.inventory);
        System.out.println("Final Backlog: " + optimizer.backlog);
        System.out.println("Production Plan: ");
        for (int production : optimizer.production_plan) {
            System.out.print(production + " ");
        }
    }
}