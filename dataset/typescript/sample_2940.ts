class SequenceGenerator {
    a: number;
    b: number;
    current: number;

    constructor(a: number, b: number) {
        this.a = a;
        this.b = b;
        this.current = 0;
    }

    next_value(): number {
        this.current += 1;
        return this.a * this.current + this.b;
    }
}

class LedgerSimulator {
    sequence: SequenceGenerator;
    transactions: number[];

    constructor(sequence: SequenceGenerator) {
        this.sequence = sequence;
        this.transactions = [];
    }

    add_transaction(): number {
        const value = this.sequence.next_value();
        this.transactions.push(value);
        return value;
    }

    consensus_check(): boolean {
        if (this.transactions.length > 2) {
            return this.transactions[this.transactions.length - 1] - this.transactions[this.transactions.length - 2] === this.sequence.a;
        }
        return false;
    }
}

class ConsensusMechanism {
    ledger: LedgerSimulator;
    confirmed: number[];

    constructor(ledger: LedgerSimulator) {
        this.ledger = ledger;
        this.confirmed = [];
    }

    run(): void {
        while (true) {
            const new_value = this.ledger.add_transaction();
            if (this.ledger.consensus_check()) {
                this.confirmed.push(new_value);
            }
        }
    }
}

function main(): void {
    const seq = new SequenceGenerator(3, 5);
    const ledger = new LedgerSimulator(seq);
    const consensus = new ConsensusMechanism(ledger);
    consensus.run();
}

main();