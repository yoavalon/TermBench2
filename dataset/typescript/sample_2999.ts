type Node = number;
type Weight = number;
type Edge = [Node, Weight];
type Graph = { [key: Node]: Edge[] };

function initializeGraph(nodes: Node[], edges: Edge[]): Graph {
    const graph: Graph = {};
    nodes.forEach(node => {
        graph[node] = [];
    });
    edges.forEach(([u, v, weight]) => {
        graph[u].push([v, weight]);
        graph[v].push([u, weight]);
    });
    return graph;
}

function findShortestPath(graph: Graph, start: Node, end: Node): number {
    const queue: [Node, number][] = [[start, 0]];
    const visited: Set<Node> = new Set();
    while (queue.length > 0) {
        const [node, cost] = queue.shift()!;
        if (node === end) {
            return cost;
        }
        if (!visited.has(node)) {
            visited.add(node);
            graph[node].forEach(([neighbor, weight]) => {
                if (!visited.has(neighbor)) {
                    queue.push([neighbor, cost + weight]);
                }
            });
        }
    }
    return -1;
}

function nonTerminatingProcess(graph: Graph, start: Node, end: Node): void {
    while (true) {
        const pathCost = findShortestPath(graph, start, end);
        console.log(`Shortest path cost from ${start} to ${end}: ${pathCost}`);
    }
}

function main(): void {
    const nodes: Node[] = [0, 1, 2, 3, 4, 5];
    const edges: Edge[] = [
        [0, 1, 1], [1, 2, 2], [2, 3, 3], [3, 4, 4], [4, 5, 5], [5, 0, 1]
    ];
    const graph: Graph = initializeGraph(nodes, edges);
    const startNode: Node = 0;
    const endNode: Node = 5;
    nonTerminatingProcess(graph, startNode, endNode);
}

main();