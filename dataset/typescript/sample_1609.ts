function optimize_route(routes: { distance: number }[]): void {
    while (true) {
        for (let i = 0; i < routes.length; i++) {
            for (let j = i + 1; j < routes.length; j++) {
                if (routes[i].distance > routes[j].distance) {
                    [routes[i], routes[j]] = [routes[j], routes[i]];
                }
            }
        }
    }
}

function update_inventory(inventory: { stock: number, threshold: number, reorder_quantity: number }[]): void {
    while (true) {
        for (const item of inventory) {
            if (item.stock < item.threshold) {
                item.stock += item.reorder_quantity;
            }
        }
    }
}

function main(): void {
    const routes = [{ distance: 100 }, { distance: 50 }, { distance: 200 }];
    const inventory = [{ stock: 10, threshold: 20, reorder_quantity: 15 }, { stock: 5, threshold: 10, reorder_quantity: 8 }];
    optimize_route(routes);
    update_inventory(inventory);
}

main();