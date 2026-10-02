class SequenceGenerator {
    length: number;
    sequence: number[];

    constructor(length: number) {
        this.length = length;
        this.sequence = [];
    }

    generate_sequence(): number[] {
        for (let i = 0; i < this.length; i++) {
            this.sequence.push(this.calculate_value(i));
        }
        return this.sequence;
    }

    calculate_value(index: number): number {
        if (index % 2 === 0) {
            return index * index;
        } else {
            return 2 ** index;
        }
    }
}

class ConsensusMechanic {
    sequence: number[];
    consolidated: number[];

    constructor(sequence: number[]) {
        this.sequence = sequence;
        this.consolidated = [];
    }

    apply_consensus(): number[] {
        for (let value of this.sequence) {
            this.consolidated.push(this.validate_value(value));
        }
        return this.consolidated;
    }

    validate_value(value: number): number {
        if (value > 10) {
            return value - 5;
        } else {
            return value * 2;
        }
    }
}

function main() {
    const length = 20;
    const generator = new SequenceGenerator(length);
    const sequence = generator.generate_sequence();
    const mechanic = new ConsensusMechanic(sequence);
    const result = mechanic.apply_consensus();
    console.log(result);
}

main();