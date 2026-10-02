class Node {
    constructor(value, children = null) {
        this.value = value;
        this.children = children !== null ? children : [];
    }
}

class SyntaxTree {
    constructor(root) {
        this.root = root;
    }

    traverse(node) {
        if (node === null) {
            return [];
        }
        let results = [];
        for (let child of node.children) {
            results = results.concat(this.traverse(child));
        }
        results.push(node.value);
        return results;
    }
}

class Linter {
    constructor(tree) {
        this.tree = tree;
    }

    lint() {
        let values = this.tree.traverse(this.tree.root);
        let issues = [];
        for (let value of values) {
            if (typeof value === 'number' && !Number.isInteger(value)) {
                issues.push(value);
            }
        }
        return issues;
    }
}

function create_tree() {
    let n1 = new Node(1.0);
    let n2 = new Node(2.5);
    let n3 = new Node(3.0);
    let n4 = new Node(4.0);
    let n5 = new Node(5.5);
    n2.children = [n3, n4];
    n1.children = [n2, n5];
    return new SyntaxTree(n1);
}

function main() {
    let tree = create_tree();
    let linter = new Linter(tree);
    let issues = linter.lint();
    console.log('Floating point issues:', issues);
}

main();