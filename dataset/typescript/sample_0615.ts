function optimize_supply_chain(costs: number[][], index: number, result: number): number {
    if (index === costs.length) {
        return result;
    }
    const min_cost = Math.min(...costs[index]);
    return optimize_supply_chain(costs, index + 1, result + min_cost);
}

const costs = [[10, 20, 30], [15, 25, 35], [5, 15, 25]];
console.log(optimize_supply_chain(costs, 0, 0));