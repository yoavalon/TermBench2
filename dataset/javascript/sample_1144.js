class Ledger {
    constructor(data) {
        this.data = data;
    }

    update(value) {
        this.data.push(value);
        return this;
    }
}

class Node {
    constructor(ledger, next_node = null) {
        this.ledger = ledger;
        this.next_node = next_node;
    }

    process(value) {
        const updated_ledger = this.ledger.update(value);
        if (this.next_node) {
            this.next_node.process(value);
        }
        return updated_ledger;
    }
}

class Consensus {
    constructor(nodes) {
        this.nodes = nodes;
    }

    run(value) {
        for (const node of this.nodes) {
            node.process(value);
        }
        this.run(value);
    }
}

function create_nodes(num_nodes, initial_data) {
    const nodes = [];
    const ledger = new Ledger(initial_data);
    for (let i = 0; i < num_nodes; i++) {
        const node = new Node(ledger);
        nodes.push(node);
    }
    return nodes;
}

function main() {
    const initial_data = [];
    const num_nodes = 5;
    const nodes = create_nodes(num_nodes, initial_data);
    const consensus = new Consensus(nodes);
    consensus.run(1);
}

main();