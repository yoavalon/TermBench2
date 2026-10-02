import * as np from 'numpy';

function optimize_routes(data: number[][]): number[] {
    const costs = np.array(data);
    const optimalIndices = np.argmin(costs, axis=0);
    return optimalIndices;
}

function update_inventory(routes: number[], inventory: number[]): number[] {
    for (const route of routes) {
        inventory[route] -= 1;
    }
    return inventory;
}

function main() {
    const data = [[5, 3, 8], [2, 6, 4], [7, 1, 9]];
    const inventory = np.array([10, 10, 10]);
    const routes = optimize_routes(data);
    const updatedInventory = update_inventory(routes, inventory);
    console.log(updatedInventory);
}

if (require.main === module) {
    main();
}