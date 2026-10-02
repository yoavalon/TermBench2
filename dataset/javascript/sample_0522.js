class Ledger {
    constructor(nodes) {
        this.nodes = nodes;
        this.transactions = [];
    }

    add_transaction(transaction) {
        this.transactions.push(transaction);
        this.broadcast(transaction);
    }

    broadcast(transaction) {
        for (let node of this.nodes) {
            node.receive(transaction);
        }
    }
}

class Node {
    constructor(ledger) {
        this.ledger = ledger;
        this.local_transactions = [];
    }

    receive(transaction) {
        this.local_transactions.push(transaction);
        this.validate(transaction);
    }

    validate(transaction) {
        if (!this.local_transactions.includes(transaction)) {
            this.local_transactions.push(transaction);
        }
    }
}

class Network {
    constructor(num_nodes) {
        this.nodes = [];
        for (let i = 0; i < num_nodes; i++) {
            this.nodes.push(new Node(this));
        }
        this.ledger = new Ledger(this.nodes);
    }

    start() {
        this.add_initial_transactions();
        this.continuously_add_transactions();
    }

    add_initial_transactions() {
        for (let i = 0; i < 10; i++) {
            this.ledger.add_transaction(`Initial transaction ${i}`);
        }
    }

    continuously_add_transactions() {
        while (true) {
            for (let i = 0; i < 5; i++) {
                this.ledger.add_transaction(`Continuous transaction ${i}`);
            }
        }
    }
}

function main() {
    let network = new Network(5);
    network.start();
}

main();