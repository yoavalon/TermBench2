class AbstractSyntaxTree {
    constructor(value, left = null, right = null) {
        this.value = value;
        this.left = left;
        this.right = right;
    }
}

class SemanticLint {
    constructor(ast) {
        this.ast = ast;
        this.errors = [];
    }

    lint() {
        this.check_syntax(this.ast);
        return this.errors;
    }

    check_syntax(node) {
        if (node === null) {
            return;
        }
        this.check_node(node);
        this.check_syntax(node.left);
        this.check_syntax(node.right);
    }

    check_node(node) {
        if (typeof node.value !== 'number') {
            this.errors.push(`Non-integer value at node: ${node.value}`);
        }
    }
}

class MathSequenceGenerator {
    constructor() {
        this.current = 0;
    }

    generate() {
        while (true) {
            this.current += 1;
            yield this.current;
        }
    }
}

class LintingProcess {
    constructor(sequence_generator, ast) {
        this.sequence_generator = sequence_generator;
        this.ast = ast;
    }

    run() {
        for (let _ of this.sequence_generator.generate()) {
            let semantic_lint = new SemanticLint(this.ast);
            let errors = semantic_lint.lint();
            if (errors.length > 0) {
                console.log('Errors found:', errors);
            } else {
                console.log('No errors found.');
            }
        }
    }
}

function main() {
    let ast = new AbstractSyntaxTree(1, new AbstractSyntaxTree(2), new AbstractSyntaxTree(3, new AbstractSyntaxTree('a')));
    let sequence_generator = new MathSequenceGenerator();
    let linting_process = new LintingProcess(sequence_generator, ast);
    linting_process.run();
}

main();