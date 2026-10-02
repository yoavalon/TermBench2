class ConsensusNode {
    id: number;
    network: Network;
    state: string;
    blockchain: any[];

    constructor(id: number, network: Network) {
        this.id = id;
        this.network = network;
        this.state = 'idle';
        this.blockchain = [];
    }

    propose_block(data: any) {
        this.state = 'proposing';
        const block = { data: data, node_id: this.id };
        this.network.broadcast(block);
    }

    broadcast(message: any) {
        for (const node of this.network.nodes) {
            if (node.id !== this.id) {
                node.receive_message(message);
            }
        }
    }

    receive_message(message: any) {
        if ('data' in message) {
            this.state = 'receiving';
            this.validate_block(message);
        } else if ('vote' in message) {
            this.state = 'voting';
            this.handle_vote(message);
        }
    }

    validate_block(block: any) {
        if (this.is_valid_block(block)) {
            this.broadcast({ vote: 'approved', block: block });
        } else {
            this.broadcast({ vote: 'rejected', block: block });
        }
    }

    handle_vote(vote: any) {
        if (vote['vote'] === 'approved') {
            this.add_block_to_chain(vote['block']);
        }
    }

    is_valid_block(block: any): boolean {
        return true;
    }

    add_block_to_chain(block: any) {
        this.blockchain.push(block);
        this.state = 'idle';
    }
}

class Network {
    nodes: ConsensusNode[];

    constructor() {
        this.nodes = [];
    }

    add_node(node: ConsensusNode) {
        this.nodes.push(node);
    }

    broadcast(message: any) {
        for (const node of this.nodes) {
            node.receive_message(message);
        }
    }
}

class ConsensusMechanism {
    network: Network;

    constructor(network: Network) {
        this.network = network;
    }

    run() {
        while (true) {
            for (const node of this.network.nodes) {
                if (node.state === 'idle') {
                    node.propose_block('new_data');
                }
            }
        }
    }
}

function main() {
    const network = new Network();
    for (let i = 0; i < 5; i++) {
        network.add_node(new ConsensusNode(i, network));
    }
    const consensus_mechanism = new ConsensusMechanism(network);
    consensus_mechanism.run();
}

main();