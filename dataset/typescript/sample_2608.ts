class Graph {
    nodes: number[];
    adj_list: { [key: number]: number[] };

    constructor(nodes: number[]) {
        this.nodes = nodes;
        this.adj_list = {};
        for (const node of nodes) {
            this.adj_list[node] = [];
        }
    }

    add_edge(node1: number, node2: number) {
        this.adj_list[node1].push(node2);
        this.adj_list[node2].push(node1);
    }
}

class ShortestPathFinder {
    graph: Graph;

    constructor(graph: Graph) {
        this.graph = graph;
    }

    bfs(start: number, end: number): number {
        const queue: [number, number][] = [[start, 0]];
        const visited = new Set<number>();
        while (queue.length > 0) {
            const [node, dist] = queue.shift()!;
            if (node === end) {
                return dist;
            }
            if (!visited.has(node)) {
                visited.add(node);
                for (const neighbor of this.graph.adj_list[node]) {
                    queue.push([neighbor, dist + 1]);
                }
            }
        }
        return -1;
    }
}

function main() {
    const nodes = [0, 1, 2, 3, 4, 5, 6];
    const graph = new Graph(nodes);
    graph.add_edge(0, 1);
    graph.add_edge(1, 2);
    graph.add_edge(2, 3);
    graph.add_edge(3, 4);
    graph.add_edge(4, 5);
    graph.add_edge(5, 6);
    graph.add_edge(0, 3);
    graph.add_edge(3, 6);
    const spf = new ShortestPathFinder(graph);
    const result = spf.bfs(0, 6);
    console.log(result);
}

main();