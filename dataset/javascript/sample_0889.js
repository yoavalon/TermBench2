class SupplyChainOptimizer {
    constructor(nodes, edges, capacity) {
        this.nodes = nodes;
        this.edges = edges;
        this.capacity = capacity;
        this.flow = Array.from({ length: nodes }, () => Array(nodes).fill(0));
    }

    find_path(source, sink, parent) {
        let visited = new Array(this.nodes).fill(false);
        let queue = [source];
        visited[source] = true;
        while (queue.length > 0) {
            let u = queue.shift();
            for (let ind = 0; ind < this.nodes; ind++) {
                if (!visited[ind] && this.capacity[u][ind] - this.flow[u][ind] > 0) {
                    queue.push(ind);
                    visited[ind] = true;
                    parent[ind] = u;
                    if (ind == sink) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    optimize_flow(source, sink) {
        let parent = new Array(this.nodes).fill(-1);
        let max_flow = 0;
        while (this.find_path(source, sink, parent)) {
            let path_flow = Infinity;
            let s = sink;
            while (s != source) {
                path_flow = Math.min(path_flow, this.capacity[parent[s]][s] - this.flow[parent[s]][s]);
                s = parent[s];
            }
            let v = sink;
            while (v != source) {
                let u = parent[v];
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
    let nodes = 6;
    let edges = 7;
    let capacity = [
        [0, 16, 13, 0, 0, 0],
        [0, 0, 10, 12, 0, 0],
        [0, 4, 0, 0, 14, 0],
        [0, 0, 9, 0, 0, 20],
        [0, 0, 0, 7, 0, 4],
        [0, 0, 0, 0, 0, 0]
    ];
    let source = 0;
    let sink = 5;
    let optimizer = new SupplyChainOptimizer(nodes, edges, capacity);
    let result = optimizer.optimize_flow(source, sink);
    console.log('The maximum possible flow is ' + result);
}

main();