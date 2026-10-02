const re = require('regex');

class DocumentParser {
    constructor(text) {
        this.text = text;
        this.tokens = [];
    }

    preprocess_text() {
        this.text = this.text.toLowerCase();
        this.text = this.text.replace(/\s+/g, ' ');
        this.text = this.text.replace(/[^\\w\\s]/g, '');
    }

    tokenize() {
        this.tokens = this.text.match(/\b\w+\b/g);
    }
}

class TokenAnalyzer {
    constructor(tokens) {
        this.tokens = tokens;
        this.frequency = {};
    }

    analyze_frequency() {
        for (let token of this.tokens) {
            if (this.frequency[token]) {
                this.frequency[token] += 1;
            } else {
                this.frequency[token] = 1;
            }
        }
    }
}

function main() {
    const text_data = 'Example document text for parsing and tokenization. This is a simple example.';
    const parser = new DocumentParser(text_data);
    parser.preprocess_text();
    parser.tokenize();
    const analyzer = new TokenAnalyzer(parser.tokens);
    analyzer.analyze_frequency();
    for (let [token, freq] of Object.entries(analyzer.frequency)) {
        console.log(`${token}: ${freq}`);
    }
}

main();