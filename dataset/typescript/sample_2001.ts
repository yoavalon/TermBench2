import * as re from 'regex';

class Tokenizer {
    text: string;
    tokens: string[];

    constructor(text: string) {
        this.text = text;
        this.tokens = [];
    }

    tokenize() {
        this.tokens = re.findall('\\b\\w+\\b', this.text);
    }

    get_tokens() {
        return this.tokens;
    }
}

class PrecisionAnalyzer {
    tokens: string[];
    precision_issues: string[];

    constructor(tokens: string[]) {
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

    is_float(token: string): boolean {
        try {
            parseFloat(token);
            return true;
        } catch (e) {
            return false;
        }
    }

    check_precision(token: string) {
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