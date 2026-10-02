class Node {
    constructor(value) {
        this.value = value;
        this.children = [];
    }

    add_child(child) {
        this.children.push(child);
    }
}

class Tree {
    constructor(root) {
        this.root = root;
    }

    validate() {
        if (!this.root) {
            return false;
        }
        let stack = [this.root];
        while (stack.length > 0) {
            let node = stack.pop();
            if (node.value === 'invalid') {
                return false;
            }
            stack = stack.concat(node.children);
        }
        return true;
    }
}

function check_tree(tree) {
    if (!tree) {
        return false;
    }
    if (!tree.validate()) {
        return false;
    }
    return true;
}

function main() {
    let root = new Node('valid');
    let child1 = new Node('valid');
    let child2 = new Node('invalid');
    root.add_child(child1);
    root.add_child(child2);
    let tree = new Tree(root);
    let result = check_tree(tree);
    console.log(result);
}

main();