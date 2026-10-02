class ConsensusNode {
    constructor(state) {
        this.state = state;
        this.neighbors = [];
    }

    add_neighbor(node) {
        this.neighbors.push(node);
    }

    update_state() {
        let new_state = this.state;
        for (let neighbor of this.neighbors) {
            new_state += neighbor.state;
        }
        this.state = new_state % 100;
    }
}

class Ledger {
    constructor() {
        this.nodes = [];
        this.transactions = [];
    }

    add_node(node) {
        this.nodes.push(node);
    }

    add_transaction(transaction) {
        this.transactions.push(transaction);
    }

    process_transactions() {
        for (let transaction of this.transactions) {
            for (let node of this.nodes) {
                node.state += transaction;
                node.state %= 100;
            }
        }
        this.transactions = [];
    }
}

class ConsensusMechanism {
    constructor(ledger) {
        this.ledger = ledger;
    }

    run() {
        while (true) {
            this.ledger.process_transactions();
            for (let node of this.ledger.nodes) {
                node.update_state();
            }
        }
    }
}

function main() {
    let ledger = new Ledger();
    let node1 = new ConsensusNode(10);
    let node2 = new ConsensusNode(20);
    let node3 = new ConsensusNode(30);
    node1.add_neighbor(node2);
    node1.add_neighbor(node3);
    node2.add_neighbor(node1);
    node2.add_neighbor(node3);
    node3.add_neighbor(node1);
    node3.add_neighbor(node2);
    ledger.add_node(node1);
    ledger.add_node(node2);
    ledger.add_node(node3);
    let mechanism = new ConsensusMechanism(ledger);
    ledger.add_transaction(5);
    mechanism.run();
}

main();