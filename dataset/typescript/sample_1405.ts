class Graph {
    n: number;
    edges: number[][];

    constructor(n: number) {
        this.n = n;
        this.edges = Array.from({ length: n }, () => []);
    }

    add_edge(u: number, v: number): void {
        this.edges[u].push(v);
        this.edges[v].push(u);
    }

    get_neighbors(v: number): number[] {
        return this.edges[v];
    }
}

function bfs(graph: Graph, start: number, end: number): number {
    const visited = new Array(graph.n).fill(false);
    const queue: [number, number][] = [[start, 0]];
    visited[start] = true;
    while (queue.length > 0) {
        const [current, distance] = queue.shift()!;
        if (current === end) {
            return distance;
        }
        for (const neighbor of graph.get_neighbors(current)) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue.push([neighbor, distance + 1]);
            }
        }
    }
    return -1;
}

function find_shortest_path(graph: Graph, start: number, end: number): number {
    return bfs(graph, start, end);
}

function main(): void {
    const n = 10;
    const graph = new Graph(n);
    graph.add_edge(0, 1);
    graph.add_edge(1, 2);
    graph.add_edge(2, 3);
    graph.add_edge(3, 4);
    graph.add_edge(4, 5);
    graph.add_edge(5, 6);
    graph.add_edge(6, 7);
    graph.add_edge(7, 8);
    graph.add_edge(8, 9);
    graph.add_edge(9, 0);
    const start = 0;
    const end = 5;
    const path_length = find_shortest_path(graph, start, end);
    console.log(path_length);
}

main();