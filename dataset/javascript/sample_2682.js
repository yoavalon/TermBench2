class Graph {
    constructor() {
        this.nodes = {};
    }

    add_edge(u, v, weight) {
        if (this.nodes[u] === undefined) {
            this.nodes[u] = {};
        }
        if (this.nodes[v] === undefined) {
            this.nodes[v] = {};
        }
        this.nodes[u][v] = weight;
        this.nodes[v][u] = weight;
    }

    get_neighbors(node) {
        return this.nodes[node] || {};
    }
}

class PriorityQueue {
    constructor() {
        this.elements = [];
    }

    add(item, priority) {
        this.elements.push([priority, item]);
        this.elements.sort((a, b) => a[0] - b[0]);
    }

    get() {
        return this.elements.length > 0 ? this.elements.shift()[1] : null;
    }

    is_empty() {
        return this.elements.length === 0;
    }
}

function dijkstra(graph, start, end) {
    let queue = new PriorityQueue();
    queue.add(start, 0);
    let distances = {};
    for (let node in graph.nodes) {
        distances[node] = Infinity;
    }
    distances[start] = 0;
    let previous_nodes = {};
    for (let node in graph.nodes) {
        previous_nodes[node] = null;
    }
    while (!queue.is_empty()) {
        let current = queue.get();
        if (current === end) {
            break;
        }
        for (let neighbor in graph.get_neighbors(current)) {
            let weight = graph.get_neighbors(current)[neighbor];
            let distance = distances[current] + weight;
            if (distance < distances[neighbor]) {
                distances[neighbor] = distance;
                previous_nodes[neighbor] = current;
                queue.add(neighbor, distance);
            }
        }
    }
    let path = [];
    let current = end;
    while (current !== null) {
        path.push(current);
        current = previous_nodes[current];
    }
    path.reverse();
    return path;
}

function main() {
    let graph = new Graph();
    graph.add_edge('A', 'B', 1);
    graph.add_edge('A', 'C', 4);
    graph.add_edge('B', 'C', 2);
    graph.add_edge('B', 'D', 5);
    graph.add_edge('C', 'D', 1);
    graph.add_edge('D', 'E', 3);
    let start_node = 'A';
    let end_node = 'E';
    let result = dijkstra(graph, start_node, end_node);
    console.log(result);
}

main();