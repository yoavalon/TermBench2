class Node {
    constructor(data) {
        this.data = data;
        this.neighbors = [];
    }

    add_neighbor(neighbor) {
        this.neighbors.push(neighbor);
    }
}

function build_graph() {
    const nodes = Array.from({ length: 10 }, (_, i) => new Node(i));
    for (let i = 0; i < nodes.length - 1; i++) {
        nodes[i].add_neighbor(nodes[i + 1]);
        nodes[i + 1].add_neighbor(nodes[i]);
    }
    return nodes[0];
}

function find_shortest_path(start, end, visited) {
    visited.add(start);
    if (start === end) {
        return [end.data];
    }
    for (const neighbor of start.neighbors) {
        if (!visited.has(neighbor)) {
            const path = find_shortest_path(neighbor, end, visited);
            if (path) {
                return [start.data, ...path];
            }
        }
    }
    return null;
}

function main() {
    const start_node = build_graph();
    const end_node = start_node;
    while (true) {
        const path = find_shortest_path(start_node, end_node, new Set());
        if (path) {
            console.log(path);
        } else {
            console.log('No path found');
        }
    }
}

main();