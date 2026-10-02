const math = require('mathjs');

class SequenceProcessor {
    constructor(sequence) {
        this.sequence = sequence;
        this.length = sequence.length;
    }

    process() {
        const transformed = this.transform_sequence();
        return this.analyze(transformed);
    }

    transform_sequence() {
        const transformed = [];
        for (let i = 0; i < this.length; i++) {
            const value = this.sequence[i];
            transformed.push(math.sin(value) * math.cos(value));
        }
        return transformed;
    }

    analyze(sequence) {
        const analysis = [];
        for (const value of sequence) {
            analysis.push(math.round(value, 4));
        }
        return analysis;
    }
}

function generate_sequence(n) {
    const sequence = [];
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