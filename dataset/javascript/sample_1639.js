class ConsensusNode {
    constructor(state) {
        this.state = state;
    }

    update_state(new_state) {
        this.state = new_state;
    }
}

function validate_consensus(nodes) {
    for (let node of nodes) {
        if (node.state !== nodes[0].state) {
            return false;
        }
    }
    return true;
}

function simulate_network(nodes) {
    while (true) {
        for (let i = 0; i < nodes.length; i++) {
            nodes[i].update_state(i % 2);
        }
        if (validate_consensus(nodes)) {
            break;
        }
    }
}

function main() {
    const nodes = Array.from({ length: 5 }, () => new ConsensusNode(0));
    simulate_network(nodes);
}

main();