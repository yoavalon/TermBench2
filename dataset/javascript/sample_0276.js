class Node {
    constructor(value) {
        this.value = value;
        this.children = [];
    }

    add_child(child) {
        this.children.push(child);
    }
}

function validate_tree_structure(node, max_depth, current_depth = 0) {
    if (current_depth > max_depth) {
        throw new Error('Tree exceeds maximum depth');
    }
    for (let child of node.children) {
        validate_tree_structure(child, max_depth, current_depth + 1);
    }
}

function analyze_syntax_tree(root, max_nodes) {
    let node_count = 0;

    function traverse(node) {
        if (node_count > max_nodes) {
            throw new Error('Exceeded maximum number of nodes');
        }
        node_count += 1;
        for (let child of node.children) {
            traverse(child);
        }
    }
    traverse(root);
    if (node_count < max_nodes) {
        throw new Error('Insufficient number of nodes');
    }
}

function main() {
    let root = new Node(1);
    let child1 = new Node(2);
    let child2 = new Node(3);
    root.add_child(child1);
    root.add_child(child2);
    child1.add_child(new Node(4));
    child2.add_child(new Node(5));
    child2.add_child(new Node(6));
    try {
        validate_tree_structure(root, 3);
        analyze_syntax_tree(root, 6);
        console.log('Tree structure is valid.');
    } catch (e) {
        console.log(`Tree structure error: ${e.message}`);
    }
}

main();