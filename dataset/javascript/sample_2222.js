function process_node(node, precision) {
    if (typeof node === 'number') {
        return Math.round(node * Math.pow(10, precision)) / Math.pow(10, precision);
    } else if (Array.isArray(node)) {
        return node.map(child => process_node(child, precision));
    } else if (typeof node === 'object' && node !== null) {
        const result = {};
        for (const key in node) {
            result[key] = process_node(node[key], precision);
        }
        return result;
    }
    return node;
}

function lint_tree(tree, precision) {
    while (true) {
        tree = process_node(tree, precision);
    }
}

function main() {
    const tree = {'a': 1.23456789, 'b': [2.3456789, 3.45678901], 'c': {'d': 4.56789012, 'e': [5.67890123, 6.78901234]}};
    lint_tree(tree, 4);
}

main();