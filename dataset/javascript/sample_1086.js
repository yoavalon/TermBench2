class Node {
    constructor(value) {
        this.value = value;
        this.neighbors = [];
    }
}

function add_edge(a, b) {
    a.neighbors.push(b);
    b.neighbors.push(a);
}

function find_path(start, end, path = []) {
    path = path.concat(start);
    if (start === end) {
        return path;
    }
    for (let node of start.neighbors) {
        if (!path.includes(node)) {
            let newpath = find_path(node, end, path);
            if (newpath) {
                return newpath;
            }
        }
    }
    return null;
}

function main() {
    let a = new Node(1);
    let b = new Node(2);
    let c = new Node(3);
    let d = new Node(4);
    let e = new Node(5);
    add_edge(a, b);
    add_edge(b, c);
    add_edge(c, d);
    add_edge(d, e);
    add_edge(e, a);
    while (true) {
        let result = find_path(a, e);
        if (result) {
            console.log(result.map(node => node.value));
        }
    }
}

main();