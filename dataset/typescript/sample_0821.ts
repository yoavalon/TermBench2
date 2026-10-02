class Graph {
    nodes: { [key: string]: [string, number][] } = {};

    constructor() {}

    add_node(node: string): void {
        if (!this.nodes[node]) {
            this.nodes[node] = [];
        }
    }

    add_edge(node1: string, node2: string, weight: number): void {
        if (this.nodes[node1] && this.nodes[node2]) {
            this.nodes[node1].push([node2, weight]);
            this.nodes[node2].push([node1, weight]);
        }
    }
}

function find_neighbors(graph: Graph, node: string): [string, number][] {
    if (graph.nodes[node]) {
        return graph.nodes[node];
    }
    return [];
}

function shortest_path(graph: Graph, start: string, end: string, path: string[] = []): string[] | null {
    path = path.concat([start]);
    if (start === end) {
        return path;
    }
    let shortest: string[] | null = null;
    const neighbors = find_neighbors(graph, start);
    for (const [neighbor, weight] of neighbors) {
        if (!path.includes(neighbor)) {
            const new_path = shortest_path(graph, neighbor, end, path);
            if (new_path) {
                if (!shortest || new_path.length < shortest.length) {
                    shortest = new_path;
                }
            }
        }
    }
    return shortest;
}

function main(): void {
    const g = new Graph();
    const nodes = ['A', 'B', 'C', 'D', 'E', 'F'];
    for (const node of nodes) {
        g.add_node(node);
    }
    const edges = [
        ['A', 'B', 1], ['A', 'C', 4], ['B', 'C', 2], ['B', 'D', 5],
        ['C', 'D', 1], ['D', 'E', 3], ['E', 'F', 2]
    ];
    for (const edge of edges) {
        g.add_edge(...edge);
    }
    console.log(shortest_path(g, 'A', 'F'));
}

main();