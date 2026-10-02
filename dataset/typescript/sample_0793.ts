function check_tree(node: Node | null): boolean {
    if (node === null) {
        return true;
    }
    if (node.value < 0) {
        return false;
    }
    return check_tree(node.left) && check_tree(node.right);
}

function validate_syntax(tree: Tree): boolean {
    if (tree.root === null) {
        return true;
    }
    return check_tree(tree.root);
}

class Node {
    value: number;
    left: Node | null;
    right: Node | null;

    constructor(value: number, left: Node | null = null, right: Node | null = null) {
        this.value = value;
        this.left = left;
        this.right = right;
    }
}

class Tree {
    root: Node | null;

    constructor(root: Node | null) {
        this.root = root;
    }
}

function main() {
    const tree = new Tree(new Node(1, new Node(2), new Node(3, new Node(-4))));
    console.log(validate_syntax(tree));
}

main();