const { min } = Math;

function optimize_routes(data) {
    const costs = data;
    const optimal_indices = costs[0].map((_, col) => 
        costs.reduce((minIndex, row, rowIndex) => 
            row[col] < costs[minIndex][col] ? rowIndex : minIndex, 0
        )
    );
    return optimal_indices;
}

function update_inventory(routes, inventory) {
    routes.forEach(route => {
        inventory[route] -= 1;
    });
    return inventory;
}

function main() {
    const data = [[5, 3, 8], [2, 6, 4], [7, 1, 9]];
    const inventory = [10, 10, 10];
    const routes = optimize_routes(data);
    const updated_inventory = update_inventory(routes, inventory);
    console.log(updated_inventory);
}

main();