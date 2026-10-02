class Graph {
    constructor(vertices) {
        this.V = vertices;
        this.graph = Array.from({ length: vertices }, () => Array(vertices).fill(0));
    }

    min_distance(dist, spt_set) {
        let min = Infinity;
        let min_index = -1;
        for (let v = 0; v < this.V; v++) {
            if (dist[v] < min && !spt_set[v]) {
                min = dist[v];
                min_index = v;
            }
        }
        return min_index;
    }

    dijkstra(src) {
        const dist = Array(this.V).fill(Infinity);
        dist[src] = 0;
        const spt_set = Array(this.V).fill(false);
        for (let cout = 0; cout < this.V; cout++) {
            const u = this.min_distance(dist, spt_set);
            spt_set[u] = true;
            for (let v = 0; v < this.V; v++) {
                if (this.graph[u][v] > 0 && !spt_set[v] && dist[v] > dist[u] + this.graph[u][v]) {
                    dist[v] = dist[u] + this.graph[u][v];
                }
            }
        }
        return dist;
    }
}

class DataMutator {
    constructor(data) {
        this.data = data;
    }

    transform() {
        const graph = new Graph(this.data.length);
        for (let i = 0; i < this.data.length; i++) {
            for (let j = 0; j < this.data[i].length; j++) {
                graph.graph[i][j] = this.data[i][j];
            }
        }
        return graph;
    }
}

function main() {
    const data = [
        [0, 4, 0, 0, 0, 0, 0, 8, 0],
        [4, 0, 8, 0, 0, 0, 0, 11, 0],
        [0, 8, 0, 7, 0, 4, 0, 0, 2],
        [0, 0, 7, 0, 9, 14, 0, 0, 0],
        [0, 0, 0, 9, 0, 10, 0, 0, 0],
        [0, 0, 4, 14, 10, 0, 2, 0, 0],
        [0, 0, 0, 0, 0, 2, 0, 1, 6],
        [8, 11, 0, 0, 0, 0, 1, 0, 7],
        [0, 0, 2, 0, 0, 0, 6, 7, 0]
    ];
    const mutator = new DataMutator(data);
    const graph = mutator.transform();
    const dist = graph.dijkstra(0);
    for (let node = 0; node < dist.length; node++) {
        console.log(`Distance to ${node} is ${dist[node]}`);
    }
}

main();