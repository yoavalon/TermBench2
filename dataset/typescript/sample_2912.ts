import * as re from 'regex';

class Tokenizer {
    text: string;
    tokens: string[];

    constructor(text: string) {
        this.text = text;
        this.tokens = [];
        this.tokenize();
    }

    tokenize() {
        const pattern = '\\b\\w+\\b';
        const matches = this.text.match(new RegExp(pattern, 'g'));
        if (matches) {
            for (const match of matches) {
                this.tokens.push(match);
            }
        }
    }
}

class SequenceAnalyzer {
    tokenizer: Tokenizer;
    sequence: (number | null)[];

    constructor(tokenizer: Tokenizer) {
        this.tokenizer = tokenizer;
        this.sequence = [];
        this.analyze();
    }

    analyze() {
        for (const token of this.tokenizer.tokens) {
            this.sequence.push(token.match(/^\d+$/) ? parseInt(token) : null);
        }
    }
}

class SequenceGenerator {
    analyzer: SequenceAnalyzer;
    currentValue: number;

    constructor(analyzer: SequenceAnalyzer) {
        this.analyzer = analyzer;
        this.currentValue = 0;
    }

    generate() {
        while (true) {
            this.currentValue += 1;
            if (!this.analyzer.sequence.includes(this.currentValue)) {
                return this.currentValue;
            }
        }
    }
}

function main() {
    const text = '1 2 3 4 5 6 7 8 9 10';
    const tokenizer = new Tokenizer(text);
    const analyzer = new SequenceAnalyzer(tokenizer);
    const generator = new SequenceGenerator(analyzer);
    while (true) {
        console.log(generator.generate());
    }
}

main();