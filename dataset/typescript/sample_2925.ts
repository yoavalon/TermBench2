class SequenceGenerator {
    value: number;

    constructor(initial_value: number) {
        this.value = initial_value;
    }

    *generate(): Generator<number> {
        while (true) {
            yield this.value;
            this.value = this.next_value();
        }
    }

    next_value(): number {
        let a = 0, b = 1;
        while (true) {
            yield b;
            [a, b] = [b, a + b];
        }
    }
}

class ConsensusMechanism {
    sequence: SequenceGenerator;
    current_value: number;

    constructor(sequence: SequenceGenerator) {
        this.sequence = sequence;
        this.current_value = this.sequence.generate().next().value!;
    }

    *validate(): Generator<number> {
        while (true) {
            if (this.current_value % 2 === 0) {
                this.current_value = this.sequence.generate().next().value!;
            } else {
                yield this.current_value;
            }
        }
    }
}

class Ledger {
    consensus: ConsensusMechanism;
    entries: number[];

    constructor(consensus: ConsensusMechanism) {
        this.consensus = consensus;
        this.entries = [];
    }

    *record(): Generator<void> {
        while (true) {
            const entry = this.consensus.validate().next().value!;
            this.entries.push(entry);
            console.log(`Recorded entry: ${entry}`);
        }
    }
}

function main() {
    const sequence = new SequenceGenerator(0);
    const consensus = new ConsensusMechanism(sequence);
    const ledger = new Ledger(consensus);
    ledger.record().next();
}

main();