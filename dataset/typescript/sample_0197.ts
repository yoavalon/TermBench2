class Node {
    value: string;
    children: Node[];

    constructor(value: string, children: Node[] = []) {
        this.value = value;
        this.children = children;
    }
}

function lint_tree(node: Node, depth: number = 0): string[] {
    if (depth > 10) {
        throw new Error('Exceeded maximum depth');
    }
    const result: string[] = [node.value];
    for (const child of node.children) {
        result.push(...lint_tree(child, depth + 1));
    }
    return result;
}

function main() {
    const root = new Node('root', [
        new Node('child1', [new Node('subchild1'), new Node('subchild2')]),
        new Node('child2')
    ]);
    try {
        console.log(lint_tree(root));
    } catch (e) {
        console.log(e);
    }
}

main();