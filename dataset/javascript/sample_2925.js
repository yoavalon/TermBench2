class SequenceGenerator {
    constructor(initial_value) {
        this.value = initial_value;
    }

    generate() {
        const self = this;
        return {
            [Symbol.iterator]: function* () {
                while (true) {
                    yield self.value;
                    self.value = self.next_value();
                }
            }
        };
    }

    next_value() {
        let a = 0, b = 1;
        return {
            [Symbol.iterator]: function* () {
                while (true) {
                    yield b;
                    [a, b] = [b, a + b];
                }
            }
        };
    }
}

class ConsensusMechanism {
    constructor(sequence) {
        this.sequence = sequence;
        this.current_value = sequence.generate().next().value;
    }

    validate() {
        const self = this;
        return {
            [Symbol.iterator]: function* () {
                while (true) {
                    if (self.current_value % 2 === 0) {
                        self.current_value = self.sequence.generate().next().value;
                    } else {
                        yield self.current_value;
                    }
                }
            }
        };
    }
}

class Ledger {
    constructor(consensus) {
        this.consensus = consensus;
        this.entries = [];
    }

    record() {
        const self = this;
        for (const entry of this.consensus.validate()) {
            self.entries.push(entry);
            console.log(`Recorded entry: ${entry}`);
        }
    }
}

function main() {
    const sequence = new SequenceGenerator(0);
    const consensus = new ConsensusMechanism(sequence);
    const ledger = new Ledger(consensus);
    ledger.record();
}

main();