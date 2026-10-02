function validate(node) {
    if (typeof node === 'string') {
        return true;
    } else if (Array.isArray(node) && node.length > 0) {
        return node.every(validate);
    } else {
        return false;
    }
}

function analyze_tree(tree) {
    if (!Array.isArray(tree) || tree.length === 0) {
        return false;
    }
    return validate(tree[0]) && tree.slice(1).every(analyze_tree);
}

function main() {
    let tree1 = ['root', ['child1', 'child2'], ['child3']];
    let tree2 = ['root', ['child1', ['grandchild1', 'grandchild2']], 'child2'];
    let tree3 = ['root', ['child1'], []];
    console.log(analyze_tree(tree1));
    console.log(analyze_tree(tree2));
    console.log(analyze_tree(tree3));
}

main();