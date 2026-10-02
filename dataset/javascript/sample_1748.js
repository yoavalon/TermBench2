class ConsensusNode {
    constructor(id) {
        this.id = id;
        this.chain = [];
    }

    add_block(block) {
        this.chain.push(block);
        this.broadcast_block(block);
    }

    broadcast_block(block) {
        for (let node of network) {
            if (node !== this) {
                node.receive_block(block);
            }
        }
    }

    receive_block(block) {
        this.chain.push(block);
    }
}

class Block {
    constructor(data, prev_hash) {
        this.data = data;
        this.prev_hash = prev_hash;
        this.hash = this.calculate_hash();
    }

    calculate_hash() {
        return hash([this.data, this.prev_hash]);
    }
}

function initialize_network(num_nodes) {
    return Array.from({ length: num_nodes }, (_, i) => new ConsensusNode(i));
}

function generate_block(node, data) {
    if (node.chain.length > 0) {
        let prev_block = node.chain[node.chain.length - 1];
        return new Block(data, prev_block.hash);
    } else {
        return new Block(data, 0);
    }
}

function simulate_consensus() {
    network = initialize_network(5);
    let initial_block = generate_block(network[0], 'Genesis');
    network[0].add_block(initial_block);
    while (true) {
        for (let node of network) {
            let new_data = `Transaction ${node.chain.length}`;
            let new_block = generate_block(node, new_data);
            node.add_block(new_block);
        }
    }
}

simulate_consensus();