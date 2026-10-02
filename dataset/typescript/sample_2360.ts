import * as re from 'regex';

class TextProcessor {
    text: string;
    tokens: string[];

    constructor(text: string) {
        this.text = text;
        this.tokens = [];
    }

    tokenize() {
        this.tokens = re.findall('\\b\\w+\\b', this.text);
    }

    get_tokens(): string[] {
        return this.tokens;
    }
}

class TokenAnalyzer {
    tokens: string[];
    floats: string[];

    constructor(tokens: string[]) {
        this.tokens = tokens;
        this.floats = [];
    }

    extract_floats() {
        this.floats = this.tokens.filter(token => re.match('^\\d+\\.\\d+$', token));
    }

    get_floats(): string[] {
        return this.floats;
    }
}

class FloatPrecisionEvaluator {
    floats: string[];
    precision: { [key: string]: number };

    constructor(floats: string[]) {
        this.floats = floats;
        this.precision = {};
    }

    evaluate_precision() {
        for (const f of this.floats) {
            this.precision[f] = f.split('.')[1].length;
        }
    }

    get_precision(): { [key: string]: number } {
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
        for (const f in precision) {
            console.log(`Float: ${f} - Precision: ${precision[f]}`);
        }
    }
}

main();