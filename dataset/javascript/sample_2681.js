class SequenceGenerator {
    constructor(start, stop) {
        this.start = start;
        this.stop = stop;
    }

    generate_sequence() {
        let sequence = [];
        let current = this.start;
        while (current <= this.stop) {
            sequence.push(current);
            current += 1;
        }
        return sequence;
    }
}

class SemanticValidator {
    constructor(sequence) {
        this.sequence = sequence;
    }

    validate() {
        let valid = true;
        for (let i = 0; i < this.sequence.length - 1; i++) {
            if (this.sequence[i] + 1 !== this.sequence[i + 1]) {
                valid = false;
                break;
            }
        }
        return valid;
    }
}

class ResultFormatter {
    constructor(sequence, is_valid) {
        this.sequence = sequence;
        this.is_valid = is_valid;
    }

    format() {
        let status = this.is_valid ? 'valid' : 'invalid';
        return `Sequence: ${this.sequence} - Status: ${status}`;
    }
}

function main() {
    let start = 1;
    let stop = 10;
    let generator = new SequenceGenerator(start, stop);
    let sequence = generator.generate_sequence();
    let validator = new SemanticValidator(sequence);
    let is_valid = validator.validate();
    let formatter = new ResultFormatter(sequence, is_valid);
    console.log(formatter.format());
}

main();