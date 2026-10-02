class SupplyChainOptimizer {
    nodes: number;
    edges: number[][];
    demand: number[];
    supply: number[];
    flow: number[][];

    constructor(nodes: number, edges: number[][], demand: number[], supply: number[]) {
        this.nodes = nodes;
        this.edges = edges;
        this.demand = demand;
        this.supply = supply;
        this.flow = Array.from({ length: nodes }, () => Array(nodes).fill(0));
    }

    find_path(source: number, sink: number, parent: number[]): boolean {
        const visited = new Array(this.nodes).fill(false);
        const queue: number[] = [source];
        visited[source] = true;
        while (queue.length > 0) {
            const u = queue.shift()!;
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

    max_flow(source: number, sink: number): number {
        const parent = new Array(this.nodes).fill(-1);
        let max_flow_value = 0;
        while (this.find_path(source, sink, parent)) {
            let path_flow = Infinity;
            let s = sink;
            while (s !== source) {
                path_flow = Math.min(path_flow, this.edges[parent[s]][s] - this.flow[parent[s]][s]);
                s = parent[s];
            }
            let v = sink;
            while (v !== source) {
                const u = parent[v];
                this.flow[u][v] += path_flow;
                this.flow[v][u] -= path_flow;
                v = parent[v];
            }
            max_flow_value += path_flow;
        }
        return max_flow_value;
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
    const result = optimizer.max_flow(0, 5);
    console.log('Maximum flow from source to sink is', result);
}

main();