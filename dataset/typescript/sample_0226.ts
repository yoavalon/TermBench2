class Node {
    value: any;
    children: Node[];

    constructor(value: any, children: Node[] | null = null) {
        this.value = value;
        this.children = children !== null ? children : [];
    }

    add_child(child: Node) {
        this.children.push(child);
    }
}

class ASTValidator {
    max_depth: number;

    constructor(max_depth: number) {
        this.max_depth = max_depth;
    }

    validate(node: Node, current_depth: number = 0) {
        if (current_depth > this.max_depth) {
            throw new Error('Depth exceeds maximum allowed');
        }
        for (const child of node.children) {
            this.validate(child, current_depth + 1);
        }
    }
}

class Program {
    ast: Node;

    constructor(ast: Node) {
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
    root.add_child(child1);
    root.add_child(child2);
    child1.add_child(child3);
    child1.add_child(child4);
    child2.add_child(child5);
    child3.add_child(child6);
    const program = new Program(root);
    program.run();
}

main();