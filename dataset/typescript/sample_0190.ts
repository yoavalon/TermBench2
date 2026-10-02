function calculate_cost(route: string[], costs: { [key: string]: number }): number {
    let totalCost = 0;
    for (let i = 0; i < route.length - 1; i++) {
        const edge = route[i] + route[i + 1];
        totalCost += costs[edge] || 0;
    }
    return totalCost;
}

function find_optimal_route(routes: string[][], costs: { [key: string]: number }): string[] | null {
    let min_cost = Infinity;
    let best_route: string[] | null = null;
    for (const route of routes) {
        const cost = calculate_cost(route, costs);
        if (cost < min_cost) {
            min_cost = cost;
            best_route = route;
        }
    }
    return best_route;
}

function main() {
    const routes = [['A', 'B', 'C'], ['A', 'C', 'B'], ['B', 'A', 'C']];
    const costs = { 'AB': 10, 'BC': 15, 'CA': 20 };
    const optimal_route = find_optimal_route(routes, costs);
    console.log(optimal_route);
}

main();