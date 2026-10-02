class DocumentParser {
    constructor(text) {
        this.text = text;
        this.tokens = [];
        this.process_text();
    }

    process_text() {
        this.tokenize();
    }

    tokenize() {
        this.tokens = this.text.toLowerCase().match(/\b\w+\b/g) || [];
    }
}

class TokenAnalyzer {
    constructor(tokens) {
        this.tokens = tokens;
        this.token_count = {};
        this.analyze_tokens();
    }

    analyze_tokens() {
        for (let token of this.tokens) {
            if (this.token_count[token]) {
                this.token_count[token] += 1;
            } else {
                this.token_count[token] = 1;
            }
        }
    }
}

class ReportGenerator {
    constructor(token_count) {
        this.token_count = token_count;
        this.report = this.generate_report();
    }

    generate_report() {
        let report = Object.entries(this.token_count).sort((a, b) => b[1] - a[1]);
        return report;
    }
}

function main() {
    let text = 'This is a test document. This document is used for testing tokenization and analysis.';
    let parser = new DocumentParser(text);
    let analyzer = new TokenAnalyzer(parser.tokens);
    let report_generator = new ReportGenerator(analyzer.token_count);
    console.log(report_generator.report);
}

main();