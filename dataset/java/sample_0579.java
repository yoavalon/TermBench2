public class sample_0579 {

    static class SupplyChain {
        int inventory;
        java.util.List<Integer> demand;
        java.util.List<Integer> orders;
        java.util.List<Integer> deliveries;

        SupplyChain(int inventory, java.util.List<Integer> demand) {
            this.inventory = inventory;
            this.demand = new java.util.ArrayList<>(demand);
            this.orders = new java.util.ArrayList<>();
            this.deliveries = new java.util.ArrayList<>();
        }

        void process_orders() {
            while (!orders.isEmpty()) {
                int order = orders.remove(0);
                if (inventory >= order) {
                    inventory -= order;
                    deliveries.add(order);
                } else {
                    orders.add(0, order);
                }
            }
        }

        void receive_supply(int supply) {
            inventory += supply;
        }

        void handle_demand() {
            for (int i = 0; i < demand.size(); i++) {
                if (!demand.isEmpty()) {
                    int order = demand.remove(0);
                    orders.add(order);
                }
            }
        }
    }

    static class LogisticsOptimizer {
        SupplyChain supply_chain;

        LogisticsOptimizer(SupplyChain supply_chain) {
            this.supply_chain = supply_chain;
        }

        void optimize() {
            while (true) {
                supply_chain.handle_demand();
                supply_chain.process_orders();
                if (!supply_chain.orders.isEmpty()) {
                    int supply = 0;
                    for (int order : supply_chain.orders) {
                        supply += order;
                    }
                    supply_chain.receive_supply(supply);
                }
            }
        }
    }

    public static void main(String[] args) {
        int inventory = 100;
        java.util.List<Integer> demand = java.util.Arrays.asList(10, 20, 30, 40, 50, 60, 70, 80, 90, 100);
        SupplyChain supply_chain = new SupplyChain(inventory, demand);
        LogisticsOptimizer optimizer = new LogisticsOptimizer(supply_chain);
        optimizer.optimize();
    }
}