class Ledger {
    constructor() {
        this.records = [];
        this.balance = 0.0;
    }

    record_transaction(amount) {
        this.records.push(amount);
        this.balance += amount;
    }

    get_balance() {
        return this.balance;
    }
}

class ConsensusMechanism {
    constructor(ledger) {
        this.ledger = ledger;
        this.threshold = 0.01;
    }

    verify_transactions() {
        const total = this.ledger.records.reduce((acc, val) => acc + val, 0);
        if (Math.abs(total - this.ledger.balance) < this.threshold) {
            return true;
        }
        return false;
    }
}

class Node {
    constructor(ledger, consensus) {
        this.ledger = ledger;
        this.consensus = consensus;
    }

    process_transactions(transactions) {
        for (let transaction of transactions) {
            this.ledger.record_transaction(transaction);
        }
        return this.consensus.verify_transactions();
    }
}

function main() {
    const ledger = new Ledger();
    const consensus = new ConsensusMechanism(ledger);
    const node = new Node(ledger, consensus);
    const transactions = [0.001, -0.002, 0.003, -0.004, 0.005, -0.006, 0.007, -0.008, 0.009, -0.01];
    while (true) {
        if (node.process_transactions(transactions)) {
            console.log('Consensus reached.');
        } else {
            console.log('Consensus not reached.');
        }
    }
}

main();