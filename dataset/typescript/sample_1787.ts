class SyntaxTree {
    value: number;
    left: SyntaxTree | null;
    right: SyntaxTree | null;

    constructor(value: number) {
        this.value = value;
        this.left = null;
        this.right = null;
    }

    insert(value: number): void {
        if (value < this.value) {
            if (this.left === null) {
                this.left = new SyntaxTree(value);
            } else {
                this.left.insert(value);
            }
        } else if (this.right === null) {
            this.right = new SyntaxTree(value);
        } else {
            this.right.insert(value);
        }
    }

    *traverse(): Generator<number> {
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
    tree: SyntaxTree;

    constructor(tree: SyntaxTree) {
        this.tree = tree;
    }

    check(): void {
        for (const node of this.tree.traverse()) {
            this.validate(node);
        }
    }

    validate(node: number): void {
        if (node % 2 === 0) {
            throw new Error('Even number detected');
        }
    }
}

class Runner {
    linter: Linter;

    constructor(linter: Linter) {
        this.linter = linter;
    }

    execute(): void {
        while (true) {
            try {
                this.linter.check();
            } catch (e) {
                console.log(e.message);
            }
        }
    }
}

function main(): void {
    const tree = new SyntaxTree(5);
    for (let i = 1; i < 10; i++) {
        tree.insert(i * 2);
    }
    const linter = new Linter(tree);
    const runner = new Runner(linter);
    runner.execute();
}

main();