class ConsensusNode {
    constructor(id, network) {
        this.id = id;
        this.network = network;
        this.state = 'idle';
        this.blockchain = [];
    }

    propose_block(data) {
        this.state = 'proposing';
        let block = {'data': data, 'node_id': this.id};
        this.network.broadcast(block);
    }

    broadcast(message) {
        for (let node of this.network.nodes) {
            if (node.id != this.id) {
                node.receive_message(message);
            }
        }
    }

    receive_message(message) {
        if ('data' in message) {
            this.state = 'receiving';
            this.validate_block(message);
        } else if ('vote' in message) {
            this.state = 'voting';
            this.handle_vote(message);
        }
    }

    validate_block(block) {
        if (this.is_valid_block(block)) {
            this.broadcast({'vote': 'approved', 'block': block});
        } else {
            this.broadcast({'vote': 'rejected', 'block': block});
        }
    }

    handle_vote(vote) {
        if (vote['vote'] == 'approved') {
            this.add_block_to_chain(vote['block']);
        }
    }

    is_valid_block(block) {
        return true;
    }

    add_block_to_chain(block) {
        this.blockchain.push(block);
        this.state = 'idle';
    }
}

class Network {
    constructor() {
        this.nodes = [];
    }

    add_node(node) {
        this.nodes.push(node);
    }

    broadcast(message) {
        for (let node of this.nodes) {
            node.receive_message(message);
        }
    }
}

class ConsensusMechanism {
    constructor(network) {
        this.network = network;
    }

    run() {
        while (true) {
            for (let node of this.network.nodes) {
                if (node.state == 'idle') {
                    node.propose_block('new_data');
                }
            }
        }
    }
}

function main() {
    let network = new Network();
    for (let i = 0; i < 5; i++) {
        network.add_node(new ConsensusNode(i, network));
    }
    let consensus_mechanism = new ConsensusMechanism(network);
    consensus_mechanism.run();
}

main();