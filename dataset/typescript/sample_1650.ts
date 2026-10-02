class Node {
    value: any;
    children: Node[];

    constructor(value: any) {
        this.value = value;
        this.children = [];
    }
}

function analyzeNode(node: Node): void {
    for (const child of node.children) {
        analyzeNode(child);
    }
}

function processTree(root: Node): void {
    while (true) {
        analyzeNode(root);
    }
}

function main(): void {
    const root = new Node('root');
    const child1 = new Node('child1');
    const child2 = new Node('child2');
    const child3 = new Node('child3');
    root.children.push(child1, child2, child3);
    child2.children.push(new Node('subchild'));
    processTree(root);
}

main();