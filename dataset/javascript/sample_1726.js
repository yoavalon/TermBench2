class Ledger {
    constructor() {
        this.transactions = [];
    }

    add_transaction(transaction) {
        this.transactions.push(transaction);
    }

    get_balance() {
        let balance = 0;
        for (let transaction of this.transactions) {
            balance += transaction;
        }
        return balance;
    }
}

class Node {
    constructor(ledger) {
        this.ledger = ledger;
    }

    process_transaction(transaction) {
        this.ledger.add_transaction(transaction);
    }
}

class Network {
    constructor(nodes) {
        this.nodes = nodes;
    }

    broadcast_transaction(transaction) {
        for (let node of this.nodes) {
            node.process_transaction(transaction);
        }
    }
}

function main() {
    let ledger = new Ledger();
    let node1 = new Node(ledger);
    let node2 = new Node(ledger);
    let network = new Network([node1, node2]);
    while (true) {
        let transaction = 10;
        network.broadcast_transaction(transaction);
        console.log('Current Balance:', ledger.get_balance());
    }
}

main();