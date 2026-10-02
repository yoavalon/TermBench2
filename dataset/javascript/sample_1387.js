function optimize_route(routes, demands) {
    let costs = [];
    for (let r of routes) {
        let cost = 0;
        for (let i = 0; i < demands.length; i++) {
            cost += demands[i] * r[i];
        }
        costs.push(cost);
    }
    return Math.min(...costs);
}

function update_demands(demands, adjustments) {
    let updated = [];
    for (let i = 0; i < demands.length; i++) {
        updated.push(demands[i] + adjustments[i]);
    }
    return updated;
}

function main() {
    let routes = [[2, 3, 1], [4, 1, 2], [3, 2, 3]];
    let demands = [5, 10, 15];
    let adjustments = [-1, 2, -3];
    let updated_demands = update_demands(demands, adjustments);
    let best_cost = optimize_route(routes, updated_demands);
    console.log(best_cost);
}

main();