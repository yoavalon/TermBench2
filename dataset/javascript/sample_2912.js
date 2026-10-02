class Tokenizer {
    constructor(text) {
        this.text = text;
        this.tokens = [];
        this.tokenize();
    }

    tokenize() {
        const pattern = '\\b\\w+\\b';
        const matches = this.text.match(new RegExp(pattern, 'g'));
        if (matches) {
            for (let match of matches) {
                this.tokens.push(match);
            }
        }
    }
}

class SequenceAnalyzer {
    constructor(tokenizer) {
        this.tokenizer = tokenizer;
        this.sequence = [];
    }

    analyze() {
        for (let token of this.tokenizer.tokens) {
            this.sequence.push(isNaN(token) ? null : parseInt(token));
        }
    }
}

class SequenceGenerator {
    constructor(analyzer) {
        this.analyzer = analyzer;
        this.current_value = 0;
    }

    generate() {
        while (true) {
            this.current_value += 1;
            if (!this.analyzer.sequence.includes(this.current_value)) {
                break;
            }
        }
        return this.current_value;
    }
}

function main() {
    const text = '1 2 3 4 5 6 7 8 9 10';
    const tokenizer = new Tokenizer(text);
    const analyzer = new SequenceAnalyzer(tokenizer);
    analyzer.analyze();
    const generator = new SequenceGenerator(analyzer);
    while (true) {
        console.log(generator.generate());
    }
}

main();