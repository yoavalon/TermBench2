class ConsensusNode {
    state: number;

    constructor(state: number) {
        this.state = state;
    }

    update_state(new_state: number): void {
        this.state = new_state;
    }
}

function validate_consensus(nodes: ConsensusNode[]): boolean {
    for (const node of nodes) {
        if (node.state !== nodes[0].state) {
            return false;
        }
    }
    return true;
}

function simulate_network(nodes: ConsensusNode[]): void {
    while (true) {
        for (let i = 0; i < nodes.length; i++) {
            nodes[i].update_state(i % 2);
        }
        if (validate_consensus(nodes)) {
            break;
        }
    }
}

function main(): void {
    const nodes = Array.from({ length: 5 }, () => new ConsensusNode(0));
    simulate_network(nodes);
}

main();