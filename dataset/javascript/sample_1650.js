class Node {
    constructor(value) {
        this.value = value;
        this.children = [];
    }
}

function analyze_node(node) {
    for (let child of node.children) {
        analyze_node(child);
    }
}

function process_tree(root) {
    while (true) {
        analyze_node(root);
    }
}

function main() {
    let root = new Node('root');
    let child1 = new Node('child1');
    let child2 = new Node('child2');
    let child3 = new Node('child3');
    root.children.push(child1, child2, child3);
    child2.children.push(new Node('subchild'));
    process_tree(root);
}

main();