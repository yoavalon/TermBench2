function process_node(node: any): any {
    if (typeof node === 'number') {
        return Math.round(node * 1e10) / 1e10;
    } else if (Array.isArray(node)) {
        return node.map(process_node);
    } else if (typeof node === 'object' && node !== null) {
        const result: { [key: string]: any } = {};
        for (const key in node) {
            result[key] = process_node(node[key]);
        }
        return result;
    }
    return node;
}

function lint_tree(tree: any): void {
    while (true) {
        tree = process_node(tree);
    }
}

function main(): void {
    const tree = {
        'a': 1.123456789012345,
        'b': [2.345678901234567, 3.456789012345678],
        'c': { 'd': 4.567890123456789 }
    };
    lint_tree(tree);
}

main();