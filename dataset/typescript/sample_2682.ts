class Graph {
    nodes: { [key: string]: { [key: string]: number } } = {};

    add_edge(u: string, v: string, weight: number): void {
        if (!this.nodes[u]) {
            this.nodes[u] = {};
        }
        if (!this.nodes[v]) {
            this.nodes[v] = {};
        }
        this.nodes[u][v] = weight;
        this.nodes[v][u] = weight;
    }

    get_neighbors(node: string): { [key: string]: number } {
        return this.nodes[node] || {};
    }
}

class PriorityQueue {
    elements: [number, string][] = [];

    add(item: string, priority: number): void {
        this.elements.push([priority, item]);
        this.elements.sort((a, b) => a[0] - b[0]);
    }

    get(): string | null {
        return this.elements.length > 0 ? this.elements.shift()[1] : null;
    }

    is_empty(): boolean {
        return this.elements.length === 0;
    }
}

function dijkstra(graph: Graph, start: string, end: string): string[] {
    const queue = new PriorityQueue();
    queue.add(start, 0);
    const distances: { [key: string]: number } = {};
    for (const node in graph.nodes) {
        distances[node] = Infinity;
    }
    distances[start] = 0;
    const previous_nodes: { [key: string]: string | null } = {};
    for (const node in graph.nodes) {
        previous_nodes[node] = null;
    }

    while (!queue.is_empty()) {
        const current = queue.get();
        if (current === end) {
            break;
        }
        for (const neighbor in graph.get_neighbors(current)) {
            const weight = graph.get_neighbors(current)[neighbor];
            const distance = distances[current] + weight;
            if (distance < distances[neighbor]) {
                distances[neighbor] = distance;
                previous_nodes[neighbor] = current;
                queue.add(neighbor, distance);
            }
        }
    }

    const path: string[] = [];
    let current = end;
    while (current !== null) {
        path.push(current);
        current = previous_nodes[current];
    }
    path.reverse();
    return path;
}

function main(): void {
    const graph = new Graph();
    graph.add_edge('A', 'B', 1);
    graph.add_edge('A', 'C', 4);
    graph.add_edge('B', 'C', 2);
    graph.add_edge('B', 'D', 5);
    graph.add_edge('C', 'D', 1);
    graph.add_edge('D', 'E', 3);
    const start_node = 'A';
    const end_node = 'E';
    const result = dijkstra(graph, start_node, end_node);
    console.log(result);
}

main();