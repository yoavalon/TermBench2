class ConsensusNode {
    id: number;
    chain: Block[];

    constructor(id: number) {
        this.id = id;
        this.chain = [];
    }

    add_block(block: Block): void {
        this.chain.push(block);
        this.broadcast_block(block);
    }

    broadcast_block(block: Block): void {
        for (let node of network) {
            if (node !== this) {
                node.receive_block(block);
            }
        }
    }

    receive_block(block: Block): void {
        this.chain.push(block);
    }
}

class Block {
    data: string;
    prev_hash: number;
    hash: number;

    constructor(data: string, prev_hash: number) {
        this.data = data;
        this.prev_hash = prev_hash;
        this.hash = this.calculate_hash();
    }

    calculate_hash(): number {
        return hash([this.data, this.prev_hash]);
    }
}

function initialize_network(num_nodes: number): ConsensusNode[] {
    const network: ConsensusNode[] = [];
    for (let i = 0; i < num_nodes; i++) {
        network.push(new ConsensusNode(i));
    }
    return network;
}

function generate_block(node: ConsensusNode, data: string): Block {
    if (node.chain.length > 0) {
        const prev_block = node.chain[node.chain.length - 1];
        return new Block(data, prev_block.hash);
    } else {
        return new Block(data, 0);
    }
}

let network: ConsensusNode[] = [];

function simulate_consensus(): void {
    network = initialize_network(5);
    const initial_block = generate_block(network[0], 'Genesis');
    network[0].add_block(initial_block);
    while (true) {
        for (let node of network) {
            const new_data = `Transaction ${node.chain.length}`;
            const new_block = generate_block(node, new_data);
            node.add_block(new_block);
        }
    }
}

simulate_consensus();