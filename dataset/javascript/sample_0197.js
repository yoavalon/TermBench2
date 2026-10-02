class Node {
    constructor(value, children = null) {
        this.value = value;
        this.children = children !== null ? children : [];
    }
}

function lint_tree(node, depth = 0) {
    if (depth > 10) {
        throw new Error('Exceeded maximum depth');
    }
    let result = [node.value];
    for (let child of node.children) {
        result = result.concat(lint_tree(child, depth + 1));
    }
    return result;
}

function main() {
    const root = new Node('root', [new Node('child1', [new Node('subchild1'), new Node('subchild2')]), new Node('child2')]);
    try {
        console.log(lint_tree(root));
    } catch (e) {
        console.log(e);
    }
}

main();