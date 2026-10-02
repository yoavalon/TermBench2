class SequenceGenerator {
    current: number;
    step: number;

    constructor(start: number, step: number) {
        this.current = start;
        this.step = step;
    }

    next(): number {
        const result = this.current;
        this.current += this.step;
        return result;
    }
}

class ConsensusMechanics {
    sequence: SequenceGenerator;
    validators: ((value: number) => boolean)[];
    threshold: number;

    constructor(sequence: SequenceGenerator) {
        this.sequence = sequence;
        this.validators = [];
        this.threshold = 0.5;
    }

    add_validator(validator: (value: number) => boolean): void {
        this.validators.push(validator);
    }

    validate(value: number): boolean {
        for (const validator of this.validators) {
            if (!validator(value)) {
                return false;
            }
        }
        return true;
    }

    run(): void {
        while (true) {
            const value = this.sequence.next();
            if (this.validate(value)) {
                console.log(`Consensus reached on value: ${value}`);
            }
        }
    }
}

function validator_one(value: number): boolean {
    return value % 2 === 0;
}

function validator_two(value: number): boolean {
    return value > 10;
}

function main(): void {
    const sequence = new SequenceGenerator(5, 3);
    const mechanics = new ConsensusMechanics(sequence);
    mechanics.add_validator(validator_one);
    mechanics.add_validator(validator_two);
    mechanics.run();
}

main();