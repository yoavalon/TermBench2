class Graph {
    nodes: string[];
    edges: { [key: string]: [string, number][] };

    constructor(nodes: string[]) {
        this.nodes = nodes;
        this.edges = {};
        for (const node of nodes) {
            this.edges[node] = [];
        }
    }

    add_edge(node1: string, node2: string, weight: number) {
        this.edges[node1].push([node2, weight]);
        this.edges[node2].push([node1, weight]);
    }
}

function dijkstra(graph: Graph, start: string, end: string): string[] {
    const queue: [number, string, string[]][] = [];
    queue.push([0, start, []]);
    const visited = new Set<string>();
    while (queue.length > 0) {
        const [cost, node, path] = queue.shift()!;
        if (node === end) {
            return path.concat([node]);
        }
        if (!visited.has(node)) {
            visited.add(node);
            for (const [neighbor, weight] of graph.edges[node]) {
                if (!visited.has(neighbor)) {
                    queue.push([cost + weight, neighbor, path.concat([node])]);
                }
            }
        }
    }
    return [];
}

function main() {
    const nodes = ['A', 'B', 'C', 'D', 'E'];
    const graph = new Graph(nodes);
    graph.add_edge('A', 'B', 1);
    graph.add_edge('B', 'C', 2);
    graph.add_edge('C', 'D', 3);
    graph.add_edge('D', 'E', 4);
    graph.add_edge('E', 'A', 5);
    const path = dijkstra(graph, 'A', 'E');
    console.log(path);
}

main();