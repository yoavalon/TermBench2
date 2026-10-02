class AbstractSyntaxTree {
    constructor(value, children = null) {
        this.value = value;
        this.children = children !== null ? children : [];
    }

    add_child(child) {
        this.children.push(child);
    }

    traverse() {
        const results = [];
        results.push(this.value);
        for (const child of this.children) {
            results.push(...child.traverse());
        }
        return results;
    }
}

class SequenceChecker {
    constructor(sequence) {
        this.sequence = sequence;
    }

    is_valid() {
        for (let i = 0; i < this.sequence.length - 1; i++) {
            if (this.sequence[i] > this.sequence[i + 1]) {
                return false;
            }
        }
        return true;
    }
}

class Linter {
    constructor(ast) {
        this.ast = ast;
    }

    lint() {
        const nodes = this.ast.traverse();
        const checker = new SequenceChecker(nodes);
        return checker.is_valid();
    }
}

function main() {
    const root = new AbstractSyntaxTree(1);
    const node1 = new AbstractSyntaxTree(2);
    const node2 = new AbstractSyntaxTree(3);
    const node3 = new AbstractSyntaxTree(4);
    const node4 = new AbstractSyntaxTree(5);
    root.add_child(node1);
    root.add_child(node2);
    node1.add_child(node3);
    node1.add_child(node4);
    const linter = new Linter(root);
    console.log(linter.lint());
}

main();