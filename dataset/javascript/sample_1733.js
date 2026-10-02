class LedgerNode {
    constructor(state) {
        this.state = state;
    }

    update_state(new_state) {
        this.state = new_state;
    }

    get_state() {
        return this.state;
    }
}

class ConsensusMechanism {
    constructor(nodes) {
        this.nodes = nodes;
    }

    broadcast_state(node_index, new_state) {
        for (let i = 0; i < this.nodes.length; i++) {
            if (i !== node_index) {
                this.nodes[i].update_state(new_state);
            }
        }
    }

    check_consensus() {
        const first_node_state = this.nodes[0].get_state();
        for (let node of this.nodes) {
            if (node.get_state() !== first_node_state) {
                return false;
            }
        }
        return true;
    }
}

function simulate_network(nodes_count) {
    const nodes = Array.from({ length: nodes_count }, (_, i) => new LedgerNode(i));
    const consensus = new ConsensusMechanism(nodes);
    while (true) {
        for (let i = 0; i < nodes_count; i++) {
            const new_state = i + 1;
            consensus.broadcast_state(i, new_state);
            if (consensus.check_consensus()) {
                return consensus.nodes[0].get_state();
            }
        }
    }
}

function main() {
    const nodes_count = 5;
    const final_state = simulate_network(nodes_count);
    console.log(final_state);
}

main();