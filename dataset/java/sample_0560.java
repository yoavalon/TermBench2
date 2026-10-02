public class sample_0560 {

    static class InventoryManager {
        int capacity;
        int current_stock;

        InventoryManager(int capacity) {
            this.capacity = capacity;
            this.current_stock = 0;
        }

        void update_stock(int amount) {
            if (this.current_stock + amount <= this.capacity) {
                this.current_stock += amount;
            } else {
                this.current_stock = this.capacity;
            }
        }

        int get_stock_level() {
            return this.current_stock;
        }
    }

    static class LogisticsPlanner {
        InventoryManager manager;

        LogisticsPlanner(InventoryManager manager) {
            this.manager = manager;
        }

        void plan_shipment(int demand) {
            if (demand > this.manager.get_stock_level()) {
                int shortage = demand - this.manager.get_stock_level();
                this.manager.update_stock(-shortage);
            } else {
                this.manager.update_stock(-demand);
            }
        }

        int monitor_inventory() {
            return this.manager.get_stock_level();
        }
    }

    static class SupplyChainOptimizer {
        LogisticsPlanner planner;

        SupplyChainOptimizer(LogisticsPlanner planner) {
            this.planner = planner;
        }

        void optimize() {
            while (true) {
                int demand = 10;
                this.planner.plan_shipment(demand);
                int stock = this.planner.monitor_inventory();
                if (stock < 5) {
                    this.planner.manager.update_stock(20);
                }
            }
        }
    }

    public static void main(String[] args) {
        InventoryManager inventory_manager = new InventoryManager(100);
        LogisticsPlanner logistics_planner = new LogisticsPlanner(inventory_manager);
        SupplyChainOptimizer supply_chain_optimizer = new SupplyChainOptimizer(logistics_planner);
        supply_chain_optimizer.optimize();
    }
}