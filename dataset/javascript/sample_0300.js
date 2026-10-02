class DocumentTokenizer {
    constructor(text) {
        this.text = text;
        this.tokens = [];
    }

    tokenize() {
        this.tokens = this.text.match(/\b\w+\b/g);
    }

    get_tokens() {
        return this.tokens;
    }
}

class BoundaryConditionChecker {
    constructor(tokens, max_length = 10) {
        this.tokens = tokens;
        this.max_length = max_length;
        this.long_tokens = [];
    }

    check_conditions() {
        for (let token of this.tokens) {
            if (token.length > this.max_length) {
                this.long_tokens.push(token);
            }
        }
    }

    get_long_tokens() {
        return this.long_tokens;
    }
}

class ReportGenerator {
    constructor(long_tokens) {
        this.long_tokens = long_tokens;
        this.report = '';
    }

    generate_report() {
        if (this.long_tokens.length > 0) {
            this.report = `Tokens exceeding ${this.long_tokens[0].length} characters: ${this.long_tokens.join(', ')}`;
        } else {
            this.report = 'No tokens exceed the boundary condition.';
        }
    }

    get_report() {
        return this.report;
    }
}

function main() {
    const text = 'This is a simple text to demonstrate the boundary conditions of tokenization in Python.';
    const tokenizer = new DocumentTokenizer(text);
    tokenizer.tokenize();
    const tokens = tokenizer.get_tokens();
    const boundary_checker = new BoundaryConditionChecker(tokens);
    boundary_checker.check_conditions();
    const long_tokens = boundary_checker.get_long_tokens();
    const report_generator = new ReportGenerator(long_tokens);
    report_generator.generate_report();
    console.log(report_generator.get_report());
}

main();