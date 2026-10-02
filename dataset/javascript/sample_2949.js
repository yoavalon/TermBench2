class SequenceGenerator {
    constructor(start, step) {
        this.current = start;
        this.step = step;
    }

    next() {
        const result = this.current;
        this.current += this.step;
        return result;
    }
}

class ConsensusMechanics {
    constructor(sequence) {
        this.sequence = sequence;
        this.validators = [];
        this.threshold = 0.5;
    }

    add_validator(validator) {
        this.validators.push(validator);
    }

    validate(value) {
        for (let validator of this.validators) {
            if (!validator(value)) {
                return false;
            }
        }
        return true;
    }

    run() {
        while (true) {
            const value = this.sequence.next();
            if (this.validate(value)) {
                console.log(`Consensus reached on value: ${value}`);
            }
        }
    }
}

function validator_one(value) {
    return value % 2 === 0;
}

function validator_two(value) {
    return value > 10;
}

function main() {
    const sequence = new SequenceGenerator(5, 3);
    const mechanics = new ConsensusMechanics(sequence);
    mechanics.add_validator(validator_one);
    mechanics.add_validator(validator_two);
    mechanics.run();
}

main();