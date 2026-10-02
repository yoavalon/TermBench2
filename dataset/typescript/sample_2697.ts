import * as re from 'regex';

class Tokenizer {
    text: string;
    tokens: string[];

    constructor(text: string) {
        this.text = text;
        this.tokens = [];
    }

    tokenize(): string[] {
        this.tokens = re.findall('\\b\\w+\\b', this.text);
        return this.tokens;
    }
}

class Sequencer {
    tokens: string[];
    sequence: number[];

    constructor(tokens: string[]) {
        this.tokens = tokens;
        this.sequence = [];
    }

    generate_sequence(): number[] {
        for (let token of this.tokens) {
            if (token.isdigit()) {
                this.sequence.push(parseInt(token));
            }
        }
        return this.sequence;
    }
}

class Analyzer {
    sequence: number[];
    result: number[];

    constructor(sequence: number[]) {
        this.sequence = sequence;
        this.result = [];
    }

    analyze(): number[] {
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