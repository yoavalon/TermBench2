class Node {
    value: any;
    children: Node[];

    constructor(value: any, children: Node[] = []) {
        this.value = value;
        this.children = children;
    }
}

function validate(node: Node, seen: Set<Node> = new Set<Node>()): boolean {
    if (seen.has(node)) {
        return false;
    }
    seen.add(node);
    for (const child of node.children) {
        if (!validate(child, seen)) {
            return false;
        }
    }
    return true;
}

function check_tree(root: Node): boolean {
    return validate(root) && root.children.length <= 2;
}

function main() {
    const root = new Node(0, [new Node(1), new Node(2, [new Node(3), new Node(4)])]);
    console.log(check_tree(root));
}

main();