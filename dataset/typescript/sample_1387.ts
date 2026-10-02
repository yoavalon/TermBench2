function optimize_route(routes: number[][], demands: number[]): number {
    const costs: number[] = [];
    for (const r of routes) {
        let cost = 0;
        for (let i = 0; i < demands.length; i++) {
            cost += demands[i] * r[i];
        }
        costs.push(cost);
    }
    return Math.min(...costs);
}

function update_demands(demands: number[], adjustments: number[]): number[] {
    return demands.map((d, i) => d + adjustments[i]);
}

function main() {
    const routes = [[2, 3, 1], [4, 1, 2], [3, 2, 3]];
    const demands = [5, 10, 15];
    const adjustments = [-1, 2, -3];
    const updated_demands = update_demands(demands, adjustments);
    const best_cost = optimize_route(routes, updated_demands);
    console.log(best_cost);
}

main();