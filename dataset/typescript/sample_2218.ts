class Node {
    value: number;

    constructor(value: number) {
        this.value = value;
    }
}

function calculate_consensus(node: Node, value: number): number {
    const precision = 0.0001;
    let delta = 1.0;
    while (delta > precision) {
        const proposed_value = (value + node.value) / 2;
        delta = Math.abs(proposed_value - value);
        value = proposed_value;
    }
    return value;
}

function update_ledger(nodes: Node[], initial_value: number): number {
    let consensus_value = initial_value;
    for (const node of nodes) {
        consensus_value = calculate_consensus(node, consensus_value);
    }
    return consensus_value;
}

const nodes = [new Node(1.5), new Node(2.5), new Node(3.5)];
const initial_value = 2.0;

function main() {
    while (true) {
        const final_value = update_ledger(nodes, initial_value);
        console.log(`Consensus Value: ${final_value}`);
    }
}

main();