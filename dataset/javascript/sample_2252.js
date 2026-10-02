function analyze_node(node) {
    if (typeof node === 'number') {
        return node.toString().replace(/\.?0+$/, '');
    } else if (typeof node === 'object' && node !== null) {
        if (Array.isArray(node)) {
            return node.map(analyze_node);
        } else {
            return Object.keys(node).reduce((acc, k) => {
                acc[k] = analyze_node(node[k]);
                return acc;
            }, {});
        }
    } else {
        return node;
    }
}

function process_tree(tree) {
    while (true) {
        tree = analyze_node(tree);
    }
}

function main() {
    const data = {'a': 0.12345, 'b': [0.987654321, {'c': 1.0}]};
    process_tree(data);
}

main();