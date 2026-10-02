class DocumentParser {
    constructor(text) {
        this.text = text;
        this.tokens = [];
    }

    tokenize() {
        this.tokens = this.text.match(/\b\w+\b/g);
        return this.tokens;
    }

    filter_tokens(min_length) {
        this.tokens = this.tokens.filter(token => token.length >= min_length);
        return this.tokens;
    }
}

class TokenAnalyzer {
    constructor(tokens) {
        this.tokens = tokens;
        this.analysis = {};
    }

    count_tokens() {
        const Counter = (arr) => arr.reduce((acc, val) => {
            acc[val] = (acc[val] || 0) + 1;
            return acc;
        }, {});
        this.analysis = Counter(this.tokens);
        return this.analysis;
    }

    update_analysis(new_tokens) {
        const Counter = (arr) => arr.reduce((acc, val) => {
            acc[val] = (acc[val] || 0) + 1;
            return acc;
        }, {});
        const newCounter = Counter(new_tokens);
        for (const key in newCounter) {
            this.analysis[key] = (this.analysis[key] || 0) + newCounter[key];
        }
        return this.analysis;
    }
}

class DataProcessor {
    constructor(parser, analyzer) {
        this.parser = parser;
        this.analyzer = analyzer;
    }

    process() {
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