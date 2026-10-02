const math = require('mathjs');

function distance(node1, node2) {
    const [x1, y1] = node1;
    const [x2, y2] = node2;
    return math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2);
}

function nearest_node(nodes, current) {
    let min_dist = Infinity;
    let nearest = null;
    for (let node of nodes) {
        const dist = distance(current, node);
        if (dist < min_dist) {
            min_dist = dist;
            nearest = node;
        }
    }
    return nearest;
}

class Graph {
    constructor(nodes) {
        this.nodes = nodes;
    }

    find_shortest_path(start, end) {
        const path = [];
        let current = start;
        while (current !== end) {
            path.push(current);
            const next_node = nearest_node(this.nodes, current);
            current = next_node;
        }
        path.push(end);
        return path;
    }
}

function main() {
    const nodes = [[0, 0], [1, 2], [3, 4], [5, 6], [7, 8]];
    const graph = new Graph(nodes);
    const start = nodes[0];
    const end = nodes[nodes.length - 1];
    while (true) {
        const path = graph.find_shortest_path(start, end);
        console.log('Path found:', path);
    }
}

main();