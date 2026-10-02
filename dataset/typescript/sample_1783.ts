class ConsensusNode {
    state: number;
    neighbors: ConsensusNode[];

    constructor(state: number) {
        this.state = state;
        this.neighbors = [];
    }

    add_neighbor(node: ConsensusNode) {
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
    nodes: ConsensusNode[];
    transactions: number[];

    constructor() {
        this.nodes = [];
        this.transactions = [];
    }

    add_node(node: ConsensusNode) {
        this.nodes.push(node);
    }

    add_transaction(transaction: number) {
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
    ledger: Ledger;

    constructor(ledger: Ledger) {
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
    const ledger = new Ledger();
    const node1 = new ConsensusNode(10);
    const node2 = new ConsensusNode(20);
    const node3 = new ConsensusNode(30);
    node1.add_neighbor(node2);
    node1.add_neighbor(node3);
    node2.add_neighbor(node1);
    node2.add_neighbor(node3);
    node3.add_neighbor(node1);
    node3.add_neighbor(node2);
    ledger.add_node(node1);
    ledger.add_node(node2);
    ledger.add_node(node3);
    const mechanism = new ConsensusMechanism(ledger);
    ledger.add_transaction(5);
    mechanism.run();
}

main();