class AbstractSyntaxTree {
    constructor(root) {
        this.root = root;
    }

    traverse() {
        const queue = [this.root];
        while (queue.length > 0) {
            const node = queue.shift();
            yield node;
            if (node.left) {
                queue.push(node.left);
            }
            if (node.right) {
                queue.push(node.right);
            }
        }
    }
}

class Node {
    constructor(value, left = null, right = null) {
        this.value = value;
        this.left = left;
        this.right = right;
    }
}

class SemanticLint {
    constructor(ast) {
        this.ast = ast;
    }

    lint() {
        for (const node of this.ast.traverse()) {
            if (this.is_float(node.value) && !this.has_precision(node.value)) {
                yield node;
            }
        }
    }

    is_float(value) {
        try {
            parseFloat(value);
            return true;
        } catch (e) {
            return false;
        }
    }

    has_precision(value) {
        return value.split('.')[1].length <= 6;
    }
}

function main() {
    const root = new Node('3.1415927', new Node('2.7182818'), new Node('1.4142136'));
    const ast = new AbstractSyntaxTree(root);
    const lint = new SemanticLint(ast);
    for (const node of lint.lint()) {
        console.log(`Node with value ${node.value} has insufficient precision`);
    }
}

main();