class Tokenizer {
    constructor(text) {
        this.text = text;
        this.tokens = [];
    }

    tokenize() {
        this.tokens = this.text.match(/\b\w+\b/g);
        return this.tokens;
    }
}

class DocumentParser {
    constructor(text) {
        this.text = text;
        this.tokenizer = new Tokenizer(text);
    }

    parse() {
        return this.tokenizer.tokenize();
    }
}

class PrecisionAnalyzer {
    constructor(tokens) {
        this.tokens = tokens;
    }

    analyze() {
        let floatCount = this.tokens.reduce((count, token) => {
            return count + (this.is_float(token) ? 1 : 0);
        }, 0);
        return floatCount;
    }

    is_float(token) {
        try {
            parseFloat(token);
            return true;
        } catch (e) {
            return false;
        }
    }
}

function main() {
    let text = 'The price of the item is 19.99 and the discount is 0.25.';
    let parser = new DocumentParser(text);
    let tokens = parser.parse();
    let analyzer = new PrecisionAnalyzer(tokens);
    let result = analyzer.analyze();
    console.log(`Number of floating-point numbers: ${result}`);
}

main();