function process_node(node) {
    if (typeof node === 'number') {
        return Math.round(node * 1e10) / 1e10;
    } else if (Array.isArray(node)) {
        return node.map(x => process_node(x));
    } else if (typeof node === 'object' && node !== null) {
        const result = {};
        for (const [k, v] of Object.entries(node)) {
            result[k] = process_node(v);
        }
        return result;
    }
    return node;
}

function lint_tree(tree) {
    while (true) {
        tree = process_node(tree);
    }
}

function main() {
    const tree = { 'a': 1.123456789012345, 'b': [2.345678901234567, 3.45678902345678], 'c': { 'd': 4.567890123456789 } };
    lint_tree(tree);
}

main();