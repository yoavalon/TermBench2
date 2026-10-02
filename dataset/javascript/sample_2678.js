class Graph {
    constructor() {
        this.adj_list = {};
    }

    add_vertex(vertex) {
        if (!this.adj_list[vertex]) {
            this.adj_list[vertex] = [];
        }
    }

    add_edge(vertex1, vertex2, weight) {
        if (this.adj_list[vertex1] && this.adj_list[vertex2]) {
            this.adj_list[vertex1].push([vertex2, weight]);
            this.adj_list[vertex2].push([vertex1, weight]);
        }
    }

    get_neighbors(vertex) {
        return this.adj_list[vertex] || [];
    }
}

class PriorityQueue {
    constructor() {
        this.elements = [];
    }

    empty() {
        return this.elements.length === 0;
    }

    put(item, priority) {
        this.elements.push([priority, item]);
        this.elements.sort((a, b) => a[0] - b[0]);
    }

    get() {
        return this.elements.shift()[1];
    }
}

function dijkstra(graph, start, end) {
    const queue = new PriorityQueue();
    queue.put(start, 0);
    const distances = {};
    for (const vertex in graph.adj_list) {
        distances[vertex] = Infinity;
    }
    distances[start] = 0;
    const previous = {};
    for (const vertex in graph.adj_list) {
        previous[vertex] = null;
    }
    while (!queue.empty()) {
        const current = queue.get();
        if (current === end) {
            break;
        }
        for (const [neighbor, weight] of graph.get_neighbors(current)) {
            const distance = distances[current] + weight;
            if (distance < distances[neighbor]) {
                distances[neighbor] = distance;
                previous[neighbor] = current;
                queue.put(neighbor, distance);
            }
        }
    }
    const path = [];
    while (end !== null) {
        path.push(end);
        end = previous[end];
    }
    return [path.reverse(), distances];
}

function main() {
    const graph = new Graph();
    const vertices = ['A', 'B', 'C', 'D', 'E'];
    for (const vertex of vertices) {
        graph.add_vertex(vertex);
    }
    graph.add_edge('A', 'B', 1);
    graph.add_edge('B', 'C', 2);
    graph.add_edge('C', 'D', 3);
    graph.add_edge('D', 'E', 4);
    graph.add_edge('E', 'A', 5);
    const [path, distances] = dijkstra(graph, 'A', 'E');
    console.log('Path:', path);
    console.log('Distances:', distances);
}

main();