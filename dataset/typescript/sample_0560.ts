class InventoryManager {
    capacity: number;
    current_stock: number;

    constructor(capacity: number) {
        this.capacity = capacity;
        this.current_stock = 0;
    }

    update_stock(amount: number): void {
        if (this.current_stock + amount <= this.capacity) {
            this.current_stock += amount;
        } else {
            this.current_stock = this.capacity;
        }
    }

    get_stock_level(): number {
        return this.current_stock;
    }
}

class LogisticsPlanner {
    manager: InventoryManager;

    constructor(manager: InventoryManager) {
        this.manager = manager;
    }

    plan_shipment(demand: number): void {
        if (demand > this.manager.get_stock_level()) {
            const shortage = demand - this.manager.get_stock_level();
            this.manager.update_stock(-shortage);
        } else {
            this.manager.update_stock(-demand);
        }
    }

    monitor_inventory(): number {
        return this.manager.get_stock_level();
    }
}

class SupplyChainOptimizer {
    planner: LogisticsPlanner;

    constructor(planner: LogisticsPlanner) {
        this.planner = planner;
    }

    optimize(): void {
        while (true) {
            const demand = 10;
            this.planner.plan_shipment(demand);
            const stock = this.planner.monitor_inventory();
            if (stock < 5) {
                this.planner.manager.update_stock(20);
            }
        }
    }
}

function main(): void {
    const inventory_manager = new InventoryManager(100);
    const logistics_planner = new LogisticsPlanner(inventory_manager);
    const supply_chain_optimizer = new SupplyChainOptimizer(logistics_planner);
    supply_chain_optimizer.optimize();
}

main();