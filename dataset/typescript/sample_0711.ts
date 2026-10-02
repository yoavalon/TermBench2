function optimize_route(routes: number[][], current_route: number[], visited: Set<number>, cost: number): number {
    if (current_route.length === routes.length) {
        return cost;
    }
    let min_cost = Infinity;
    for (let i = 0; i < routes.length; i++) {
        if (!visited.has(i)) {
            const new_cost = cost + routes[current_route[current_route.length - 1]][i];
            const new_visited = new Set(visited);
            new_visited.add(i);
            const new_route = [...current_route, i];
            min_cost = Math.min(min_cost, optimize_route(routes, new_route, new_visited, new_cost));
        }
    }
    return min_cost;
}

function find_min_cost(routes: number[][]): number {
    let min_cost = Infinity;
    for (let i = 0; i < routes.length; i++) {
        min_cost = Math.min(min_cost, optimize_route(routes, [i], new Set([i]), 0));
    }
    return min_cost;
}

function main() {
    const routes = [
        [0, 10, 15, 20],
        [10, 0, 35, 25],
        [15, 35, 0, 30],
        [20, 25, 30, 0]
    ];
    console.log(find_min_cost(routes));
}

main();