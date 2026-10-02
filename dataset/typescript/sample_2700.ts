class Graph {
    nodes: { [key: string]: Array<[string, number]> };

    constructor() {
        this.nodes = {};
    }

    add_node(node: string) {
        this.nodes[node] = [];
    }

    add_edge(node1: string, node2: string, weight: number) {
        if (this.nodes[node1] && this.nodes[node2]) {
            this.nodes[node1].push([node2, weight]);
            this.nodes[node2].push([node1, weight]);
        }
    }
}

class PathFinder {
    graph: Graph;

    constructor(graph: Graph) {
        this.graph = graph;
    }

    find_shortest_path(start: string, end: string): string[] {
        let queue: Array<[string, number]> = [[start, 0]];
        let visited: Set<string> = new Set();
        let paths: { [key: string]: string[] } = { [start]: [] };
        while (queue.length > 0) {
            let [node, distance] = queue.shift()!;
            if (node === end) {
                return paths[node].concat(node);
            }
            if (!visited.has(node)) {
                visited.add(node);
                for (let [neighbor, weight] of this.graph.nodes[node]) {
                    if (!visited.has(neighbor)) {
                        queue.push([neighbor, distance + weight]);
                        paths[neighbor] = paths[node].concat(node);
                    }
                }
            }
        }
        return [];
    }
}

function main() {
    let g = new Graph();
    g.add_node('A');
    g.add_node('B');
    g.add_node('C');
    g.add_node('D');
    g.add_node('E');
    g.add_node('F');
    g.add_node('G');
    g.add_edge('A', 'B', 1);
    g.add_edge('A', 'C', 4);
    g.add_edge('B', 'C', 2);
    g.add_edge('B', 'D', 5);
    g.add_edge('C', 'D', 1);
    g.add_edge('C', 'E', 3);
    g.add_edge('D', 'E', 1);
    g.add_edge('D', 'F', 8);
    g.add_edge('E', 'F', 2);
    g.add_edge('E', 'G', 2);
    g.add_edge('F', 'G', 7);
    let pf = new PathFinder(g);
    let path = pf.find_shortest_path('A', 'G');
    console.log(path);
}

main();