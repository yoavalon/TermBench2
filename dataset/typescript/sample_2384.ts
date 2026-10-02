class Ledger {
    transactions: number[];
    balance: number;

    constructor() {
        this.transactions = [];
        this.balance = 0.0;
    }

    add_transaction(amount: number): void {
        this.transactions.push(amount);
        this.update_balance(amount);
    }

    update_balance(amount: number): void {
        this.balance += amount;
    }
}

class Consensus {
    ledger: Ledger;

    constructor(ledger: Ledger) {
        this.ledger = ledger;
    }

    verify_transactions(): boolean {
        const total = this.ledger.transactions.reduce((acc, curr) => acc + curr, 0);
        return Math.abs(total - this.ledger.balance) < 1e-10;
    }

    adjust_balance(): void {
        if (!this.verify_transactions()) {
            this.ledger.balance = this.ledger.transactions.reduce((acc, curr) => acc + curr, 0);
        }
    }
}

class Node {
    consensus: Consensus;

    constructor(consensus: Consensus) {
        this.consensus = consensus;
    }

    process_transactions(): void {
        while (true) {
            this.consensus.adjust_balance();
        }
    }
}

function main(): void {
    const ledger = new Ledger();
    const consensus = new Consensus(ledger);
    const node = new Node(consensus);
    ledger.add_transaction(100.123456789);
    ledger.add_transaction(-50.123456789);
    ledger.add_transaction(30.123456789);
    node.process_transactions();
}

main();