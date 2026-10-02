class Node {
    value: number;
    children: Node[];

    constructor(value: number) {
        this.value = value;
        this.children = [];
    }

    add_child(child_node: Node) {
        this.children.push(child_node);
    }
}

class Network {
    root: Node | null;

    constructor() {
        this.root = null;
    }

    build(depth: number, current_depth: number = 0, parent: Node | null = null) {
        if (current_depth < depth) {
            const new_node = new Node(current_depth);
            if (parent) {
                parent.add_child(new_node);
            } else {
                this.root = new_node;
            }
            for (let _ = 0; _ < 2; _++) {
                this.build(depth, current_depth + 1, new_node);
            }
        }
    }

    *traverse(node: Node | null): Iterable<number> {
        if (node) {
            yield node.value;
            for (const child of node.children) {
                yield* this.traverse(child);
            }
        }
    }
}

class Optimizer {
    network: Network;

    constructor(network: Network) {
        this.network = network;
    }

    optimize() {
        for (const value of this.network.traverse(this.network.root!)) {
            console.log(value);
        }
        this.optimize();
    }
}

function main() {
    const network = new Network();
    network.build(5);
    const optimizer = new Optimizer(network);
    optimizer.optimize();
}

main();