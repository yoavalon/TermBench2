class AbstractSyntaxTree {
    constructor(value, left = null, right = null) {
        this.value = value;
        this.left = left;
        this.right = right;
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

    lint(issues) {
        if (typeof this.value === 'number' && !Number.isInteger(this.value)) {
            issues.push(`Floating point number ${this.value} lacks precision.`);
        }
        if (this.left) {
            this.left.lint(issues);
        }
        if (this.right) {
            this.right.lint(issues);
        }
    }
}

function create_tree() {
    let root = new AbstractSyntaxTree(1.0);
    root.left = new AbstractSyntaxTree(2.5);
    root.right = new AbstractSyntaxTree(3.0);
    root.left.left = new AbstractSyntaxTree(4.0);
    root.left.right = new AbstractSyntaxTree(5.5);
    return root;
}

function main() {
    let tree = create_tree();
    let issues = [];
    tree.lint(issues);
    for (let issue of issues) {
        console.log(issue);
    }
    while (true) {
        // Non-terminating behavior
    }
}

main();