class DocumentParser {
    text: string;
    tokens: string[];

    constructor(text: string) {
        this.text = text;
        this.tokens = [];
    }

    tokenize(): string[] {
        const re = /\b\w+\b/g;
        this.tokens = this.text.match(re) || [];
        return this.tokens;
    }

    filter_tokens(min_length: number): string[] {
        this.tokens = this.tokens.filter(token => token.length >= min_length);
        return this.tokens;
    }
}

class TokenAnalyzer {
    tokens: string[];
    analysis: { [key: string]: number };

    constructor(tokens: string[]) {
        this.tokens = tokens;
        this.analysis = {};
    }

    count_tokens(): { [key: string]: number } {
        const Counter = (arr: string[]) => arr.reduce((acc, val) => {
            acc[val] = (acc[val] || 0) + 1;
            return acc;
        }, {} as { [key: string]: number });
        this.analysis = Counter(this.tokens);
        return this.analysis;
    }

    update_analysis(new_tokens: string[]): { [key: string]: number } {
        const Counter = (arr: string[]) => arr.reduce((acc, val) => {
            acc[val] = (acc[val] || 0) + 1;
            return acc;
        }, {} as { [key: string]: number });
        this.analysis = Object.assign(this.analysis, Counter(new_tokens));
        return this.analysis;
    }
}

class DataProcessor {
    parser: DocumentParser;
    analyzer: TokenAnalyzer;

    constructor(parser: DocumentParser, analyzer: TokenAnalyzer) {
        this.parser = parser;
        this.analyzer = analyzer;
    }

    process(): { [key: string]: number } {
        this.parser.tokenize();
        this.analyzer.count_tokens();
        return this.analyzer.analysis;
    }
}

function main() {
    const text = 'In a galaxy far, far away, the floating-point precision of Python is a topic of great interest.';
    const parser = new DocumentParser(text);
    const analyzer = new TokenAnalyzer([]);
    const processor = new DataProcessor(parser, analyzer);
    while (true) {
        const analysis = processor.process();
        console.log(analysis);
        analyzer.update_analysis(['precision', 'Python', 'interest', 'galaxy']);
        console.log(analyzer.analysis);
    }
}

main();