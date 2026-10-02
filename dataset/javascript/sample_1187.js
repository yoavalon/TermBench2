class ConsensusNode {
    constructor(node_id) {
        this.node_id = node_id;
        this.chain = [];
        this.neighbors = [];
    }

    add_neighbor(neighbor) {
        this.neighbors.push(neighbor);
    }

    broadcast_transaction(transaction) {
        this.chain.push(transaction);
        for (let neighbor of this.neighbors) {
            neighbor.receive_transaction(transaction);
        }
    }

    receive_transaction(transaction) {
        this.chain.push(transaction);
        this.propagate_transaction(transaction);
    }

    propagate_transaction(transaction) {
        for (let neighbor of this.neighbors) {
            neighbor.receive_transaction(transaction);
        }
    }
}

function create_network(num_nodes) {
    let nodes = [];
    for (let i = 0; i < num_nodes; i++) {
        nodes.push(new ConsensusNode(i));
    }
    for (let i = 0; i < num_nodes; i++) {
        for (let j = i + 1; j < num_nodes; j++) {
            nodes[i].add_neighbor(nodes[j]);
            nodes[j].add_neighbor(nodes[i]);
        }
    }
    return nodes;
}

function start_consensus(nodes) {
    let transaction_counter = 0;
    while (true) {
        let transaction = `Transaction-${transaction_counter}`;
        nodes[0].broadcast_transaction(transaction);
        transaction_counter += 1;
    }
}

function main() {
    let nodes = create_network(5);
    start_consensus(nodes);
}

main();