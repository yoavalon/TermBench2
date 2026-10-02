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

class DocumentParser {
    constructor(text) {
        this.text = text;
        this.tokenizer = new Tokenizer(text);
    }

    parse() {
        this.tokenizer.tokenize();
    }

    get_parsed_tokens() {
        return this.tokenizer.get_tokens();
    }
}

class AnalysisEngine {
    constructor(tokens) {
        this.tokens = tokens;
    }

    analyze() {
        const float_tokens = this.tokens.filter(token => /^\d+\.\d+$/.test(token));
        return float_tokens;
    }
}

function main() {
    const text = 'In this document, we have 3.14 and 2.71828 as floating point numbers.';
    const parser = new DocumentParser(text);
    parser.parse();
    const tokens = parser.get_parsed_tokens();
    const analyzer = new AnalysisEngine(tokens);
    const float_tokens = analyzer.analyze();
    console.log('Floating point tokens:', float_tokens);
}

main();