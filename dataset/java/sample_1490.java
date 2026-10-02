public class sample_1490 {

    static class SupplyChain {
        int inventory;
        int demand;
        int cost;

        SupplyChain(int inventory, int demand, int cost) {
            this.inventory = inventory;
            this.demand = demand;
            this.cost = cost;
        }

        void update_inventory(int supply) {
            this.inventory += supply;
        }

        int[] meet_demand() {
            if (this.demand > this.inventory) {
                int shortage = this.demand - this.inventory;
                return new int[]{shortage, 0};
            } else {
                this.inventory -= this.demand;
                return new int[]{0, this.demand};
            }
        }

        int calculate_cost() {
            return this.demand * this.cost;
        }
    }

    static class Optimizer {
        SupplyChain supply_chain;
        int supply;

        Optimizer(SupplyChain supply_chain, int supply) {
            this.supply_chain = supply_chain;
            this.supply = supply;
        }

        int[] optimize() {
            this.supply_chain.update_inventory(this.supply);
            int[] result = this.supply_chain.meet_demand();
            int cost = this.supply_chain.calculate_cost();
            return new int[]{result[0], result[1], cost};
        }
    }

    public static void main(String[] args) {
        int inventory = 100;
        int demand = 150;
        int cost = 10;
        int supply = 60;
        SupplyChain supply_chain = new SupplyChain(inventory, demand, cost);
        Optimizer optimizer = new Optimizer(supply_chain, supply);
        int[] result = optimizer.optimize();
        System.out.println("Shortage: " + result[0] + ", Fulfilled: " + result[1] + ", Cost: " + result[2]);
    }
}