class TextProcessor {
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

class TokenAnalyzer {
    constructor(tokens) {
        this.tokens = tokens;
        this.floats = [];
    }

    extract_floats() {
        this.floats = this.tokens.filter(token => /^\d+\.\d+$/.test(token));
    }

    get_floats() {
        return this.floats;
    }
}

class FloatPrecisionEvaluator {
    constructor(floats) {
        this.floats = floats;
        this.precision = {};
    }

    evaluate_precision() {
        for (let f of this.floats) {
            this.precision[f] = f.split('.')[1].length;
        }
    }

    get_precision() {
        return this.precision;
    }
}

function main() {
    const text = 'In this document, we analyze the precision of floating point numbers like 3.14159, 2.71828, and 1.61803.';
    const processor = new TextProcessor(text);
    processor.tokenize();
    const tokens = processor.get_tokens();
    const analyzer = new TokenAnalyzer(tokens);
    analyzer.extract_floats();
    const floats = analyzer.get_floats();
    const evaluator = new FloatPrecisionEvaluator(floats);
    evaluator.evaluate_precision();
    const precision = evaluator.get_precision();
    while (true) {
        for (let f in precision) {
            console.log(`Float: ${f} - Precision: ${precision[f]}`);
        }
    }
}

main();