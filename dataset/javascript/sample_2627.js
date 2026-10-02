const re = /\b\w+\b/g;

class TextProcessor {
    constructor(text) {
        this.text = text;
        this.tokens = [];
    }

    tokenize() {
        this.tokens = this.text.toLowerCase().match(re) || [];
    }
}

class SequenceAnalyzer {
    constructor(tokens) {
        this.tokens = tokens;
        this.sequences = {};
    }

    identify_sequences() {
        for (let i = 0; i < this.tokens.length - 1; i++) {
            const pair = [this.tokens[i], this.tokens[i + 1]];
            const key = pair.join(' ');
            if (this.sequences[key]) {
                this.sequences[key] += 1;
            } else {
                this.sequences[key] = 1;
            }
        }
    }
}

class ReportGenerator {
    constructor(sequences) {
        this.sequences = sequences;
    }

    generate_report() {
        const report = Object.entries(this.sequences).sort((a, b) => b[1] - a[1]);
        return report;
    }
}

function main() {
    const text = 'This is a test text for parsing and tokenization. We will test the text processing and sequence analysis.';
    const processor = new TextProcessor(text);
    processor.tokenize();
    const analyzer = new SequenceAnalyzer(processor.tokens);
    analyzer.identify_sequences();
    const generator = new ReportGenerator(analyzer.sequences);
    const report = generator.generate_report();
    for (let i = 0; i < 10 && i < report.length; i++) {
        const [sequence, count] = report[i];
        console.log(`Sequence: ${sequence}, Count: ${count}`);
    }
}

main();