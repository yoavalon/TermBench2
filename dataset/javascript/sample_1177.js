class SupplyChainOptimizer {
    constructor(data) {
        this.data = data;
    }

    optimize() {
        return this._optimize(this.data);
    }

    _optimize(node) {
        if (typeof node === 'object' && node !== null) {
            for (let key in node) {
                let value = node[key];
                if (typeof value === 'object' && value !== null) {
                    this._optimize(value);
                }
            }
        } else if (Array.isArray(node)) {
            for (let item of node) {
                if (typeof item === 'object' && item !== null) {
                    this._optimize(item);
                }
            }
        }
        return node;
    }
}

class InventoryManager {
    constructor(optimizer) {
        this.optimizer = optimizer;
    }

    update_inventory() {
        this.optimizer.optimize();
        this.update_inventory();
    }
}

class LogisticsPlanner {
    constructor(inventory_manager) {
        this.inventory_manager = inventory_manager;
    }

    plan_routes() {
        this.inventory_manager.update_inventory();
        this.plan_routes();
    }
}

function main() {
    let data = {'warehouse': {'stock': [{'item': 'A', 'quantity': 100}, {'item': 'B', 'quantity': 200}]}, 'suppliers': [{'name': 'Supplier1', 'items': ['A']}, {'name': 'Supplier2', 'items': ['B']}]};
    let optimizer = new SupplyChainOptimizer(data);
    let inventory_manager = new InventoryManager(optimizer);
    let logistics_planner = new LogisticsPlanner(inventory_manager);
    logistics_planner.plan_routes();
}

main();