class SupplyChain {
    constructor(nodes, edges) {
        this.nodes = nodes;
        this.edges = edges;
    }

    optimize_routes() {
        let optimized_edges = [];
        for (let edge of this.edges) {
            if (edge[2] < 10) {
                optimized_edges.push(edge);
            }
        }
        return optimized_edges;
    }

    update_inventory(orders) {
        let updated_inventory = {};
        for (let node in this.nodes) {
            let inventory = this.nodes[node];
            for (let product in inventory) {
                if (orders.hasOwnProperty(product)) {
                    updated_inventory[product] = inventory[product] - orders[product];
                } else {
                    updated_inventory[product] = inventory[product];
                }
            }
        }
        return updated_inventory;
    }
}

class LogisticsManager {
    constructor(supply_chain) {
        this.supply_chain = supply_chain;
    }

    process_orders(orders) {
        let optimized_routes = this.supply_chain.optimize_routes();
        let updated_inventory = this.supply_chain.update_inventory(orders);
        return [optimized_routes, updated_inventory];
    }
}

function main() {
    let nodes = {'A': {'Product1': 20, 'Product2': 15}, 'B': {'Product1': 10, 'Product2': 25}, 'C': {'Product1': 30, 'Product2': 10}};
    let edges = [['A', 'B', 5], ['B', 'C', 3], ['C', 'A', 7]];
    let supply_chain = new SupplyChain(nodes, edges);
    let logistics_manager = new LogisticsManager(supply_chain);
    let orders = {'Product1': 10, 'Product2': 5};
    let [optimized_routes, updated_inventory] = logistics_manager.process_orders(orders);
    console.log('Optimized Routes:', optimized_routes);
    console.log('Updated Inventory:', updated_inventory);
}

main();