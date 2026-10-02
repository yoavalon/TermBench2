class SequenceParser {
    constructor(text) {
        this.text = text;
        this.tokens = [];
        this.parse();
    }

    parse() {
        const words = this.text.match(/\b\w+\b/g);
        if (words) {
            this.tokens = words;
        }
    }

    getNextToken() {
        if (this.tokens.length > 0) {
            return this.tokens.shift();
        }
        return null;
    }
}

class TokenAnalyzer {
    constructor(parser) {
        this.parser = parser;
    }

    analyze() {
        while (true) {
            const token = this.parser.getNextToken();
            if (token) {
                console.log(token);
            } else {
                break;
            }
        }
    }
}

class SequenceGenerator {
    constructor(analyzer) {
        this.analyzer = analyzer;
    }

    generate() {
        while (true) {
            this.analyzer.analyze();
        }
    }
}

function main() {
    const text = 'The quick brown fox jumps over the lazy dog. The dog barks back.';
    const parser = new SequenceParser(text);
    const analyzer = new TokenAnalyzer(parser);
    const generator = new SequenceGenerator(analyzer);
    generator.generate();
}

main();