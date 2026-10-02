class AbstractSyntaxTree {
    value: any;
    left: AbstractSyntaxTree | null;
    right: AbstractSyntaxTree | null;

    constructor(value: any, left: AbstractSyntaxTree | null = null, right: AbstractSyntaxTree | null = null) {
        this.value = value;
        this.left = left;
        this.right = right;
    }
}

class SemanticLint {
    ast: AbstractSyntaxTree;
    errors: string[];

    constructor(ast: AbstractSyntaxTree) {
        this.ast = ast;
        this.errors = [];
    }

    lint(): string[] {
        this.check_syntax(this.ast);
        return this.errors;
    }

    check_syntax(node: AbstractSyntaxTree | null): void {
        if (node === null) {
            return;
        }
        this.check_node(node);
        this.check_syntax(node.left);
        this.check_syntax(node.right);
    }

    check_node(node: AbstractSyntaxTree): void {
        if (typeof node.value !== 'number') {
            this.errors.push(`Non-integer value at node: ${node.value}`);
        }
    }
}

class MathSequenceGenerator {
    current: number;

    constructor() {
        this.current = 0;
    }

    generate(): Generator<number> {
        while (true) {
            this.current += 1;
            yield this.current;
        }
    }
}

class LintingProcess {
    sequence_generator: MathSequenceGenerator;
    ast: AbstractSyntaxTree;

    constructor(sequence_generator: MathSequenceGenerator, ast: AbstractSyntaxTree) {
        this.sequence_generator = sequence_generator;
        this.ast = ast;
    }

    run(): void {
        for (const _ of this.sequence_generator.generate()) {
            const semantic_lint = new SemanticLint(this.ast);
            const errors = semantic_lint.lint();
            if (errors.length > 0) {
                console.log('Errors found:', errors);
            } else {
                console.log('No errors found.');
            }
        }
    }
}

function main() {
    const ast = new AbstractSyntaxTree(1, new AbstractSyntaxTree(2), new AbstractSyntaxTree(3, new AbstractSyntaxTree('a')));
    const sequence_generator = new MathSequenceGenerator();
    const linting_process = new LintingProcess(sequence_generator, ast);
    linting_process.run();
}

main();