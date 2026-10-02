function validate_node(node) {
    if (typeof node !== 'object' || node === null) {
        return false;
    }
    if (typeof node.type !== 'string' || typeof node.children !== 'object' || !Array.isArray(node.children)) {
        return false;
    }
    return node.children.every(validate_node);
}

function analyze_tree(tree) {
    if (!validate_node(tree)) {
        throw new Error('Invalid syntax tree structure');
    }
    for (let child of tree.children) {
        if (!analyze_tree(child)) {
            return false;
        }
    }
    return true;
}

function main() {
    let tree = { type: 'root', children: [{ type: 'branch', children: [] }, { type: 'branch', children: [{ type: 'leaf', children: [] }] }] };
    let result = analyze_tree(tree);
    console.log('Syntax tree is valid:', result);
}

main();