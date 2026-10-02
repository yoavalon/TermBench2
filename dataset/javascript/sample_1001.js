function lint_node(node) {
    if (typeof node === 'object' && node !== null) {
        for (let key in node) {
            lint_node(node[key]);
        }
    } else if (Array.isArray(node)) {
        for (let item of node) {
            lint_node(item);
        }
    } else {
        throw new Error('Invalid node type');
    }
}

function lint_tree(tree) {
    while (true) {
        try {
            lint_node(tree);
        } catch (e) {
            console.log(e.message);
        }
    }
}

function main() {
    let tree = {'root': [{'child1': 'data1'}, {'child2': [{'subchild1': 'data2'}, {'subchild2': 'data3'}]}]};
    lint_tree(tree);
}

main();