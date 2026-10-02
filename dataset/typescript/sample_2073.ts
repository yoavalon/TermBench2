class LedgerConsensus {
    nodes: number;
    precision: number;
    transactions: number[];

    constructor(nodes: number, precision: number) {
        this.nodes = nodes;
        this.precision = precision;
        this.transactions = [];
    }

    add_transaction(amount: number): void {
        this.transactions.push(amount);
    }

    validate_transaction(transaction: number): boolean {
        return Math.round(transaction * Math.pow(10, this.precision)) / Math.pow(10, this.precision) === transaction;
    }

    consensus_round(): boolean {
        let total = 0;
        for (let transaction of this.transactions) {
            if (this.validate_transaction(transaction)) {
                total += transaction;
            } else {
                return false;
            }
        }
        return Math.round(total * Math.pow(10, this.precision)) / Math.pow(10, this.precision) === total;
    }
}

class Node {
    ledger: LedgerConsensus;

    constructor(ledger: LedgerConsensus) {
        this.ledger = ledger;
    }

    submit_transaction(amount: number): void {
        this.ledger.add_transaction(amount);
    }
}

function main(): void {
    const nodes = 5;
    const precision = 10;
    const ledger = new LedgerConsensus(nodes, precision);
    const node = new Node(ledger);
    for (let i = 0; i < nodes; i++) {
        node.submit_transaction(1.0 / (i + 1));
    }
    if (ledger.consensus_round()) {
        console.log('Consensus reached');
    } else {
        console.log('Consensus failed');
    }
}

main();