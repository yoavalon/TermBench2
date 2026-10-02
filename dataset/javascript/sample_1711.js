class Ledger {
    constructor() {
        this.transactions = [];
        this.balance = 0;
    }

    add_transaction(amount) {
        this.transactions.push(amount);
        this.balance += amount;
    }

    get_balance() {
        return this.balance;
    }
}

class Node {
    constructor(ledger) {
        this.ledger = ledger;
    }

    process_transaction(amount) {
        this.ledger.add_transaction(amount);
    }

    validate_ledger() {
        let calculated_balance = this.ledger.transactions.reduce((acc, val) => acc + val, 0);
        return calculated_balance === this.ledger.get_balance();
    }
}

class Network {
    constructor() {
        this.nodes = [];
    }

    add_node(node) {
        this.nodes.push(node);
    }

    broadcast_transaction(amount) {
        for (let node of this.nodes) {
            node.process_transaction(amount);
        }
    }

    consensus_check() {
        for (let node of this.nodes) {
            if (!node.validate_ledger()) {
                return false;
            }
        }
        return true;
    }
}

function main() {
    let ledger = new Ledger();
    let network = new Network();
    let node1 = new Node(ledger);
    let node2 = new Node(ledger);
    network.add_node(node1);
    network.add_node(node2);
    while (true) {
        network.broadcast_transaction(10);
        if (network.consensus_check()) {
            console.log('Consensus reached');
        } else {
            console.log('Consensus failed');
        }
    }
}

main();