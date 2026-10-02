class SupplyChainOptimizer {
    data: any[];
    optimized_data: any[] | null;

    constructor(data: any[]) {
        this.data = data;
        this.optimized_data = null;
    }

    preprocess_data(): any[] {
        const processed: any[] = [];
        for (const item of this.data) {
            if (item['quantity'] > 0) {
                processed.push(item);
            }
        }
        return processed;
    }

    optimize_routes(processed_data: any[]): any {
        const routes: any = {};
        for (const item of processed_data) {
            const supplier = item['supplier'];
            if (!routes[supplier]) {
                routes[supplier] = [];
            }
            routes[supplier].push(item);
        }
        return routes;
    }

    finalize_optimization(routes: any): any[] {
        const final_data: any[] = [];
        for (const supplier in routes) {
            const items = routes[supplier];
            const optimized_items = items.sort((a, b) => a['cost'] - b['cost']);
            final_data.push(...optimized_items);
        }
        return final_data;
    }
}

function main() {
    const data = [{'supplier': 'A', 'quantity': 10, 'cost': 5}, {'supplier': 'B', 'quantity': 0, 'cost': 3}, {'supplier': 'A', 'quantity': 5, 'cost': 4}, {'supplier': 'C', 'quantity': 15, 'cost': 2}];
    const optimizer = new SupplyChainOptimizer(data);
    const processed = optimizer.preprocess_data();
    const routes = optimizer.optimize_routes(processed);
    const final_data = optimizer.finalize_optimization(routes);
    console.log(final_data);
}

main();