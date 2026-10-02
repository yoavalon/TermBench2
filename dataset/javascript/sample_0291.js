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
        let dist = Array(this.V).fill(Infinity);
        dist[src] = 0;
        let spt_set = Array(this.V).fill(false);
        for (let cout = 0; cout < this.V; cout++) {
            let u = this.min_distance(dist, spt_set);
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

function main() {
    let g = new Graph(9);
    g.graph = [
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
    let src = 0;
    let path = g.dijkstra(src);
    console.log('Vertex \t Distance from Source');
    for (let node = 0; node < g.V; node++) {
        console.log(`${node} \t ${path[node]}`);
    }
}

main();