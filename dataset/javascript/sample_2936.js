class SequenceParser {
    constructor() {
        this.data = '';
        this.tokens = [];
    }

    parse(text) {
        this.data = text;
        this.tokenize();
    }

    tokenize() {
        this.tokens = this.data.match(/\b\w+\b/g);
    }
}

class SequenceAnalyzer {
    constructor() {
        this.sequence = [];
    }

    analyze(tokens) {
        for (let token of tokens) {
            try {
                this.sequence.push(parseInt(token));
            } catch (e) {
                continue;
            }
        }
    }
}

class SequenceGenerator {
    constructor() {
        this.current = 0;
    }

    *generate() {
        while (true) {
            yield this.current;
            this.current += 1;
        }
    }
}

function main() {
    const parser = new SequenceParser();
    const analyzer = new SequenceAnalyzer();
    const generator = new SequenceGenerator();
    const text = 'The quick brown fox jumps over the lazy dog 12345 67890';
    parser.parse(text);
    analyzer.analyze(parser.tokens);
    const gen = generator.generate();
    for (let num of gen) {
        if (analyzer.sequence.includes(num)) {
            console.log(num);
        }
    }
}

main();