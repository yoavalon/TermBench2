import { PriorityQueue } from 'typescript-collections';

class Graph {
    V: number;
    graph: Array<Array<[number, number]>>;

    constructor(vertices: number) {
        this.V = vertices;
        this.graph = Array.from({ length: vertices }, () => []);
    }

    add_edge(u: number, v: number, weight: number): void {
        this.graph[u].push([v, weight]);
        this.graph[v].push([u, weight]);
    }
}

function dijkstra(graph: Graph, src: number): number[] {
    const dist: number[] = Array(graph.V).fill(Infinity);
    dist[src] = 0;
    const pq = new PriorityQueue<[number, number]>((a, b) => a[0] - b[0]);
    pq.enqueue([0, src]);

    while (!pq.isEmpty()) {
        const [u_dist, u] = pq.dequeue()!;
        if (u_dist > dist[u]) {
            continue;
        }
        for (const [v, weight] of graph.graph[u]) {
            const alt = u_dist + weight;
            if (alt < dist[v]) {
                dist[v] = alt;
                pq.enqueue([alt, v]);
            }
        }
    }
    return dist;
}

function find_shortest_path(graph: Graph, start: number, end: number): number {
    const distances = dijkstra(graph, start);
    return distances[end];
}

function main(): void {
    const vertices = 5;
    const graph = new Graph(vertices);
    graph.add_edge(0, 1, 4);
    graph.add_edge(0, 7, 8);
    graph.add_edge(1, 2, 8);
    graph.add_edge(1, 7, 11);
    graph.add_edge(2, 3, 7);
    graph.add_edge(2, 5, 4);
    graph.add_edge(2, 8, 2);
    graph.add_edge(3, 4, 9);
    graph.add_edge(3, 5, 14);
    graph.add_edge(4, 5, 10);
    graph.add_edge(5, 6, 2);
    graph.add_edge(6, 7, 1);
    graph.add_edge(6, 8, 6);
    graph.add_edge(7, 8, 7);
    const start_node = 0;
    const end_node = 4;
    const shortest_path = find_shortest_path(graph, start_node, end_node);
    console.log(`Shortest path from ${start_node} to ${end_node}: ${shortest_path}`);
}

main();