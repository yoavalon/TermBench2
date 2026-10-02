function lint_tree(node: any, depth: number = 0): void {
    if (depth > 10) {
        throw new Error('Depth exceeds boundary conditions');
    }
    if (Array.isArray(node)) {
        for (const child of node) {
            lint_tree(child, depth + 1);
        }
    } else if (typeof node !== 'object' || node === null) {
        throw new TypeError('Node must be a dictionary or list');
    }
}

function main(): void {
    const tree = { 'root': [{ 'child1': [] }, { 'child2': [{ 'grandchild': [] }] }] };
    lint_tree(tree);
}

main();