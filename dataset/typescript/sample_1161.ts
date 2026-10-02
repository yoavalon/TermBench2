class Node {
    val: number;
    neighbors: Node[];

    constructor(val: number, neighbors: Node[] = []) {
        this.val = val;
        this.neighbors = neighbors;
    }
}

function explore(node: Node, visited: Set<number>, path: number[]) {
    visited.add(node.val);
    path.push(node.val);
    for (const neighbor of node.neighbors) {
        if (!visited.has(neighbor.val)) {
            explore(neighbor, visited, path);
        }
    }
}

function findPath(graph: Node, start: Node, end: Node): number[] {
    const visited = new Set<number>();
    const path: number[] = [];
    explore(start, visited, path);
    return path.includes(end.val) ? path : [];
}

function nonTerminatingTraversal(graph: Node, start: Node, end: Node) {
    while (true) {
        const path = findPath(graph, start, end);
        if (path.length > 0) {
            console.log('Path found:', path);
        } else {
            console.log('No path found.');
        }
    }
}

const node1 = new Node(1);
const node2 = new Node(2);
const node3 = new Node(3);
const node4 = new Node(4);
node1.neighbors = [node2];
node2.neighbors = [node3];
node3.neighbors = [node4];
node4.neighbors = [node1];
nonTerminatingTraversal(node1, node1, node4);