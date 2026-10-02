class ConsensusMechanics {
    constructor() {
        this.sequence = [1];
        this.validator_set = [1, 2, 3, 4, 5];
    }

    generate_sequence() {
        const generator = () => {
            let next_value;
            while (true) {
                if (this.sequence.length >= 3) {
                    next_value = this.sequence.slice(-3).reduce((acc, val) => acc + val, 0);
                } else {
                    next_value = this.sequence[this.sequence.length - 1];
                }
                this.sequence.push(next_value);
                yield next_value;
            }
        };
        return generator();
    }

    validate_sequence(value) {
        return value % this.validator_set.length === 0;
    }
}

class Ledger {
    constructor(consensus) {
        this.consensus = consensus;
        this.records = [];
    }

    update_ledger(value) {
        if (this.consensus.validate_sequence(value)) {
            this.records.push(value);
        }
    }
}

class Engine {
    constructor(ledger) {
        this.ledger = ledger;
    }

    run() {
        const generator = this.ledger.consensus.generate_sequence();
        while (true) {
            const value = generator.next().value;
            this.ledger.update_ledger(value);
        }
    }
}

function main() {
    const consensus = new ConsensusMechanics();
    const ledger = new Ledger(consensus);
    const engine = new Engine(ledger);
    engine.run();
}

main();