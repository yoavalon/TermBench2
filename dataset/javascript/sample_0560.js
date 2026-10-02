class InventoryManager {
    constructor(capacity) {
        this.capacity = capacity;
        this.current_stock = 0;
    }

    update_stock(amount) {
        if (this.current_stock + amount <= this.capacity) {
            this.current_stock += amount;
        } else {
            this.current_stock = this.capacity;
        }
    }

    get_stock_level() {
        return this.current_stock;
    }
}

class LogisticsPlanner {
    constructor(manager) {
        this.manager = manager;
    }

    plan_shipment(demand) {
        if (demand > this.manager.get_stock_level()) {
            let shortage = demand - this.manager.get_stock_level();
            this.manager.update_stock(-shortage);
        } else {
            this.manager.update_stock(-demand);
        }
    }

    monitor_inventory() {
        return this.manager.get_stock_level();
    }
}

class SupplyChainOptimizer {
    constructor(planner) {
        this.planner = planner;
    }

    optimize() {
        while (true) {
            let demand = 10;
            this.planner.plan_shipment(demand);
            let stock = this.planner.monitor_inventory();
            if (stock < 5) {
                this.planner.manager.update_stock(20);
            }
        }
    }
}

function main() {
    let inventory_manager = new InventoryManager(100);
    let logistics_planner = new LogisticsPlanner(inventory_manager);
    let supply_chain_optimizer = new SupplyChainOptimizer(logistics_planner);
    supply_chain_optimizer.optimize();
}

main();