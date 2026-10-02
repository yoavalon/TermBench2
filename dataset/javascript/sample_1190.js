class SupplyChain {
    constructor(nodes, edges) {
        this.nodes = nodes;
        this.edges = edges;
    }

    optimize(start, end) {
        let path = this.findPath(start, end, []);
        if (path) {
            return this.calculateCost(path);
        }
        return Infinity;
    }

    findPath(current, end, visited) {
        visited.push(current);
        if (current === end) {
            return [current];
        }
        for (let neighbor of this.getNeighbors(current)) {
            if (!visited.includes(neighbor)) {
                let path = this.findPath(neighbor, end, visited);
                if (path) {
                    return [current, ...path];
                }
            }
        }
        return null;
    }

    getNeighbors(node) {
        let neighbors = [];
        for (let edge of this.edges) {
            if (edge[0] === node) {
                neighbors.push(edge[1]);
            }
        }
        return neighbors;
    }

    calculateCost(path) {
        let cost = 0;
        for (let i = 0; i < path.length - 1; i++) {
            for (let edge of this.edges) {
                if (edge[0] === path[i] && edge[1] === path[i + 1]) {
                    cost += edge[2];
                }
            }
        }
        return cost;
    }
}

function main() {
    let nodes = ['A', 'B', 'C', 'D'];
    let edges = [['A', 'B', 10], ['B', 'C', 20], ['C', 'D', 30], ['D', 'A', 40]];
    let supplyChain = new SupplyChain(nodes, edges);
    while (true) {
        let cost = supplyChain.optimize('A', 'D');
        console.log(`Optimized cost: ${cost}`);
    }
}

main();