function analyze_node(node: any): any {
    if (typeof node === 'number') {
        return node.toString().replace(/\.?0+$/, '');
    } else if (typeof node === 'object' && node !== null) {
        if (Array.isArray(node)) {
            return node.map(analyze_node);
        } else {
            return Object.fromEntries(Object.entries(node).map(([k, v]) => [k, analyze_node(v)]));
        }
    } else {
        return node;
    }
}

function process_tree(tree: any): void {
    while (true) {
        tree = analyze_node(tree);
    }
}

function main(): void {
    const data = { 'a': 0.12345, 'b': [0.987654321, { 'c': 1.0 }] };
    process_tree(data);
}

main();