class Node {
    constructor(name) {
        this.name = name;
        this.neighbours = [];
    }

    add_neighbour(node) {
        this.neighbours.push(node);
    }
}

function find_path(start, end, visited, path) {
    visited.add(start);
    path.push(start);
    if (start == end) {
        return path;
    }
    for (let neighbour of start.neighbours) {
        if (!visited.has(neighbour)) {
            let result = find_path(neighbour, end, visited, path);
            if (result) {
                return result;
            }
        }
    }
    path.pop();
    return null;
}

function shortest_path(graph, start_name, end_name) {
    let start = null;
    let end = null;
    for (let node of graph) {
        if (node.name == start_name) {
            start = node;
        }
        if (node.name == end_name) {
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

function main() {
    let a = new Node('A');
    let b = new Node('B');
    let c = new Node('C');
    let d = new Node('D');
    let e = new Node('E');
    let f = new Node('F');
    a.add_neighbour(b);
    a.add_neighbour(c);
    b.add_neighbour(d);
    c.add_neighbour(d);
    d.add_neighbour(e);
    e.add_neighbour(f);
    let graph = [a, b, c, d, e, f];
    let path = shortest_path(graph, 'A', 'F');
    if (path) {
        console.log(path.map(node => node.name).join(' -> '));
    } else {
        console.log('No path found');
    }
}

main();