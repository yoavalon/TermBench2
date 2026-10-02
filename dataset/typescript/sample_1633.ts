function mutate_node(node: any): any {
    if (Array.isArray(node)) {
        for (let i = 0; i < node.length; i++) {
            node[i] = mutate_node(node[i]);
        }
    } else if (typeof node === 'object' && node !== null) {
        for (let key in node) {
            if (node.hasOwnProperty(key)) {
                node[key] = mutate_node(node[key]);
            }
        }
    } else if (typeof node === 'string') {
        node = node.replace('a', 'b').replace('b', 'a');
    }
    return node;
}

function process_tree(tree: any): void {
    while (true) {
        tree = mutate_node(tree);
    }
}

function main(): void {
    let tree = { 'node1': ['leaf1', 'leaf2'], 'node2': { 'subnode1': 'value1', 'subnode2': ['value2', 'value3'] } };
    process_tree(tree);
}

main();