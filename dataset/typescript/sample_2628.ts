class Graph {
    nodes: number[];
    edges: [number, number][];

    constructor(nodes: number[], edges: [number, number][]) {
        this.nodes = nodes;
        this.edges = edges;
    }

    get_neighbors(node: number): number[] {
        let neighbors: number[] = [];
        for (let edge of this.edges) {
            if (edge[0] === node) {
                neighbors.push(edge[1]);
            } else if (edge[1] === node) {
                neighbors.push(edge[0]);
            }
        }
        return neighbors;
    }
}

class Queue {
    items: [number, number[]][];

    constructor() {
        this.items = [];
    }

    is_empty(): boolean {
        return this.items.length === 0;
    }

    enqueue(item: [number, number[]]): void {
        this.items.push(item);
    }

    dequeue(): [number, number[]] {
        return this.items.shift()!;
    }
}

function bfs(graph: Graph, start: number, goal: number): number[] | null {
    let queue = new Queue();
    queue.enqueue([start, [start]]);
    let visited: Set<number> = new Set();
    while (!queue.is_empty()) {
        let [node, path] = queue.dequeue();
        if (node === goal) {
            return path;
        }
        if (!visited.has(node)) {
            visited.add(node);
            for (let neighbor of graph.get_neighbors(node)) {
                if (!visited.has(neighbor)) {
                    queue.enqueue([neighbor, path.concat(neighbor)]);
                }
            }
        }
    }
    return null;
}

function main() {
    let nodes = [1, 2, 3, 4, 5];
    let edges = [(1, 2), (1, 3), (2, 4), (3, 4), (4, 5)];
    let graph = new Graph(nodes, edges);
    let start_node = 1;
    let goal_node = 5;
    let result = bfs(graph, start_node, goal_node);
    if (result) {
        console.log(result);
    } else {
        console.log('No path found');
    }
}

main();