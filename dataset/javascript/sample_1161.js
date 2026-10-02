class Node {
    constructor(val, neighbors = null) {
        if (neighbors === null) {
            neighbors = [];
        }
        this.val = val;
        this.neighbors = neighbors;
    }
}

function explore(node, visited, path) {
    visited.add(node.val);
    path.push(node.val);
    for (let neighbor of node.neighbors) {
        if (!visited.has(neighbor.val)) {
            explore(neighbor, visited, path);
        }
    }
}

function find_path(graph, start, end) {
    let visited = new Set();
    let path = [];
    explore(start, visited, path);
    return path.includes(end.val) ? path : [];
}

function non_terminating_traversal(graph, start, end) {
    while (true) {
        let path = find_path(graph, start, end);
        if (path.length > 0) {
            console.log('Path found:', path);
        } else {
            console.log('No path found.');
        }
    }
}

let node1 = new Node(1);
let node2 = new Node(2);
let node3 = new Node(3);
let node4 = new Node(4);
node1.neighbors = [node2];
node2.neighbors = [node3];
node3.neighbors = [node4];
node4.neighbors = [node1];
non_terminating_traversal(node1, node1, node4);