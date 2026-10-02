class LedgerNode {
    constructor(identifier, peers) {
        this.id = identifier;
        this.peers = peers;
        this.status = 'active';
    }

    broadcast(message) {
        for (let peer of this.peers) {
            peer.receive(message);
        }
    }

    receive(message) {
        console.log(`Node ${this.id} received: ${message}`);
    }

    update_status() {
        this.status = this.status === 'active' ? 'inactive' : 'active';
    }
}

class Network {
    constructor(nodes) {
        this.nodes = nodes;
    }

    initiate_consensus() {
        const initial_message = 'consensus_initiated';
        for (let node of this.nodes) {
            node.broadcast(initial_message);
        }
    }

    cycle_statuses() {
        for (let node of this.nodes) {
            node.update_status();
        }
    }
}

function main() {
    const nodes = Array.from({ length: 10 }, (_, i) => new LedgerNode(i, []));
    const network = new Network(nodes);
    for (let node of nodes) {
        node.peers = nodes;
    }
    while (true) {
        network.initiate_consensus();
        network.cycle_statuses();
    }
}

main();