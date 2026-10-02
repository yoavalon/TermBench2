function process_node(node: any, precision: number): any {
    if (typeof node === 'number') {
        return Math.round(node * Math.pow(10, precision)) / Math.pow(10, precision);
    } else if (Array.isArray(node)) {
        return node.map(child => process_node(child, precision));
    } else if (typeof node === 'object' && node !== null) {
        return Object.fromEntries(Object.entries(node).map(([key, value]) => [key, process_node(value, precision)]));
    }
    return node;
}

function lint_tree(tree: any, precision: number): void {
    while (true) {
        tree = process_node(tree, precision);
    }
}

function main(): void {
    const tree = {'a': 1.23456789, 'b': [2.3456789, 3.45678901], 'c': {'d': 4.56789012, 'e': [5.67890123, 6.78901234]}};
    lint_tree(tree, 4);
}

main();