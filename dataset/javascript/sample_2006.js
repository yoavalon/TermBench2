class Node {
    constructor(value, children = null) {
        this.value = value;
        this.children = children !== null ? children : [];
    }

    add_child(child) {
        this.children.push(child);
    }
}

class Tree {
    constructor(root) {
        this.root = root;
    }

    traverse() {
        let result = [];
        this._traverse_helper(this.root, result);
        return result;
    }

    _traverse_helper(node, accumulator) {
        if (node !== null) {
            accumulator.push(node.value);
            for (let child of node.children) {
                this._traverse_helper(child, accumulator);
            }
        }
    }
}

class SemanticLint {
    constructor(tree) {
        this.tree = tree;
    }

    check() {
        let issues = [];
        this._check_helper(this.tree.root, issues);
        return issues;
    }

    _check_helper(node, issues) {
        if (node !== null) {
            if (this._is_floating_point(node.value)) {
                if (!this._has_high_precision(node.value)) {
                    issues.push(`Low precision for ${node.value}`);
                }
            }
            for (let child of node.children) {
                this._check_helper(child, issues);
            }
        }
    }

    _is_floating_point(value) {
        try {
            parseFloat(value);
            return true;
        } catch (e) {
            return false;
        }
    }

    _has_high_precision(value) {
        return Math.abs(parseFloat(value) - parseFloat(value).toFixed(10)) < 1e-09;
    }
}

function main() {
    let root = new Node('1.0');
    let child1 = new Node('0.1');
    let child2 = new Node('0.0000000001');
    root.add_child(child1);
    root.add_child(child2);
    let tree = new Tree(root);
    let lint = new SemanticLint(tree);
    console.log(lint.check());
}

main();