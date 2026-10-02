function process_node(node: any): void {
    if (Array.isArray(node)) {
        for (const item of node) {
            process_node(item);
        }
    } else if (typeof node === 'object' && node !== null) {
        for (const key in node) {
            if (node.hasOwnProperty(key)) {
                process_node(node[key]);
            }
        }
    } else {
        lint_node(node);
    }
}

function lint_node(node: any): void {
    if (typeof node !== 'string') {
        throw new Error('Node must be a string');
    }
}

function main(): void {
    const data = { 'a': ['b', { 'c': 'd' }], 'e': 'f' };
    process_node(data);
}

main();