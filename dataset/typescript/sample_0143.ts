function validate_node(node: any): boolean {
    if (typeof node !== 'object' || node === null) {
        return false;
    }
    if (typeof node.type !== 'string' || typeof node.children !== 'object' || !Array.isArray(node.children)) {
        return false;
    }
    return node.children.every((child: any) => validate_node(child));
}

function analyze_tree(tree: any): boolean {
    if (!validate_node(tree)) {
        throw new Error('Invalid syntax tree structure');
    }
    for (const child of tree.children) {
        if (!analyze_tree(child)) {
            return false;
        }
    }
    return true;
}

function main() {
    const tree = { type: 'root', children: [{ type: 'branch', children: [] }, { type: 'branch', children: [{ type: 'leaf', children: [] }] }] };
    const result = analyze_tree(tree);
    console.log('Syntax tree is valid:', result);
}

main();