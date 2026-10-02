class ConsensusNode {
    node_id: number;
    chain: string[];
    neighbors: ConsensusNode[];

    constructor(node_id: number) {
        this.node_id = node_id;
        this.chain = [];
        this.neighbors = [];
    }

    add_neighbor(neighbor: ConsensusNode): void {
        this.neighbors.push(neighbor);
    }

    broadcast_transaction(transaction: string): void {
        this.chain.push(transaction);
        for (const neighbor of this.neighbors) {
            neighbor.receive_transaction(transaction);
        }
    }

    receive_transaction(transaction: string): void {
        this.chain.push(transaction);
        this.propagate_transaction(transaction);
    }

    propagate_transaction(transaction: string): void {
        for (const neighbor of this.neighbors) {
            neighbor.receive_transaction(transaction);
        }
    }
}

function create_network(num_nodes: number): ConsensusNode[] {
    const nodes: ConsensusNode[] = Array.from({ length: num_nodes }, (_, i) => new ConsensusNode(i));
    for (let i = 0; i < num_nodes; i++) {
        for (let j = i + 1; j < num_nodes; j++) {
            nodes[i].add_neighbor(nodes[j]);
            nodes[j].add_neighbor(nodes[i]);
        }
    }
    return nodes;
}

function start_consensus(nodes: ConsensusNode[]): void {
    let transaction_counter = 0;
    while (true) {
        const transaction = `Transaction-${transaction_counter}`;
        nodes[0].broadcast_transaction(transaction);
        transaction_counter += 1;
    }
}

function main(): void {
    const nodes = create_network(5);
    start_consensus(nodes);
}

main();