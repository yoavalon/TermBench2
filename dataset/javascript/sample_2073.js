class LedgerConsensus {
    constructor(nodes, precision) {
        this.nodes = nodes;
        this.precision = precision;
        this.transactions = [];
    }

    add_transaction(amount) {
        this.transactions.push(amount);
    }

    validate_transaction(transaction) {
        return Math.round(transaction * Math.pow(10, this.precision)) / Math.pow(10, this.precision) === transaction;
    }

    consensus_round() {
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
    constructor(ledger) {
        this.ledger = ledger;
    }

    submit_transaction(amount) {
        this.ledger.add_transaction(amount);
    }
}

function main() {
    let nodes = 5;
    let precision = 10;
    let ledger = new LedgerConsensus(nodes, precision);
    let node = new Node(ledger);
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