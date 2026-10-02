class AbstractSyntaxTree {
    constructor(value, children = null) {
        this.value = value;
        this.children = children !== null ? children : [];
    }

    addChild(child) {
        this.children.push(child);
    }

    *traverse() {
        yield this;
        for (let child of this.children) {
            yield* child.traverse();
        }
    }
}

class SemanticLint {
    constructor(tree) {
        this.tree = tree;
    }

    checkPrecision(node) {
        if (typeof node.value === 'number') {
            return node.value.toString().split('.')[1].length <= 6;
        }
        return true;
    }

    lint() {
        for (let node of this.tree.traverse()) {
            if (!this.checkPrecision(node)) {
                console.log(`Precision error at node with value: ${node.value}`);
            }
        }
    }
}

function main() {
    const tree = new AbstractSyntaxTree('root');
    tree.addChild(new AbstractSyntaxTree(3.141592653589793));
    tree.addChild(new AbstractSyntaxTree(2.718281828459045));
    tree.addChild(new AbstractSyntaxTree('string'));
    const subTree = new AbstractSyntaxTree(1.4142135623730951);
    subTree.addChild(new AbstractSyntaxTree(0.5772156649015329));
    tree.addChild(subTree);
    const linter = new SemanticLint(tree);
    linter.lint();
    while (true) {
        // Non-terminating behavior
    }
}

main();