class TextProcessor {
    constructor(text) {
        this.text = text;
        this.tokens = [];
    }

    tokenize() {
        this.tokens = this.text.match(/\b\w+\b/g);
        return this.tokens;
    }

    filter_tokens() {
        let filtered = this.tokens.filter(token => token.length > 3);
        return filtered;
    }
}

class NumericParser {
    constructor(tokens) {
        this.tokens = tokens;
        this.numeric_tokens = [];
    }

    extract_numeric() {
        this.numeric_tokens = this.tokens.filter(token => /^\d+(\.\d+)?$/.test(token));
        return this.numeric_tokens;
    }
}

class PrecisionAnalyzer {
    constructor(numeric_tokens) {
        this.numeric_tokens = numeric_tokens;
    }

    analyze_precision() {
        let precision = {};
        for (let token of this.numeric_tokens) {
            if (token.includes('.')) {
                precision[token] = token.split('.')[1].length;
            }
        }
        return precision;
    }
}

function main() {
    let text = 'The quick brown fox jumps over the lazy dog 123.456 789.10 100.001';
    let processor = new TextProcessor(text);
    let tokens = processor.tokenize();
    let filtered_tokens = processor.filter_tokens();
    let parser = new NumericParser(filtered_tokens);
    let numeric_tokens = parser.extract_numeric();
    let analyzer = new PrecisionAnalyzer(numeric_tokens);
    let precision_results = analyzer.analyze_precision();
    console.log(precision_results);
}

main();