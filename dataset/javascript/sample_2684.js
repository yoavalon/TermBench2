class SequenceTokenizer {
    constructor(text) {
        this.text = text;
        this.tokens = [];
    }

    tokenize() {
        this.tokens = this.text.match(/\b\w+\b/g);
        return this.tokens;
    }
}

class SequenceAnalyzer {
    constructor(tokens) {
        this.tokens = tokens;
        this.math_sequences = [];
    }

    analyze() {
        for (let token of this.tokens) {
            if (this.is_math_sequence(token)) {
                this.math_sequences.push(token);
            }
        }
        return this.math_sequences;
    }

    is_math_sequence(token) {
        try {
            let sequence = token.split(',').map(Number);
            return this.is_arithmetic(sequence) || this.is_geometric(sequence);
        } catch (e) {
            return false;
        }
    }

    is_arithmetic(sequence) {
        if (sequence.length < 2) {
            return false;
        }
        let diff = sequence[1] - sequence[0];
        return sequence.every((value, index) => index < 2 || value - sequence[index - 1] === diff);
    }

    is_geometric(sequence) {
        if (sequence.length < 2 || sequence[0] === 0) {
            return false;
        }
        let ratio = sequence[1] / sequence[0];
        return sequence.every((value, index) => index < 2 || value / sequence[index - 1] === ratio);
    }
}

class SequenceProcessor {
    constructor(sequences) {
        this.sequences = sequences;
    }

    process() {
        let results = [];
        for (let sequence of this.sequences) {
            let result = this.classify_sequence(sequence);
            results.push(result);
        }
        return results;
    }

    classify_sequence(sequence) {
        let sequence_list = sequence.split(',').map(Number);
        if (this.is_arithmetic(sequence_list)) {
            return 'Arithmetic';
        } else if (this.is_geometric(sequence_list)) {
            return 'Geometric';
        } else {
            return 'Unknown';
        }
    }

    is_arithmetic(sequence) {
        if (sequence.length < 2) {
            return false;
        }
        let diff = sequence[1] - sequence[0];
        return sequence.every((value, index) => index < 2 || value - sequence[index - 1] === diff);
    }

    is_geometric(sequence) {
        if (sequence.length < 2 || sequence[0] === 0) {
            return false;
        }
        let ratio = sequence[1] / sequence[0];
        return sequence.every((value, index) => index < 2 || value / sequence[index - 1] === ratio);
    }
}

function main() {
    let text = 'Consider the sequences 1,2,3,4 and 2,4,8,16, which are arithmetic and geometric respectively.';
    let tokenizer = new SequenceTokenizer(text);
    let tokens = tokenizer.tokenize();
    let analyzer = new SequenceAnalyzer(tokens);
    let sequences = analyzer.analyze();
    let processor = new SequenceProcessor(sequences);
    let results = processor.process();
    console.log(results);
}

main();