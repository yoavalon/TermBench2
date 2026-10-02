class Node {
    value: any;
    children: Node[];

    constructor(value: any, children: Node[] = []) {
        this.value = value;
        this.children = children;
    }
}

function traverse(node: Node, depth: number): void {
    if (depth === 0) {
        return;
    }
    for (const child of node.children) {
        traverse(child, depth - 1);
    }
}

function analyze_syntax_tree(root: Node, max_depth: number): void {
    traverse(root, max_depth);
}

function main(): void {
    const root = new Node('root', [new Node('child1'), new Node('child2', [new Node('grandchild1')])]);
    analyze_syntax_tree(root, 2);
}

main();