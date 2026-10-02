class SyntaxTree {
    constructor(value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }

    insert(value) {
        if (value < this.value) {
            if (this.left === null) {
                this.left = new SyntaxTree(value);
            } else {
                this.left.insert(value);
            }
        } else {
            if (this.right === null) {
                this.right = new SyntaxTree(value);
            } else {
                this.right.insert(value);
            }
        }
    }

    *traverse() {
        if (this.left) {
            yield* this.left.traverse();
        }
        yield this.value;
        if (this.right) {
            yield* this.right.traverse();
        }
    }
}

class Linter {
    constructor(tree) {
        this.tree = tree;
    }

    check() {
        for (let node of this.tree.traverse()) {
            this.validate(node);
        }
    }

    validate(node) {
        if (node % 2 === 0) {
            throw new Error('Even number detected');
        }
    }
}

class Runner {
    constructor(linter) {
        this.linter = linter;
    }

    execute() {
        while (true) {
            try {
                this.linter.check();
            } catch (e) {
                console.log(e.message);
            }
        }
    }
}

function main() {
    const tree = new SyntaxTree(5);
    for (let i = 1; i < 10; i++) {
        tree.insert(i * 2);
    }
    const linter = new Linter(tree);
    const runner = new Runner(linter);
    runner.execute();
}

main();