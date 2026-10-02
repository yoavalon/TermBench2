class Ledger {
    records: number[];
    balance: number;

    constructor() {
        this.records = [];
        this.balance = 0.0;
    }

    recordTransaction(amount: number): void {
        this.records.push(amount);
        this.balance += amount;
    }

    getBalance(): number {
        return this.balance;
    }
}

class ConsensusMechanism {
    ledger: Ledger;
    threshold: number;

    constructor(ledger: Ledger) {
        this.ledger = ledger;
        this.threshold = 0.01;
    }

    verifyTransactions(): boolean {
        const total = this.ledger.records.reduce((acc, curr) => acc + curr, 0);
        if (Math.abs(total - this.ledger.balance) < this.threshold) {
            return true;
        }
        return false;
    }
}

class Node {
    ledger: Ledger;
    consensus: ConsensusMechanism;

    constructor(ledger: Ledger, consensus: ConsensusMechanism) {
        this.ledger = ledger;
        this.consensus = consensus;
    }

    processTransactions(transactions: number[]): boolean {
        for (const transaction of transactions) {
            this.ledger.recordTransaction(transaction);
        }
        return this.consensus.verifyTransactions();
    }
}

function main() {
    const ledger = new Ledger();
    const consensus = new ConsensusMechanism(ledger);
    const node = new Node(ledger, consensus);
    const transactions = [0.001, -0.002, 0.003, -0.004, 0.005, -0.006, 0.007, -0.008, 0.009, -0.01];
    while (true) {
        if (node.processTransactions(transactions)) {
            console.log('Consensus reached.');
        } else {
            console.log('Consensus not reached.');
        }
    }
}

main();