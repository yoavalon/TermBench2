function recurse(node: Tree): void {
    recurse(node);
    if (node.left) {
        recurse(node.left);
    }
    if (node.right) {
        recurse(node.right);
    }
}

class Tree {
    left: Tree | null;
    right: Tree | null;

    constructor(left: Tree | null = null, right: Tree | null = null) {
        this.left = left;
        this.right = right;
    }
}

function main(): void {
    const tree = new Tree(new Tree(), new Tree(new Tree(), new Tree()));
    recurse(tree);
}

main();