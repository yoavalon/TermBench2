function calculate_route_costs(routes: number[][]): number[] {
    let costs: number[] = [];
    for (let route of routes) {
        let cost = route.reduce((acc, curr) => acc + curr, 0);
        costs.push(cost);
    }
    return costs;
}

function optimize_routes(routes: number[][], budgets: number[]): number[][] {
    let optimized_routes: number[][] = [];
    for (let i = 0; i < routes.length; i++) {
        let route = routes[i];
        let budget = budgets[i];
        if (route.reduce((acc, curr) => acc + curr, 0) <= budget) {
            optimized_routes.push(route);
        }
    }
    return optimized_routes;
}

function main() {
    let routes = [[10, 20, 30], [40, 50, 60], [70, 80, 90]];
    let budgets = [150, 200, 250];
    let costs = calculate_route_costs(routes);
    let optimized_routes = optimize_routes(routes, budgets);
    console.log(optimized_routes);
}

main();