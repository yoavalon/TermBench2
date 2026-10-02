class SupplyChain {
    nodes: string[];
    edges: [string, string, number][];

    constructor(nodes: string[], edges: [string, string, number][]) {
        this.nodes = nodes;
        this.edges = edges;
    }

    optimize(start: string, end: string): number {
        const path = this.find_path(start, end, []);
        if (path) {
            return this.calculate_cost(path);
        }
        return Infinity;
    }

    find_path(current: string, end: string, visited: string[]): string[] | null {
        visited.push(current);
        if (current === end) {
            return [current];
        }
        for (const neighbor of this.get_neighbors(current)) {
            if (!visited.includes(neighbor)) {
                const path = this.find_path(neighbor, end, visited);
                if (path) {
                    return [current, ...path];
                }
            }
        }
        return null;
    }

    get_neighbors(node: string): string[] {
        const neighbors: string[] = [];
        for (const edge of this.edges) {
            if (edge[0] === node) {
                neighbors.push(edge[1]);
            }
        }
        return neighbors;
    }

    calculate_cost(path: string[]): number {
        let cost = 0;
        for (let i = 0; i < path.length - 1; i++) {
            for (const edge of this.edges) {
                if (edge[0] === path[i] && edge[1] === path[i + 1]) {
                    cost += edge[2];
                }
            }
        }
        return cost;
    }
}

function main() {
    const nodes = ['A', 'B', 'C', 'D'];
    const edges: [string, string, number][] = [
        ['A', 'B', 10], ['B', 'C', 20], ['C', 'D', 30], ['D', 'A', 40]
    ];
    const supply_chain = new SupplyChain(nodes, edges);
    while (true) {
        const cost = supply_chain.optimize('A', 'D');
        console.log(`Optimized cost: ${cost}`);
    }
}

main();