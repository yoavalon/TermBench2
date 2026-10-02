class LogisticsOptimizer {
    data: { [key: string]: { [key: string]: number } };

    constructor(data: { [key: string]: { [key: string]: number } }) {
        this.data = data;
    }

    find_optimal_route(current: string, destination: string, visited: Set<string>): string[] | null {
        if (current === destination) {
            return [destination];
        }
        visited.add(current);
        const neighbors = this.data[current] || {};
        for (const neighbor in neighbors) {
            if (!visited.has(neighbor)) {
                const path = this.find_optimal_route(neighbor, destination, visited);
                if (path) {
                    return [current].concat(path);
                }
            }
        }
        return null;
    }

    calculate_cost(path: string[]): number {
        let cost = 0;
        for (let i = 0; i < path.length - 1; i++) {
            cost += (this.data[path[i]][path[i + 1]] || Infinity);
        }
        return cost;
    }

    optimize(start: string, end: string): [number, string[]] {
        const path = this.find_optimal_route(start, end, new Set());
        if (path) {
            return [this.calculate_cost(path), path];
        }
        return [Infinity, []];
    }
}

function main() {
    const data = { 'A': { 'B': 10, 'C': 15 }, 'B': { 'A': 10, 'D': 20 }, 'C': { 'A': 15, 'D': 30 }, 'D': { 'B': 20, 'C': 30 } };
    const optimizer = new LogisticsOptimizer(data);
    const [cost, path] = optimizer.optimize('A', 'D');
    console.log('Optimal Cost:', cost);
    console.log('Optimal Path:', path);
}

main();