class SupplyChainOptimizer {
    constructor(nodes, edges, demand) {
        this.nodes = nodes;
        this.edges = edges;
        this.demand = demand;
        this.optimized_path = [];
    }

    find_optimal_path(start, end, path = []) {
        path = path.concat(start);
        if (start === end) {
            return path;
        }
        if (!this.edges[start]) {
            return null;
        }
        let shortest = null;
        for (let node in this.edges[start]) {
            if (!path.includes(node)) {
                let newpath = this.find_optimal_path(node, end, path);
                if (newpath) {
                    if (!shortest || newpath.length < shortest.length) {
                        shortest = newpath;
                    }
                }
            }
        }
        return shortest;
    }

    calculate_supply(path) {
        let supply = 0;
        for (let i = 0; i < path.length - 1; i++) {
            supply += this.edges[path[i]][path[i + 1]];
        }
        return supply;
    }

    optimize() {
        for (let start of this.nodes) {
            for (let end of this.nodes) {
                if (start !== end) {
                    let path = this.find_optimal_path(start, end);
                    if (path && this.demand <= this.calculate_supply(path)) {
                        this.optimized_path = path;
                        return;
                    }
                }
            }
        }
        return null;
    }
}

function main() {
    let nodes = ['A', 'B', 'C', 'D'];
    let edges = {'A': {'B': 10, 'C': 5}, 'B': {'D': 8}, 'C': {'D': 12}, 'D': {}};
    let demand = 15;
    let optimizer = new SupplyChainOptimizer(nodes, edges, demand);
    optimizer.optimize();
    console.log(optimizer.optimized_path);
}

main();