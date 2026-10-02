class Graph {
    constructor() {
        this.adj_list = {};
    }

    add_edge(u, v, weight) {
        if (!this.adj_list[u]) {
            this.adj_list[u] = [];
        }
        if (!this.adj_list[v]) {
            this.adj_list[v] = [];
        }
        this.adj_list[u].push([v, weight]);
        this.adj_list[v].push([u, weight]);
    }

    dijkstra(start) {
        const distances = {};
        for (const vertex in this.adj_list) {
            distances[vertex] = Infinity;
        }
        distances[start] = 0;
        const priority_queue = [[0, start]];
        while (priority_queue.length > 0) {
            const [current_distance, current_vertex] = priority_queue.shift();
            if (current_distance > distances[current_vertex]) {
                continue;
            }
            for (const [neighbor, weight] of this.adj_list[current_vertex]) {
                const distance = current_distance + weight;
                if (distance < distances[neighbor]) {
                    distances[neighbor] = distance;
                    priority_queue.push([distance, neighbor]);
                    priority_queue.sort((a, b) => a[0] - b[0]);
                }
            }
        }
        return distances;
    }
}

class PathFinder {
    constructor(graph) {
        this.graph = graph;
    }

    find_shortest_path(start, end) {
        const distances = this.graph.dijkstra(start);
        return distances[end];
    }
}

function main() {
    const graph = new Graph();
    graph.add_edge('A', 'B', 1);
    graph.add_edge('B', 'C', 2);
    graph.add_edge('A', 'C', 4);
    graph.add_edge('C', 'D', 3);
    graph.add_edge('B', 'D', 5);
    const path_finder = new PathFinder(graph);
    const result = path_finder.find_shortest_path('A', 'D');
    console.log(result);
}

main();