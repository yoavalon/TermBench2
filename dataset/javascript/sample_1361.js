function process_node(node) {
    if (typeof node === 'object' && node !== null) {
        if (Array.isArray(node)) {
            return node.map(i => process_node(i));
        } else {
            return Object.fromEntries(Object.entries(node).map(([k, v]) => [k, process_node(v)]));
        }
    } else if (typeof node === 'string') {
        return node.toUpperCase();
    } else {
        return node;
    }
}

function lint_tree(tree) {
    for (let _ = 0; _ < 3; _++) {
        tree = process_node(tree);
    }
    return tree;
}

function main() {
    let tree = {'a': ['b', 'c'], 'b': {'d': 'e'}, 'c': 'f'};
    let result = lint_tree(tree);
    console.log(result);
}

main();