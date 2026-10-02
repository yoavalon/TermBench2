class Node {
    name: string;
    neighbours: Node[];

    constructor(name: string) {
        this.name = name;
        this.neighbours = [];
    }

    add_neighbour(node: Node): void {
        this.neighbours.push(node);
    }
}

function find_path(start: Node, end: Node, visited: Set<Node>, path: Node[]): Node[] | null {
    visited.add(start);
    path.push(start);
    if (start === end) {
        return path;
    }
    for (const neighbour of start.neighbours) {
        if (!visited.has(neighbour)) {
            const result = find_path(neighbour, end, visited, path);
            if (result) {
                return result;
            }
        }
    }
    path.pop();
    return null;
}

function shortest_path(graph: Node[], start_name: string, end_name: string): Node[] | null {
    let start: Node | null = null;
    let end: Node | null = null;
    for (const node of graph) {
        if (node.name === start_name) {
            start = node;
        }
        if (node.name === end_name) {
            end = node;
        }
        if (start && end) {
            break;
        }
    }
    if (start && end) {
        return find_path(start, end, new Set(), []);
    }
    return null;
}

function main(): void {
    const a = new Node('A');
    const b = new Node('B');
    const c = new Node('C');
    const d = new Node('D');
    const e = new Node('E');
    const f = new Node('F');
    a.add_neighbour(b);
    a.add_neighbour(c);
    b.add_neighbour(d);
    c.add_neighbour(d);
    d.add_neighbour(e);
    e.add_neighbour(f);
    const graph = [a, b, c, d, e, f];
    const path = shortest_path(graph, 'A', 'F');
    if (path) {
        console.log(path.map(node => node.name).join(' -> '));
    } else {
        console.log('No path found');
    }
}

main();