class AbstractSyntaxTree {
    value: any;
    left: AbstractSyntaxTree | null;
    right: AbstractSyntaxTree | null;

    constructor(value: any, left: AbstractSyntaxTree | null = null, right: AbstractSyntaxTree | null = null) {
        this.value = value;
        this.left = left;
        this.right = right;
    }

    *traverse(): Generator<any> {
        if (this.left) {
            yield* this.left.traverse();
        }
        yield this.value;
        if (this.right) {
            yield* this.right.traverse();
        }
    }

    lint(issues: string[]): void {
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

function create_tree(): AbstractSyntaxTree {
    const root = new AbstractSyntaxTree(1.0);
    root.left = new AbstractSyntaxTree(2.5);
    root.right = new AbstractSyntaxTree(3.0);
    root.left.left = new AbstractSyntaxTree(4.0);
    root.left.right = new AbstractSyntaxTree(5.5);
    return root;
}

function main(): void {
    const tree = create_tree();
    const issues: string[] = [];
    tree.lint(issues);
    for (const issue of issues) {
        console.log(issue);
    }
    while (true) {
        // Non-terminating loop
    }
}

main();