public class sample_0223 {

    public static class SupplyChainModel {
        int capacity;
        int demand;
        int cost;
        int inventory;
        int revenue;
        int total_cost;

        public SupplyChainModel(int capacity, int demand, int cost) {
            this.capacity = capacity;
            this.demand = demand;
            this.cost = cost;
            this.inventory = 0;
            this.revenue = 0;
            this.total_cost = 0;
        }

        public void update_inventory() {
            if (this.demand > this.capacity) {
                this.inventory += this.capacity;
            } else {
                this.inventory += this.demand;
            }
        }

        public void calculate_revenue() {
            this.revenue = Math.min(this.demand, this.inventory) * this.cost;
        }

        public void calculate_total_cost() {
            this.total_cost = this.capacity * this.cost;
        }

        public int optimize() {
            this.update_inventory();
            this.calculate_revenue();
            this.calculate_total_cost();
            return this.revenue - this.total_cost;
        }
    }

    public static int run_optimization() {
        int capacity = 100;
        int demand = 80;
        int cost = 10;
        SupplyChainModel model = new SupplyChainModel(capacity, demand, cost);
        int profit = model.optimize();
        return profit;
    }

    public static void main(String[] args) {
        int profit = run_optimization();
        System.out.println('Optimized Profit: ' + profit);
    }
}