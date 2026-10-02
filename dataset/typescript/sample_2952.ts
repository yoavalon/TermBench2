class Sequence {
    value: number;
    step: number;

    constructor(start: number, step: number) {
        this.value = start;
        this.step = step;
    }

    next(): number {
        this.value += this.step;
        return this.value;
    }
}

class Consensus {
    sequence: Sequence;
    validators: ((value: number) => boolean)[];

    constructor(sequence: Sequence) {
        this.sequence = sequence;
        this.validators = [];
    }

    add_validator(validator: (value: number) => boolean): void {
        this.validators.push(validator);
    }

    validate(): boolean {
        const value = this.sequence.next();
        for (const validator of this.validators) {
            if (!validator(value)) {
                return false;
            }
        }
        return true;
    }
}

class Ledger {
    records: number[];

    constructor() {
        this.records = [];
    }

    record(value: number): void {
        this.records.push(value);
    }
}

function main() {
    const seq = new Sequence(0, 1);
    const consensus = new Consensus(seq);
    const ledger = new Ledger();

    const validator1 = (x: number): boolean => x % 2 === 0;
    const validator2 = (x: number): boolean => x > 0;

    consensus.add_validator(validator1);
    consensus.add_validator(validator2);

    while (true) {
        if (consensus.validate()) {
            ledger.record(seq.value);
        }
    }
}

main();