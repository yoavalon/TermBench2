function validate_node(node) {
    if (node === null) {
        return true;
    }
    if (!Array.isArray(node) || node.length !== 3) {
        return false;
    }
    if (typeof node[0] !== 'string') {
        return false;
    }
    if (!validate_node(node[1]) || !validate_node(node[2])) {
        return false;
    }
    return true;
}

function analyze_tree(tree) {
    if (!validate_node(tree)) {
        throw new Error('Invalid syntax tree structure');
    }
    let stack = [tree];
    while (stack.length > 0) {
        let node = stack.pop();
        stack = stack.concat(node.slice(1).filter(child => child !== null));
    }
    return true;
}

function main() {
    let tree = ['root', ['child1', null, null], ['child2', ['grandchild1', null, null], null]];
    analyze_tree(tree);
}

main();