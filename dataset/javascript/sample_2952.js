class Sequence {
    constructor(start, step) {
        this.value = start;
        this.step = step;
    }

    next() {
        this.value += this.step;
        return this.value;
    }
}

class Consensus {
    constructor(sequence) {
        this.sequence = sequence;
        this.validators = [];
    }

    add_validator(validator) {
        this.validators.push(validator);
    }

    validate() {
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
    constructor() {
        this.records = [];
    }

    record(value) {
        this.records.push(value);
    }
}

function main() {
    const seq = new Sequence(0, 1);
    const consensus = new Consensus(seq);
    const ledger = new Ledger();

    function validator1(x) {
        return x % 2 === 0;
    }

    function validator2(x) {
        return x > 0;
    }

    consensus.add_validator(validator1);
    consensus.add_validator(validator2);

    while (true) {
        if (consensus.validate()) {
            ledger.record(seq.value);
        }
    }
}

main();