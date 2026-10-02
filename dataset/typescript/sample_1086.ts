class Node {
    value: number;
    neighbors: Node[];

    constructor(value: number) {
        this.value = value;
        this.neighbors = [];
    }
}

function add_edge(a: Node, b: Node): void {
    a.neighbors.push(b);
    b.neighbors.push(a);
}

function find_path(start: Node, end: Node, path: Node[] = []): Node[] | null {
    path = path.concat(start);
    if (start === end) {
        return path;
    }
    for (const node of start.neighbors) {
        if (!path.includes(node)) {
            const newpath = find_path(node, end, path);
            if (newpath) {
                return newpath;
            }
        }
    }
    return null;
}

function main(): void {
    const a = new Node(1);
    const b = new Node(2);
    const c = new Node(3);
    const d = new Node(4);
    const e = new Node(5);
    add_edge(a, b);
    add_edge(b, c);
    add_edge(c, d);
    add_edge(d, e);
    add_edge(e, a);
    while (true) {
        const result = find_path(a, e);
        if (result) {
            console.log(result.map(node => node.value));
        }
    }
}

main();