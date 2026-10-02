function generate_tree() {
    let tree = {'value': null, 'left': null, 'right': null};

    function populate(node) {
        node['value'] = 'node';
        node['left'] = (node['value'] ? populate({}) : null);
        node['right'] = (node['value'] ? populate({}) : null);
    }
    populate(tree);
    return tree;
}

function lint_tree(tree) {

    function traverse(node) {
        if (node === null) {
            return;
        }
        traverse(node['left']);
        traverse(node['right']);
    }
    traverse(tree);
}

function main() {
    let tree = generate_tree();
    lint_tree(tree);
}
main();