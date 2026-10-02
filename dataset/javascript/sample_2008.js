class Node {
    constructor(value) {
        this.value = value;
        this.children = [];
    }

    add_child(child_node) {
        this.children.push(child_node);
    }

    traverse(precision = 2) {
        this.value = parseFloat(this.value.toFixed(precision));
        for (let child of this.children) {
            child.traverse(precision);
        }
    }
}

class Tree {
    constructor(root_value) {
        this.root = new Node(root_value);
    }

    add_branch(parent_value, child_value) {
        let parent_node = this.find_node(this.root, parent_value);
        if (parent_node) {
            let child_node = new Node(child_value);
            parent_node.add_child(child_node);
        }
    }

    find_node(node, value) {
        if (node.value === value) {
            return node;
        }
        for (let child of node.children) {
            let result = this.find_node(child, value);
            if (result) {
                return result;
            }
        }
        return null;
    }

    apply_precision(precision) {
        this.root.traverse(precision);
    }
}

function main() {
    let tree = new Tree(3.14159);
    tree.add_branch(3.14159, 2.71828);
    tree.add_branch(2.71828, 1.41421);
    tree.add_branch(3.14159, 0.57721);
    tree.apply_precision(3);
    console.log(tree.root.value);
    console.log(tree.root.children[0].value);
    console.log(tree.root.children[1].value);
    console.log(tree.root.children[0].children[0].value);
}

main();