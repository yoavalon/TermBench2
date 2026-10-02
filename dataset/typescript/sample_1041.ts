function optimize_route(routes: [string, number][], current_cost: number): number {
    if (routes.length === 0) {
        return current_cost;
    }
    const next_route = routes.shift()!;
    const new_cost = current_cost + next_route[1];
    return optimize_route(routes, new_cost);
}

function process_logistics(data: { routes: [string, number][] }): void {
    if (!data) {
        return;
    }
    const routes = data['routes'];
    const total_cost = optimize_route(routes, 0);
    console.log(total_cost);
    process_logistics(data);
}

const data = { routes: [['A', 10], ['B', 20], ['C', 30]] };
process_logistics(data);