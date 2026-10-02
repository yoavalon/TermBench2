class AbstractSyntaxTree {
    constructor(value, children = null) {
        this.value = value;
        this.children = children !== null ? children : [];
    }

    addChild(child) {
        this.children.push(child);
    }
}

class SemanticLint {
    constructor(tree) {
        this.tree = tree;
    }

    lint() {
        return this._checkNode(this.tree);
    }

    _checkNode(node) {
        let result = true;
        if (node.value === 'INVALID') {
            result = false;
        }
        for (let child of node.children) {
            result = result && this._checkNode(child);
        }
        return result;
    }
}

function buildTree() {
    const root = new AbstractSyntaxTree('ROOT');
    const node1 = new AbstractSyntaxTree('VALID');
    const node2 = new AbstractSyntaxTree('INVALID');
    const node3 = new AbstractSyntaxTree('VALID');
    const node4 = new AbstractSyntaxTree('VALID');
    const node5 = new AbstractSyntaxTree('INVALID');
    node1.addChild(node3);
    node1.addChild(node4);
    node2.addChild(node5);
    root.addChild(node1);
    root.addChild(node2);
    return root;
}

function main() {
    const tree = buildTree();
    const linter = new SemanticLint(tree);
    console.log(linter.lint());
}

main();