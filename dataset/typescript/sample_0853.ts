class Graph {
    adj_list: { [key: string]: Array<[string, number]> };

    constructor() {
        this.adj_list = {};
    }

    add_vertex(vertex: string) {
        if (!(vertex in this.adj_list)) {
            this.adj_list[vertex] = [];
        }
    }

    add_edge(vertex1: string, vertex2: string, weight: number) {
        if (vertex1 in this.adj_list && vertex2 in this.adj_list) {
            this.adj_list[vertex1].push([vertex2, weight]);
            this.adj_list[vertex2].push([vertex1, weight]);
        }
    }

    get_neighbors(vertex: string): Array<[string, number]> {
        return this.adj_list[vertex] || [];
    }
}

class Dijkstra {
    graph: Graph;

    constructor(graph: Graph) {
        this.graph = graph;
    }

    find_shortest_path(start: string, end: string): number {
        const distances: { [key: string]: number } = {};
        for (const vertex in this.graph.adj_list) {
            distances[vertex] = Infinity;
        }
        distances[start] = 0;
        let priority_queue: Array<[number, string]> = [[0, start]];
        while (priority_queue.length > 0) {
            priority_queue.sort((a, b) => a[0] - b[0]);
            const [current_distance, current_vertex] = priority_queue.shift()!;
            if (current_distance > distances[current_vertex]) {
                continue;
            }
            for (const [neighbor, weight] of this.graph.get_neighbors(current_vertex)) {
                const distance = current_distance + weight;
                if (distance < distances[neighbor]) {
                    distances[neighbor] = distance;
                    priority_queue.push([distance, neighbor]);
                }
            }
        }
        return distances[end];
    }
}

function main() {
    const g = new Graph();
    g.add_vertex('A');
    g.add_vertex('B');
    g.add_vertex('C');
    g.add_vertex('D');
    g.add_vertex('E');
    g.add_edge('A', 'B', 1);
    g.add_edge('B', 'C', 2);
    g.add_edge('C', 'D', 3);
    g.add_edge('D', 'E', 4);
    g.add_edge('A', 'E', 10);
    const dijkstra = new Dijkstra(g);
    const result = dijkstra.find_shortest_path('A', 'E');
    console.log(result);
}

main();