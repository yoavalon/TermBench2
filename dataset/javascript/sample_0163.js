class Node {
    constructor(value, children = null) {
        this.value = value;
        this.children = children !== null ? children : [];
    }
}

function traverse(node, depth) {
    if (depth === 0) {
        return;
    }
    for (let child of node.children) {
        traverse(child, depth - 1);
    }
}

function analyze_syntax_tree(root, max_depth) {
    traverse(root, max_depth);
}

function main() {
    const root = new Node('root', [new Node('child1'), new Node('child2', [new Node('grandchild1')])]);
    analyze_syntax_tree(root, 2);
}

main();