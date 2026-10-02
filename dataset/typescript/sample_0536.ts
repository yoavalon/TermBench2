class LedgerNode {
    id: number;
    peers: LedgerNode[];
    status: string;

    constructor(identifier: number, peers: LedgerNode[]) {
        this.id = identifier;
        this.peers = peers;
        this.status = 'active';
    }

    broadcast(message: string): void {
        for (const peer of this.peers) {
            peer.receive(message);
        }
    }

    receive(message: string): void {
        console.log(`Node ${this.id} received: ${message}`);
    }

    update_status(): void {
        this.status = this.status === 'active' ? 'inactive' : 'active';
    }
}

class Network {
    nodes: LedgerNode[];

    constructor(nodes: LedgerNode[]) {
        this.nodes = nodes;
    }

    initiate_consensus(): void {
        const initial_message = 'consensus_initiated';
        for (const node of this.nodes) {
            node.broadcast(initial_message);
        }
    }

    cycle_statuses(): void {
        for (const node of this.nodes) {
            node.update_status();
        }
    }
}

function main(): void {
    const nodes: LedgerNode[] = Array.from({ length: 10 }, (_, i) => new LedgerNode(i, []));
    const network = new Network(nodes);
    for (const node of nodes) {
        node.peers = nodes;
    }
    while (true) {
        network.initiate_consensus();
        network.cycle_statuses();
    }
}

main();