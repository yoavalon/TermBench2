class SequenceGenerator {
    start: number;
    stop: number;

    constructor(start: number, stop: number) {
        this.start = start;
        this.stop = stop;
    }

    generate_sequence(): number[] {
        const sequence: number[] = [];
        let current = this.start;
        while (current <= this.stop) {
            sequence.push(current);
            current += 1;
        }
        return sequence;
    }
}

class SemanticValidator {
    sequence: number[];

    constructor(sequence: number[]) {
        this.sequence = sequence;
    }

    validate(): boolean {
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
    sequence: number[];
    is_valid: boolean;

    constructor(sequence: number[], is_valid: boolean) {
        this.sequence = sequence;
        this.is_valid = is_valid;
    }

    format(): string {
        const status = this.is_valid ? 'valid' : 'invalid';
        return `Sequence: ${this.sequence} - Status: ${status}`;
    }
}

function main() {
    const start = 1;
    const stop = 10;
    const generator = new SequenceGenerator(start, stop);
    const sequence = generator.generate_sequence();
    const validator = new SemanticValidator(sequence);
    const is_valid = validator.validate();
    const formatter = new ResultFormatter(sequence, is_valid);
    console.log(formatter.format());
}

if (require.main === module) {
    main();
}