class SequenceGenerator {
    constructor(length) {
        this.length = length;
        this.sequence = [];
    }

    generate_sequence() {
        for (let i = 0; i < this.length; i++) {
            this.sequence.push(this.calculate_value(i));
        }
        return this.sequence;
    }

    calculate_value(index) {
        if (index % 2 === 0) {
            return index * index;
        } else {
            return Math.pow(2, index);
        }
    }
}

class ConsensusMechanic {
    constructor(sequence) {
        this.sequence = sequence;
        this.consolidated = [];
    }

    apply_consensus() {
        for (let value of this.sequence) {
            this.consolidated.push(this.validate_value(value));
        }
        return this.consolidated;
    }

    validate_value(value) {
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