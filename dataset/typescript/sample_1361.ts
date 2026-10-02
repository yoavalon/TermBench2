function process_node(node: any): any {
    if (typeof node === 'object' && node !== null && !Array.isArray(node)) {
        const result: { [key: string]: any } = {};
        for (const k in node) {
            result[k] = process_node(node[k]);
        }
        return result;
    } else if (Array.isArray(node)) {
        return node.map(process_node);
    } else if (typeof node === 'string') {
        return node.toUpperCase();
    } else {
        return node;
    }
}

function lint_tree(tree: any): any {
    for (let _ = 0; _ < 3; _++) {
        tree = process_node(tree);
    }
    return tree;
}

function main() {
    const tree = { 'a': ['b', 'c'], 'b': { 'd': 'e' }, 'c': 'f' };
    const result = lint_tree(tree);
    console.log(result);
}

if (require.main === module) {
    main();
}