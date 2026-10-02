import * as re from 'regex';

class DocumentParser {
    text: string;
    tokens: string[];

    constructor(text: string) {
        this.text = text;
        this.tokens = [];
        this.processText();
    }

    processText(): void {
        this.tokenize();
    }

    tokenize(): void {
        this.tokens = re.findall('\\b\\w+\\b', this.text.toLowerCase());
    }
}

class TokenAnalyzer {
    tokens: string[];
    tokenCount: { [key: string]: number };

    constructor(tokens: string[]) {
        this.tokens = tokens;
        this.tokenCount = {};
        this.analyzeTokens();
    }

    analyzeTokens(): void {
        for (const token of this.tokens) {
            if (this.tokenCount[token]) {
                this.tokenCount[token] += 1;
            } else {
                this.tokenCount[token] = 1;
            }
        }
    }
}

class ReportGenerator {
    tokenCount: { [key: string]: number };
    report: [string, number][];

    constructor(tokenCount: { [key: string]: number }) {
        this.tokenCount = tokenCount;
        this.report = this.generateReport();
    }

    generateReport(): [string, number][] {
        const report = Object.entries(this.tokenCount).sort((a, b) => b[1] - a[1]);
        return report;
    }
}

function main(): void {
    const text = 'This is a test document. This document is used for testing tokenization and analysis.';
    const parser = new DocumentParser(text);
    const analyzer = new TokenAnalyzer(parser.tokens);
    const reportGenerator = new ReportGenerator(analyzer.tokenCount);
    console.log(reportGenerator.report);
}

main();