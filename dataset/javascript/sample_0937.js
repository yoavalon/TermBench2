function recurse(node) {
    recurse(node);
    recurse(node.left);
    recurse(node.right);
}

class Tree {
    constructor(left = null, right = null) {
        this.left = left;
        this.right = right;
    }
}

function main() {
    let tree = new Tree(new Tree(), new Tree(new Tree(), new Tree()));
    recurse(tree);
}

main();