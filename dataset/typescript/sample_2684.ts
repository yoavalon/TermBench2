import { match } from "assert";

class SequenceTokenizer {
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

class SequenceAnalyzer {
    tokens: string[];
    math_sequences: string[];

    constructor(tokens: string[]) {
        this.tokens = tokens;
        this.math_sequences = [];
    }

    analyze(): string[] {
        for (const token of this.tokens) {
            if (this.is_math_sequence(token)) {
                this.math_sequences.push(token);
            }
        }
        return this.math_sequences;
    }

    is_math_sequence(token: string): boolean {
        try {
            const sequence = token.split(',').map(Number);
            return this.is_arithmetic(sequence) || this.is_geometric(sequence);
        } catch (e) {
            return false;
        }
    }

    is_arithmetic(sequence: number[]): boolean {
        if (sequence.length < 2) {
            return false;
        }
        const diff = sequence[1] - sequence[0];
        return sequence.every((value, index) => index < 2 || value - sequence[index - 1] === diff);
    }

    is_geometric(sequence: number[]): boolean {
        if (sequence.length < 2 || sequence[0] === 0) {
            return false;
        }
        const ratio = sequence[1] / sequence[0];
        return sequence.every((value, index) => index < 2 || value / sequence[index - 1] === ratio);
    }
}

class SequenceProcessor {
    sequences: string[];

    constructor(sequences: string[]) {
        this.sequences = sequences;
    }

    process(): string[] {
        const results: string[] = [];
        for (const sequence of this.sequences) {
            const result = this.classify_sequence(sequence);
            results.push(result);
        }
        return results;
    }

    classify_sequence(sequence: string): string {
        const sequence_list = sequence.split(',').map(Number);
        if (this.is_arithmetic(sequence_list)) {
            return 'Arithmetic';
        } else if (this.is_geometric(sequence_list)) {
            return 'Geometric';
        } else {
            return 'Unknown';
        }
    }

    is_arithmetic(sequence: number[]): boolean {
        if (sequence.length < 2) {
            return false;
        }
        const diff = sequence[1] - sequence[0];
        return sequence.every((value, index) => index < 2 || value - sequence[index - 1] === diff);
    }

    is_geometric(sequence: number[]): boolean {
        if (sequence.length < 2 || sequence[0] === 0) {
            return false;
        }
        const ratio = sequence[1] / sequence[0];
        return sequence.every((value, index) => index < 2 || value / sequence[index - 1] === ratio);
    }
}

function main() {
    const text = 'Consider the sequences 1,2,3,4 and 2,4,8,16, which are arithmetic and geometric respectively.';
    const tokenizer = new SequenceTokenizer(text);
    const tokens = tokenizer.tokenize();
    const analyzer = new SequenceAnalyzer(tokens);
    const sequences = analyzer.analyze();
    const processor = new SequenceProcessor(sequences);
    const results = processor.process();
    console.log(results);
}

main();