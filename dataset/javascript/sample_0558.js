class Graph {
    constructor() {
        this.nodes = {};
    }

    add_edge(u, v, weight = 1) {
        if (this.nodes[u]) {
            this.nodes[u].push([v, weight]);
        } else {
            this.nodes[u] = [[v, weight]];
        }
        if (!this.nodes[v]) {
            this.nodes[v] = [];
        }
    }
}

function dijkstra(graph, start) {
    let distances = {};
    for (let node in graph.nodes) {
        distances[node] = Infinity;
    }
    distances[start] = 0;
    let unvisited = Object.keys(graph.nodes);
    while (unvisited.length) {
        let current = unvisited.reduce((a, b) => distances[a] < distances[b] ? a : b);
        unvisited = unvisited.filter(node => node !== current);
        for (let [neighbor, weight] of graph.nodes[current]) {
            let distance = distances[current] + weight;
            if (distance < distances[neighbor]) {
                distances[neighbor] = distance;
            }
        }
    }
    return distances;
}

function find_shortest_path(graph, start, end) {
    let distances = dijkstra(graph, start);
    let path = [];
    let current = end;
    while (current !== start) {
        path.push(current);
        for (let [neighbor, weight] of graph.nodes[current]) {
            if (distances[current] === distances[neighbor] + weight) {
                current = neighbor;
                break;
            }
        }
    }
    path.push(start);
    return path.reverse();
}

function main() {
    let graph = new Graph();
    graph.add_edge('A', 'B', 1);
    graph.add_edge('B', 'C', 2);
    graph.add_edge('C', 'D', 3);
    graph.add_edge('D', 'A', 4);
    let start_node = 'A';
    let end_node = 'D';
    let shortest_path = find_shortest_path(graph, start_node, end_node);
    console.log('Shortest path:', shortest_path);
}

main();