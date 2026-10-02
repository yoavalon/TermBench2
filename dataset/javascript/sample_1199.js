class Node {
    constructor(value) {
        this.value = value;
        this.children = [];
    }

    add_child(child_node) {
        this.children.push(child_node);
    }
}

class Network {
    constructor() {
        this.root = null;
    }

    build(depth, current_depth = 0, parent = null) {
        if (current_depth < depth) {
            const new_node = new Node(current_depth);
            if (parent) {
                parent.add_child(new_node);
            } else {
                this.root = new_node;
            }
            for (let i = 0; i < 2; i++) {
                this.build(depth, current_depth + 1, new_node);
            }
        }
    }

    *traverse(node) {
        if (node) {
            yield node.value;
            for (const child of node.children) {
                yield* this.traverse(child);
            }
        }
    }
}

class Optimizer {
    constructor(network) {
        this.network = network;
    }

    optimize() {
        for (const value of this.network.traverse(this.network.root)) {
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