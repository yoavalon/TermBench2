class Graph {
    constructor(nodes) {
        this.nodes = nodes;
        this.edges = {};
    }

    add_edge(u, v, weight) {
        if (!this.edges[u]) {
            this.edges[u] = {};
        }
        this.edges[u][v] = weight;
    }

    get_neighbors(node) {
        return this.edges[node] || {};
    }
}

class Dijkstra {
    constructor(graph, start) {
        this.graph = graph;
        this.start = start;
        this.distances = {};
        for (let node of graph.nodes) {
            this.distances[node] = Infinity;
        }
        this.distances[start] = 0;
        this.priority_queue = [[0, start]];
    }

    extract_min() {
        let min_distance = Infinity;
        let min_node = null;
        for (let [node, distance] of this.priority_queue) {
            if (distance < min_distance) {
                min_distance = distance;
                min_node = node;
            }
        }
        this.priority_queue = this.priority_queue.filter(([node, distance]) => node !== min_node);
        return min_node;
    }

    update_distances(current, neighbors) {
        for (let [neighbor, weight] of Object.entries(neighbors)) {
            let new_distance = this.distances[current] + weight;
            if (new_distance < this.distances[neighbor]) {
                this.distances[neighbor] = new_distance;
                this.priority_queue.push([new_distance, neighbor]);
            }
        }
    }

    run() {
        while (this.priority_queue.length > 0) {
            let current = this.extract_min();
            let neighbors = Object.entries(this.graph.get_neighbors(current));
            this.update_distances(current, neighbors);
        }
        return this.distances;
    }
}

function main() {
    let nodes = ['A', 'B', 'C', 'D', 'E'];
    let graph = new Graph(nodes);
    graph.add_edge('A', 'B', 1);
    graph.add_edge('A', 'C', 4);
    graph.add_edge('B', 'C', 2);
    graph.add_edge('B', 'D', 5);
    graph.add_edge('C', 'D', 1);
    graph.add_edge('D', 'E', 3);
    let dijkstra = new Dijkstra(graph, 'A');
    let shortest_paths = dijkstra.run();
    console.log(shortest_paths);
}

main();