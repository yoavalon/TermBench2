class Graph {
    constructor(vertices) {
        this.V = vertices;
        this.graph = Array.from({ length: vertices }, () => Array(vertices).fill(0));
    }

    add_edge(u, v, weight) {
        this.graph[u][v] = weight;
        this.graph[v][u] = weight;
    }

    min_distance(dist, spt_set) {
        let min = Infinity;
        let min_index = -1;
        for (let v = 0; v < this.V; v++) {
            if (dist[v] < min && spt_set[v] === false) {
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
                if (this.graph[u][v] > 0 && spt_set[v] === false && dist[v] > dist[u] + this.graph[u][v]) {
                    dist[v] = dist[u] + this.graph[u][v];
                }
            }
        }
        return dist;
    }
}

class SequenceGenerator {
    constructor(graph) {
        this.graph = graph;
    }

    generate_sequence(start_vertex) {
        let sequence = [];
        while (true) {
            let distances = this.graph.dijkstra(start_vertex);
            let next_vertex = distances.indexOf(Math.min(...distances));
            sequence.push(next_vertex);
            start_vertex = next_vertex;
        }
    }
}

function main() {
    let vertices = 5;
    let graph = new Graph(vertices);
    graph.add_edge(0, 1, 4);
    graph.add_edge(0, 3, 7);
    graph.add_edge(1, 2, 1);
    graph.add_edge(1, 3, 2);
    graph.add_edge(1, 4, 10);
    graph.add_edge(2, 3, 5);
    graph.add_edge(3, 4, 3);
    graph.add_edge(2, 4, 8);
    let sequence_generator = new SequenceGenerator(graph);
    let sequence = sequence_generator.generate_sequence(0);
    for (let vertex of sequence) {
        console.log(vertex);
    }
}

main();