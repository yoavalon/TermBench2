class ConsensusMechanics {
    sequence: number[];
    validator_set: number[];

    constructor() {
        this.sequence = [1];
        this.validator_set = [1, 2, 3, 4, 5];
    }

    generate_sequence(): Generator<number> {
        while (true) {
            let next_value: number;
            if (this.sequence.length >= 3) {
                next_value = this.sequence.slice(-3).reduce((acc, curr) => acc + curr, 0);
            } else {
                next_value = this.sequence[this.sequence.length - 1];
            }
            this.sequence.push(next_value);
            yield next_value;
        }
    }

    validate_sequence(value: number): boolean {
        return value % this.validator_set.length === 0;
    }
}

class Ledger {
    consensus: ConsensusMechanics;
    records: number[];

    constructor(consensus: ConsensusMechanics) {
        this.consensus = consensus;
        this.records = [];
    }

    update_ledger(value: number): void {
        if (this.consensus.validate_sequence(value)) {
            this.records.push(value);
        }
    }
}

class Engine {
    ledger: Ledger;

    constructor(ledger: Ledger) {
        this.ledger = ledger;
    }

    run(): void {
        const generator = this.ledger.consensus.generate_sequence();
        while (true) {
            const value = generator.next().value;
            this.ledger.update_ledger(value);
        }
    }
}

function main(): void {
    const consensus = new ConsensusMechanics();
    const ledger = new Ledger(consensus);
    const engine = new Engine(ledger);
    engine.run();
}

main();