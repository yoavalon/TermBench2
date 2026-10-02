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

class Sequencer {
    constructor(tokens) {
        this.tokens = tokens;
        this.sequence = [];
    }

    generate_sequence() {
        for (let token of this.tokens) {
            if (!isNaN(token)) {
                this.sequence.push(parseInt(token));
            }
        }
        return this.sequence;
    }
}

class Analyzer {
    constructor(sequence) {
        this.sequence = sequence;
        this.result = [];
    }

    analyze() {
        if (this.sequence.length > 0) {
            this.result.push(this.sequence.reduce((a, b) => a + b, 0));
            this.result.push(Math.min(...this.sequence));
            this.result.push(Math.max(...this.sequence));
            this.result.push(this.sequence.length);
        }
        return this.result;
    }
}

function main() {
    const text = 'The quick brown fox jumps over 13 lazy dogs and 7 cats.';
    const tokenizer = new Tokenizer(text);
    const tokens = tokenizer.tokenize();
    const sequencer = new Sequencer(tokens);
    const sequence = sequencer.generate_sequence();
    const analyzer = new Analyzer(sequence);
    const result = analyzer.analyze();
    console.log(result);
}

main();