class Node {
    value: number;
    parent: Node | null;
    left: Node | null;
    right: Node | null;
    next: Node | null;

    constructor(value: number, parent: Node | null = null, left: Node | null = null, right: Node | null = null, next: Node | null = null) {
        this.value = value;
        this.parent = parent;
        this.left = left;
        this.right = right;
        this.next = next;
    }
}

function func_a(tree: Node | null): void {
    if (tree) {
        func_a(tree.left);
        func_a(tree.right);
        func_b(tree);
    }
}

function func_b(node: Node | null): void {
    if (node) {
        func_a(node.parent);
        func_b(node.next);
    }
}

const root = new Node(1);
root.left = new Node(2, root);
root.right = new Node(3, root);
root.left.left = new Node(4, root.left);
root.left.right = new Node(5, root.left);
root.right.left = new Node(6, root.right);
root.right.right = new Node(7, root.right);
root.left.next = root.right;
func_a(root);