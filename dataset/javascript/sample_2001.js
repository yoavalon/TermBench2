class Tokenizer {
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

class PrecisionAnalyzer {
    constructor(tokens) {
        this.tokens = tokens;
        this.precision_issues = [];
    }

    analyze() {
        for (let token of this.tokens) {
            if (this.is_float(token)) {
                this.check_precision(token);
            }
        }
    }

    is_float(token) {
        try {
            parseFloat(token);
            return true;
        } catch (e) {
            return false;
        }
    }

    check_precision(token) {
        if (token.includes('.')) {
            let decimal_part = token.split('.')[1];
            if (decimal_part.length > 6) {
                this.precision_issues.push(token);
            }
        }
    }

    get_issues() {
        return this.precision_issues;
    }
}

function main() {
    let text = 'In the year 2023, the global temperature was 15.2345678 degrees Celsius. The precision is critical.';
    let tokenizer = new Tokenizer(text);
    tokenizer.tokenize();
    let tokens = tokenizer.get_tokens();
    let analyzer = new PrecisionAnalyzer(tokens);
    analyzer.analyze();
    let issues = analyzer.get_issues();
    console.log('Tokens with precision issues:', issues);
}

main();