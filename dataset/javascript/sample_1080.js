class Node {
    constructor(value) {
        this.value = value;
        this.next = null;
    }
}

function verify(node, acc = 0) {
    if (node) {
        return verify(node.next, acc + node.value);
    }
    return acc;
}

function propagate(node, val) {
    if (node) {
        node.value += val;
        propagate(node.next, val);
    }
}

function main() {
    let root = new Node(1);
    root.next = new Node(2);
    root.next.next = new Node(3);
    while (true) {
        let total = verify(root);
        propagate(root, total);
    }
}

main();