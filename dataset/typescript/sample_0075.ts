function optimize_supply_chain(data: { distances: { [key: string]: { [key: string]: number } }; routes: string[][] }): string[] {
    function calculate_cost(route: string[]): number {
        return route.reduce((acc, city, i) => acc + (i < route.length - 1 ? data.distances[city][route[i + 1]] : 0), 0);
    }

    function find_best_route(routes: string[][]): string[] {
        return routes.reduce((best, current) => calculate_cost(current) < calculate_cost(best) ? current : best);
    }

    const routes = data.routes;
    const best_route = find_best_route(routes);
    return best_route;
}

const data = {
    distances: {
        'A': { 'B': 10, 'C': 15 },
        'B': { 'A': 10, 'C': 35 },
        'C': { 'A': 15, 'B': 35 }
    },
    routes: [['A', 'B', 'C'], ['A', 'C', 'B']]
};

optimize_supply_chain(data);