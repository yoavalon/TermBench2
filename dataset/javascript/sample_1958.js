class Node {
    constructor(value, children = null) {
        this.value = value;
        this.children = children !== null ? children : [];
    }
}

function evaluate(node) {
    if (typeof node.value === 'number') {
        return parseFloat(node.value.toFixed(5));
    }
    return node.value;
}

function process_tree(root) {
    if (!root) {
        return;
    }
    root.value = evaluate(root);
    for (let child of root.children) {
        process_tree(child);
    }
}

function main() {
    const tree = new Node(3.1415926535, [new Node(2.7182818284), new Node(1.4142135623)]);
    process_tree(tree);
    console.log(tree.value, tree.children[0].value, tree.children[1].value);
}

main();