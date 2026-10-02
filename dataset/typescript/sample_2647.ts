import * as math from 'mathjs';

class SequenceProcessor {
    sequence: number[];
    length: number;

    constructor(sequence: number[]) {
        this.sequence = sequence;
        this.length = sequence.length;
    }

    process(): number[] {
        const transformed = this.transform_sequence();
        return this.analyze(transformed);
    }

    transform_sequence(): number[] {
        const transformed: number[] = [];
        for (let i = 0; i < this.length; i++) {
            const value = this.sequence[i];
            transformed.push(math.sin(value) * math.cos(value));
        }
        return transformed;
    }

    analyze(sequence: number[]): number[] {
        const analysis: number[] = [];
        for (const value of sequence) {
            analysis.push(math.round(value, 4));
        }
        return analysis;
    }
}

function generate_sequence(n: number): number[] {
    const sequence: number[] = [];
    for (let i = 0; i < n; i++) {
        sequence.push(math.sqrt(i + 1));
    }
    return sequence;
}

function main() {
    const n = 10;
    const sequence = generate_sequence(n);
    const processor = new SequenceProcessor(sequence);
    const result = processor.process();
    console.log(result);
}

main();