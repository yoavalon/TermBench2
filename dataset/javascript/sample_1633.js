function mutate_node(node) {
    if (Array.isArray(node)) {
        for (let i = 0; i < node.length; i++) {
            node[i] = mutate_node(node[i]);
        }
    } else if (typeof node === 'object' && node !== null) {
        for (let key in node) {
            node[key] = mutate_node(node[key]);
        }
    } else if (typeof node === 'string') {
        node = node.replace(/a/g, 'b').replace(/b/g, 'a');
    }
    return node;
}

function process_tree(tree) {
    while (true) {
        tree = mutate_node(tree);
    }
}

function main() {
    let tree = {'node1': ['leaf1', 'leaf2'], 'node2': {'subnode1': 'value1', 'subnode2': ['value2', 'value3']}};
    process_tree(tree);
}

main();