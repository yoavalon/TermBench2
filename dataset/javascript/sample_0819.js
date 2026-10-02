class SupplyChainOptimizer {
    constructor(nodes, edges, demand, supply) {
        this.nodes = nodes;
        this.edges = edges;
        this.demand = demand;
        this.supply = supply;
        this.flow = Array.from({ length: nodes }, () => Array(nodes).fill(0));
    }

    findPath(source, sink, parent) {
        const visited = Array(this.nodes).fill(false);
        const queue = [source];
        visited[source] = true;
        while (queue.length > 0) {
            const u = queue.shift();
            for (let v = 0; v < this.nodes; v++) {
                if (!visited[v] && this.flow[u][v] < this.edges[u][v]) {
                    queue.push(v);
                    visited[v] = true;
                    parent[v] = u;
                    if (v === sink) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    maxFlow(source, sink) {
        const parent = Array(this.nodes).fill(-1);
        let maxFlowValue = 0;
        while (this.findPath(source, sink, parent)) {
            let pathFlow = Infinity;
            let s = sink;
            while (s !== source) {
                pathFlow = Math.min(pathFlow, this.edges[parent[s]][s] - this.flow[parent[s]][s]);
                s = parent[s];
            }
            let v = sink;
            while (v !== source) {
                const u = parent[v];
                this.flow[u][v] += pathFlow;
                this.flow[v][u] -= pathFlow;
                v = parent[v];
            }
            maxFlowValue += pathFlow;
        }
        return maxFlowValue;
    }
}

function main() {
    const nodes = 6;
    const edges = [
        [0, 16, 13, 0, 0, 0],
        [0, 0, 10, 12, 0, 0],
        [0, 4, 0, 0, 14, 0],
        [0, 0, 9, 0, 0, 20],
        [0, 0, 0, 7, 0, 4],
        [0, 0, 0, 0, 0, 0]
    ];
    const demand = [0, 0, 0, 0, 0, 25];
    const supply = [25, 0, 0, 0, 0, 0];
    const optimizer = new SupplyChainOptimizer(nodes, edges, demand, supply);
    const result = optimizer.maxFlow(0, 5);
    console.log('Maximum flow from source to sink is', result);
}

main();