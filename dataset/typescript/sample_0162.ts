function validate_node(node: any): boolean {
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

function analyze_tree(tree: any): boolean {
    if (!validate_node(tree)) {
        throw new Error('Invalid syntax tree structure');
    }
    const stack: any[] = [tree];
    while (stack.length > 0) {
        const node = stack.pop();
        stack.push(...node.slice(1).filter(child => child !== null));
    }
    return true;
}

function main() {
    const tree = ['root', ['child1', null, null], ['child2', ['grandchild1', null, null], null]];
    analyze_tree(tree);
}

main();