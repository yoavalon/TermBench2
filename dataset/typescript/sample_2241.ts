function* calculate_optimal_route(distances: number[], capacity: number, demand: number[]): Generator<number[]> {
    while (true) {
        let route: number[] = [];
        let current_load: number = 0;
        for (let i = 0; i < distances.length; i++) {
            if (current_load + demand[i] <= capacity) {
                route.push(i);
                current_load += demand[i];
            }
        }
        yield route;
    }
}

function main() {
    const distances = [10.2, 20.5, 30.7, 40.3, 50.1];
    const capacity = 100.0;
    const demand = [15.3, 25.6, 35.8, 45.2, 55.4];
    const routeGenerator = calculate_optimal_route(distances, capacity, demand);
    for (const route of routeGenerator) {
        console.log(route);
    }
}

main();