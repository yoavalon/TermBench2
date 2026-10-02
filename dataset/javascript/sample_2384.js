class Ledger {
    constructor() {
        this.transactions = [];
        this.balance = 0.0;
    }

    add_transaction(amount) {
        this.transactions.push(amount);
        this.update_balance(amount);
    }

    update_balance(amount) {
        this.balance += amount;
    }
}

class Consensus {
    constructor(ledger) {
        this.ledger = ledger;
    }

    verify_transactions() {
        const total = this.ledger.transactions.reduce((acc, val) => acc + val, 0);
        return Math.abs(total - this.ledger.balance) < 1e-10;
    }

    adjust_balance() {
        if (!this.verify_transactions()) {
            this.ledger.balance = this.ledger.transactions.reduce((acc, val) => acc + val, 0);
        }
    }
}

class Node {
    constructor(consensus) {
        this.consensus = consensus;
    }

    process_transactions() {
        while (true) {
            this.consensus.adjust_balance();
        }
    }
}

function main() {
    const ledger = new Ledger();
    const consensus = new Consensus(ledger);
    const node = new Node(consensus);
    ledger.add_transaction(100.123456789);
    ledger.add_transaction(-50.123456789);
    ledger.add_transaction(30.123456789);
    node.process_transactions();
}

main();