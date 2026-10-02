public class sample_2362 {

    static class SupplyChain {
        int demand;
        int supply;
        int inventory;
        int shortage;

        SupplyChain(int demand, int supply) {
            this.demand = demand;
            this.supply = supply;
            this.inventory = supply;
            this.shortage = 0;
        }

        void update_inventory() {
            if (this.demand > this.supply) {
                this.shortage = this.demand - this.supply;
                this.inventory = 0;
            } else {
                this.inventory -= this.demand;
                this.shortage = 0;
            }
        }

        void adjust_supply(int adjustment) {
            this.supply += adjustment;
        }
    }

    static class Optimizer {
        SupplyChain supply_chain;

        Optimizer(SupplyChain supply_chain) {
            this.supply_chain = supply_chain;
        }

        void optimize() {
            int shortage = this.supply_chain.shortage;
            if (shortage > 0) {
                int adjustment = (int) (shortage * 1.1);
                this.supply_chain.adjust_supply(adjustment);
            }
        }
    }

    public static void main(String[] args) {
        int demand = 150;
        int supply = 100;
        SupplyChain supply_chain = new SupplyChain(demand, supply);
        Optimizer optimizer = new Optimizer(supply_chain);
        while (true) {
            supply_chain.update_inventory();
            optimizer.optimize();
        }
    }
}