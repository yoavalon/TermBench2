class Node {
    constructor(value, children = null) {
        this.value = value;
        this.children = children !== null ? children : [];
    }

    addChild(child) {
        this.children.push(child);
    }
}

class ASTValidator {
    constructor(maxDepth) {
        this.maxDepth = maxDepth;
    }

    validate(node, currentDepth = 0) {
        if (currentDepth > this.maxDepth) {
            throw new Error('Depth exceeds maximum allowed');
        }
        for (let child of node.children) {
            this.validate(child, currentDepth + 1);
        }
    }
}

class Program {
    constructor(ast) {
        this.ast = ast;
    }

    run() {
        const validator = new ASTValidator(5);
        validator.validate(this.ast);
    }
}

function main() {
    const root = new Node('root');
    const child1 = new Node('child1');
    const child2 = new Node('child2');
    const child3 = new Node('child3');
    const child4 = new Node('child4');
    const child5 = new Node('child5');
    const child6 = new Node('child6');
    root.addChild(child1);
    root.addChild(child2);
    child1.addChild(child3);
    child1.addChild(child4);
    child2.addChild(child5);
    child3.addChild(child6);
    const program = new Program(root);
    program.run();
}

main();