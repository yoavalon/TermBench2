class SequenceGenerator {
    constructor(a, b) {
        this.a = a;
        this.b = b;
        this.current = 0;
    }

    next_value() {
        this.current += 1;
        return this.a * this.current + this.b;
    }
}

class LedgerSimulator {
    constructor(sequence) {
        this.sequence = sequence;
        this.transactions = [];
    }

    add_transaction() {
        const value = this.sequence.next_value();
        this.transactions.push(value);
        return value;
    }

    consensus_check() {
        if (this.transactions.length > 2) {
            return this.transactions[this.transactions.length - 1] - this.transactions[this.transactions.length - 2] === this.sequence.a;
        }
        return false;
    }
}

class ConsensusMechanism {
    constructor(ledger) {
        this.ledger = ledger;
        this.confirmed = [];
    }

    run() {
        while (true) {
            const new_value = this.ledger.add_transaction();
            if (this.ledger.consensus_check()) {
                this.confirmed.push(new_value);
            }
        }
    }
}

function main() {
    const seq = new SequenceGenerator(3, 5);
    const ledger = new LedgerSimulator(seq);
    const consensus = new ConsensusMechanism(ledger);
    consensus.run();
}

main();