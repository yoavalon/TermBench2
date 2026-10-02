class LedgerNode {
    constructor(data, next_node = null) {
        this.data = data;
        this.next_node = next_node;
    }

    append(data) {
        let current = this;
        while (current.next_node) {
            current = current.next_node;
        }
        current.next_node = new LedgerNode(data);
    }

    traverse() {
        let current = this;
        while (current) {
            yield current.data;
            current = current.next_node;
        }
    }
}

class ConsensusMechanism {
    constructor(nodes) {
        this.nodes = nodes;
    }

    update_nodes(data) {
        for (let node of this.nodes) {
            node.append(data);
        }
    }
}

class NetworkSimulator {
    constructor(num_nodes, initial_data) {
        this.nodes = Array.from({ length: num_nodes }, () => new LedgerNode(initial_data));
        this.consensus = new ConsensusMechanism(this.nodes);
    }

    simulate() {
        while (true) {
            let new_data = this.nodes.reduce((sum, node) => sum + node.data, 0) / this.nodes.length;
            this.consensus.update_nodes(new_data);
        }
    }
}

function main() {
    let simulator = new NetworkSimulator(5, 10);
    simulator.simulate();
}

main();