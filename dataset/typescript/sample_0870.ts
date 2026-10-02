class SupplyChainOptimizer {
    nodes: string[];
    edges: { [key: string]: { [key: string]: number } };
    demand: number;
    optimized_path: string[];

    constructor(nodes: string[], edges: { [key: string]: { [key: string]: number } }, demand: number) {
        this.nodes = nodes;
        this.edges = edges;
        this.demand = demand;
        this.optimized_path = [];
    }

    find_optimal_path(start: string, end: string, path: string[] = []): string[] | null {
        path = path.concat(start);
        if (start === end) {
            return path;
        }
        if (!(start in this.edges)) {
            return null;
        }
        let shortest: string[] | null = null;
        for (const node in this.edges[start]) {
            if (!path.includes(node)) {
                const newpath = this.find_optimal_path(node, end, path);
                if (newpath) {
                    if (!shortest || newpath.length < shortest.length) {
                        shortest = newpath;
                    }
                }
            }
        }
        return shortest;
    }

    calculate_supply(path: string[]): number {
        let supply = 0;
        for (let i = 0; i < path.length - 1; i++) {
            supply += this.edges[path[i]][path[i + 1]];
        }
        return supply;
    }

    optimize(): void {
        for (const start of this.nodes) {
            for (const end of this.nodes) {
                if (start !== end) {
                    const path = this.find_optimal_path(start, end);
                    if (path && this.demand <= this.calculate_supply(path)) {
                        this.optimized_path = path;
                        return;
                    }
                }
            }
        }
        return;
    }
}

function main() {
    const nodes = ['A', 'B', 'C', 'D'];
    const edges = { 'A': { 'B': 10, 'C': 5 }, 'B': { 'D': 8 }, 'C': { 'D': 12 }, 'D': {} };
    const demand = 15;
    const optimizer = new SupplyChainOptimizer(nodes, edges, demand);
    optimizer.optimize();
    console.log(optimizer.optimized_path);
}

main();