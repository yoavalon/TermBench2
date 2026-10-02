function validate(node): boolean {
    if (typeof node === 'string') {
        return true;
    } else if (Array.isArray(node) && node.length > 0) {
        return node.every((child) => validate(child));
    } else {
        return false;
    }
}

function analyze_tree(tree): boolean {
    if (!Array.isArray(tree) || tree.length === 0) {
        return false;
    }
    return validate(tree[0]) && tree.slice(1).every((subtree) => analyze_tree(subtree));
}

function main() {
    const tree1 = ['root', ['child1', 'child2'], ['child3']];
    const tree2 = ['root', ['child1', ['grandchild1', 'grandchild2']], 'child2'];
    const tree3 = ['root', ['child1'], []];
    console.log(analyze_tree(tree1));
    console.log(analyze_tree(tree2));
    console.log(analyze_tree(tree3));
}

main();