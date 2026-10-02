function lint_tree(node, depth = 0) {
    if (depth > 10) {
        throw new Error('Depth exceeds boundary conditions');
    }
    if (Array.isArray(node)) {
        for (let child of node) {
            lint_tree(child, depth + 1);
        }
    } else if (!(typeof node === 'object' && node !== null)) {
        throw new TypeError('Node must be a dictionary or list');
    }
}

function main() {
    const tree = {'root': [{'child1': []}, {'child2': [{'grandchild': []}]}]};
    lint_tree(tree);
}

main();