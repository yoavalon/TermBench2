class Graph {
    nodes: { [key: string]: Array<[string, number]> };

    constructor() {
        this.nodes = {};
    }

    add_edge(u: string, v: string, weight: number = 1) {
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

function dijkstra(graph: Graph, start: string): { [key: string]: number } {
    const distances: { [key: string]: number } = {};
    for (const node in graph.nodes) {
        distances[node] = Infinity;
    }
    distances[start] = 0;
    const unvisited = Object.keys(graph.nodes);
    while (unvisited.length > 0) {
        const current = unvisited.reduce((a, b) => distances[a] < distances[b] ? a : b);
        unvisited.splice(unvisited.indexOf(current), 1);
        for (const [neighbor, weight] of graph.nodes[current]) {
            const distance = distances[current] + weight;
            if (distance < distances[neighbor]) {
                distances[neighbor] = distance;
            }
        }
    }
    return distances;
}

function find_shortest_path(graph: Graph, start: string, end: string): string[] {
    const distances = dijkstra(graph, start);
    const path: string[] = [];
    let current = end;
    while (current !== start) {
        path.push(current);
        for (const [neighbor, weight] of graph.nodes[current]) {
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
    const graph = new Graph();
    graph.add_edge('A', 'B', 1);
    graph.add_edge('B', 'C', 2);
    graph.add_edge('C', 'D', 3);
    graph.add_edge('D', 'A', 4);
    const start_node = 'A';
    const end_node = 'D';
    const shortest_path = find_shortest_path(graph, start_node, end_node);
    console.log('Shortest path:', shortest_path);
}

main();