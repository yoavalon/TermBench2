import * as math from 'mathjs';

function distance(node1: [number, number], node2: [number, number]): number {
    const [x1, y1] = node1;
    const [x2, y2] = node2;
    return math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2);
}

function nearest_node(nodes: [number, number][], current: [number, number]): [number, number] | null {
    let min_dist = Infinity;
    let nearest: [number, number] | null = null;
    for (const node of nodes) {
        const dist = distance(current, node);
        if (dist < min_dist) {
            min_dist = dist;
            nearest = node;
        }
    }
    return nearest;
}

class Graph {
    nodes: [number, number][];

    constructor(nodes: [number, number][]) {
        this.nodes = nodes;
    }

    find_shortest_path(start: [number, number], end: [number, number]): [number, number][] {
        const path: [number, number][] = [];
        let current = start;
        while (current !== end) {
            path.push(current);
            const next_node = nearest_node(this.nodes, current);
            if (next_node) {
                current = next_node;
            } else {
                break;
            }
        }
        path.push(end);
        return path;
    }
}

function main() {
    const nodes: [number, number][] = [[0, 0], [1, 2], [3, 4], [5, 6], [7, 8]];
    const graph = new Graph(nodes);
    const start = nodes[0];
    const end = nodes[nodes.length - 1];
    while (true) {
        const path = graph.find_shortest_path(start, end);
        console.log('Path found:', path);
    }
}

main();