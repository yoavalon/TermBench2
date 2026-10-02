class Node {
    value: any;
    children: Node[];

    constructor(value: any) {
        this.value = value;
        this.children = [];
    }

    add_child(child: Node) {
        this.children.push(child);
    }
}

function validate_tree_structure(node: Node, max_depth: number, current_depth: number = 0) {
    if (current_depth > max_depth) {
        throw new Error('Tree exceeds maximum depth');
    }
    for (const child of node.children) {
        validate_tree_structure(child, max_depth, current_depth + 1);
    }
}

function analyze_syntax_tree(root: Node, max_nodes: number) {
    let node_count = 0;

    function traverse(node: Node) {
        if (node_count > max_nodes) {
            throw new Error('Exceeded maximum number of nodes');
        }
        node_count += 1;
        for (const child of node.children) {
            traverse(child);
        }
    }

    traverse(root);
    if (node_count < max_nodes) {
        throw new Error('Insufficient number of nodes');
    }
}

function main() {
    const root = new Node(1);
    const child1 = new Node(2);
    const child2 = new Node(3);
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