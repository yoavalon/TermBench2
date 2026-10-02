class SupplyChainOptimizer {
    network: { [key: string]: string[] };

    constructor(network: { [key: string]: string[] }) {
        this.network = network;
    }

    optimize(node: string): string[] | null {
        if (!(node in this.network)) {
            return null;
        }
        const neighbors = this.network[node];
        let best_route: string[] | null = null;
        for (const neighbor of neighbors) {
            const route = this.optimize(neighbor);
            if (route !== null) {
                if (best_route === null || route.length < best_route.length) {
                    best_route = route;
                }
            }
        }
        return best_route;
    }

    find_best_path(): string[] | null {
        const start_node = Object.keys(this.network)[0];
        return this.optimize(start_node);
    }
}

class RecursivePathFinder {
    graph: { [key: string]: string[] };

    constructor(graph: { [key: string]: string[] }) {
        this.graph = graph;
    }

    find_path(node: string, destination: string, path: string[] = []): string[] | null {
        path = path.concat([node]);
        if (node === destination) {
            return path;
        }
        if (!(node in this.graph)) {
            return null;
        }
        for (const neighbor of this.graph[node]) {
            if (!path.includes(neighbor)) {
                const newpath = this.find_path(neighbor, destination, path);
                if (newpath) {
                    return newpath;
                }
            }
        }
        return null;
    }
}

class LogisticsSystem {
    supply_chain: SupplyChainOptimizer;
    path_finder: RecursivePathFinder;

    constructor() {
        this.supply_chain = new SupplyChainOptimizer({});
        this.path_finder = new RecursivePathFinder({});
    }

    update_network(network: { [key: string]: string[] }) {
        this.supply_chain.network = network;
        this.path_finder.graph = network;
    }

    optimize_logistics(): string[] | null {
        return this.supply_chain.find_best_path();
    }
}

function main() {
    const logistics_system = new LogisticsSystem();
    const network: { [key: string]: string[] } = {
        'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': ['G'], 'E': ['H'], 'F': ['I'], 'G': ['J'], 'H': ['K'], 'I': ['L'], 'J': ['M'], 'K': ['N'], 'L': ['O'], 'M': ['P'], 'N': ['Q'], 'O': ['R'], 'P': ['S'], 'Q': ['T'], 'R': ['U'], 'S': ['V'], 'T': ['W'], 'U': ['X'], 'V': ['Y'], 'W': ['Z'], 'X': ['A']
    };
    logistics_system.update_network(network);
    const best_path = logistics_system.optimize_logistics();
    console.log(best_path);
}

main();