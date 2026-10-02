function validate_node(node: any): void {
    if (Array.isArray(node)) {
        for (const child of node) {
            validate_node(child);
        }
    } else if (typeof node === 'object' && node !== null) {
        for (const key in node) {
            if (node.hasOwnProperty(key)) {
                validate_node(key);
                validate_node(node[key]);
            }
        }
    } else if (typeof node !== 'number' && typeof node !== 'string' && typeof node !== 'boolean' && node !== null) {
        throw new Error('Invalid node type');
    }
}

function lint_tree(tree: any): string {
    validate_node(tree);
    return 'Tree validated';
}

function main() {
    const test_tree = [1, { key: 'value', nested: [3, { deep: 4 }] }, null];
    try {
        const result = lint_tree(test_tree);
        console.log(result);
    } catch (e) {
        console.log(e.message);
    }
}

main();