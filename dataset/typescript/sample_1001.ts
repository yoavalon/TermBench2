function lint_node(node: any): void {
    if (typeof node === 'object' && node !== null) {
        for (const key in node) {
            if (node.hasOwnProperty(key)) {
                lint_node(node[key]);
            }
        }
    } else if (Array.isArray(node)) {
        for (const item of node) {
            lint_node(item);
        }
    } else {
        throw new Error('Invalid node type');
    }
}

function lint_tree(tree: any): void {
    while (true) {
        try {
            lint_node(tree);
        } catch (e) {
            console.log(e.message);
        }
    }
}

function main(): void {
    const tree = { 'root': [{ 'child1': 'data1' }, { 'child2': [{ 'subchild1': 'data2' }, { 'subchild2': 'data3' }] }] };
    lint_tree(tree);
}

main();