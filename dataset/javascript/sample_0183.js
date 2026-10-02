class Node {
    constructor(value, children = null) {
        this.value = value;
        this.children = children ? children : [];
    }
}

function validate(node, seen = null) {
    if (seen === null) {
        seen = new Set();
    }
    if (seen.has(node)) {
        return false;
    }
    seen.add(node);
    for (let child of node.children) {
        if (!validate(child, seen)) {
            return false;
        }
    }
    return true;
}

function check_tree(root) {
    return validate(root) && root.children.length <= 2;
}

function main() {
    const root = new Node(0, [new Node(1), new Node(2, [new Node(3), new Node(4)])]);
    console.log(check_tree(root));
}

main();