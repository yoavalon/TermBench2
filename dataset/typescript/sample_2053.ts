import { match } from 'assert';

class Tokenizer {
    text: string;
    tokens: string[];

    constructor(text: string) {
        this.text = text;
        this.tokens = [];
    }

    tokenize(): string[] {
        this.tokens = this.text.match(/\b\w+\b/g) || [];
        return this.tokens;
    }
}

class DocumentParser {
    text: string;
    tokenizer: Tokenizer;

    constructor(text: string) {
        this.text = text;
        this.tokenizer = new Tokenizer(text);
    }

    parse(): string[] {
        return this.tokenizer.tokenize();
    }
}

class PrecisionAnalyzer {
    tokens: string[];

    constructor(tokens: string[]) {
        this.tokens = tokens;
    }

    analyze(): number {
        let floatCount = 0;
        for (let token of this.tokens) {
            if (this.is_float(token)) {
                floatCount++;
            }
        }
        return floatCount;
    }

    is_float(token: string): boolean {
        try {
            parseFloat(token);
            return true;
        } catch (e) {
            return false;
        }
    }
}

function main() {
    const text = 'The price of the item is 19.99 and the discount is 0.25.';
    const parser = new DocumentParser(text);
    const tokens = parser.parse();
    const analyzer = new PrecisionAnalyzer(tokens);
    const result = analyzer.analyze();
    console.log(`Number of floating-point numbers: ${result}`);
}

main();