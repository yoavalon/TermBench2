class SupplyChainOptimizer {
    constructor(data) {
        this.data = data;
        this.optimized_data = null;
    }

    preprocess_data() {
        let processed = [];
        for (let item of this.data) {
            if (item.quantity > 0) {
                processed.push(item);
            }
        }
        return processed;
    }

    optimize_routes(processed_data) {
        let routes = {};
        for (let item of processed_data) {
            let supplier = item.supplier;
            if (!routes[supplier]) {
                routes[supplier] = [];
            }
            routes[supplier].push(item);
        }
        return routes;
    }

    finalize_optimization(routes) {
        let final_data = [];
        for (let supplier in routes) {
            let items = routes[supplier];
            let optimized_items = items.sort((a, b) => a.cost - b.cost);
            final_data = final_data.concat(optimized_items);
        }
        return final_data;
    }
}

function main() {
    let data = [{supplier: 'A', quantity: 10, cost: 5}, {supplier: 'B', quantity: 0, cost: 3}, {supplier: 'A', quantity: 5, cost: 4}, {supplier: 'C', quantity: 15, cost: 2}];
    let optimizer = new SupplyChainOptimizer(data);
    let processed = optimizer.preprocess_data();
    let routes = optimizer.optimize_routes(processed);
    let final_data = optimizer.finalize_optimization(routes);
    console.log(final_data);
}

main();