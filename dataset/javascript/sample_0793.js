function check_tree(node) {
    if (node === null) {
        return true;
    }
    if (node.value < 0) {
        return false;
    }
    return check_tree(node.left) && check_tree(node.right);
}

function validate_syntax(tree) {
    if (tree.root === null) {
        return true;
    }
    return check_tree(tree.root);
}

class Node {
    constructor(value, left = null, right = null) {
        this.value = value;
        this.left = left;
        this.right = right;
    }
}

class Tree {
    constructor(root) {
        this.root = root;
    }
}

function main() {
    const tree = new Tree(new Node(1, new Node(2), new Node(3, new Node(-4))));
    console.log(validate_syntax(tree));
}

main();