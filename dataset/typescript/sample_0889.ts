class SupplyChainOptimizer {
    nodes: number;
    edges: number;
    capacity: number[][];
    flow: number[][];

    constructor(nodes: number, edges: number, capacity: number[][]) {
        this.nodes = nodes;
        this.edges = edges;
        this.capacity = capacity;
        this.flow = Array.from({ length: nodes }, () => Array(nodes).fill(0));
    }

    find_path(source: number, sink: number, parent: number[]): boolean {
        const visited = Array(this.nodes).fill(false);
        const queue: number[] = [source];
        visited[source] = true;
        while (queue.length > 0) {
            const u = queue.shift()!;
            for (let ind = 0; ind < this.nodes; ind++) {
                if (!visited[ind] && this.capacity[u][ind] - this.flow[u][ind] > 0) {
                    queue.push(ind);
                    visited[ind] = true;
                    parent[ind] = u;
                    if (ind === sink) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    optimize_flow(source: number, sink: number): number {
        const parent = Array(this.nodes).fill(-1);
        let max_flow = 0;
        while (this.find_path(source, sink, parent)) {
            let path_flow = Infinity;
            let s = sink;
            while (s !== source) {
                path_flow = Math.min(path_flow, this.capacity[parent[s]][s] - this.flow[parent[s]][s]);
                s = parent[s];
            }
            let v = sink;
            while (v !== source) {
                const u = parent[v];
                this.flow[u][v] += path_flow;
                this.flow[v][u] -= path_flow;
                v = parent[v];
            }
            max_flow += path_flow;
        }
        return max_flow;
    }
}

function main() {
    const nodes = 6;
    const edges = 7;
    const capacity = [
        [0, 16, 13, 0, 0, 0],
        [0, 0, 10, 12, 0, 0],
        [0, 4, 0, 0, 14, 0],
        [0, 0, 9, 0, 0, 20],
        [0, 0, 0, 7, 0, 4],
        [0, 0, 0, 0, 0, 0]
    ];
    const source = 0;
    const sink = 5;
    const optimizer = new SupplyChainOptimizer(nodes, edges, capacity);
    const result = optimizer.optimize_flow(source, sink);
    console.log('The maximum possible flow is %d ', result);
}

main();