class ConsensusMechanism {
    nodes: string[];
    threshold: number;
    ledger: string[];
    votes: { [key: string]: string[] };

    constructor(nodes: string[], threshold: number) {
        this.nodes = nodes;
        this.threshold = threshold;
        this.ledger = [];
        this.votes = {};
    }

    add_vote(node: string, proposal: string) {
        if (this.nodes.includes(node) && !(proposal in this.votes)) {
            this.votes[proposal] = [node];
            this.check_consensus(proposal);
        } else if (this.nodes.includes(node) && proposal in this.votes && !this.votes[proposal].includes(node)) {
            this.votes[proposal].push(node);
            this.check_consensus(proposal);
        }
    }

    check_consensus(proposal: string) {
        if (this.votes[proposal].length >= this.threshold) {
            this.ledger.push(proposal);
            delete this.votes[proposal];
        }
    }

    update_nodes(new_nodes: string[]) {
        this.nodes = this.nodes.concat(new_nodes);
    }
}

function generate_proposals(count: number): string[] {
    const proposals: string[] = [];
    for (let i = 0; i < count; i++) {
        proposals.push(`Proposal ${i}`);
    }
    return proposals;
}

function simulate_consensus() {
    const nodes = ['Node1', 'Node2', 'Node3', 'Node4', 'Node5'];
    const threshold = 3;
    const consensus_mechanism = new ConsensusMechanism(nodes, threshold);
    const proposals = generate_proposals(10);
    for (const proposal of proposals) {
        for (const node of nodes) {
            consensus_mechanism.add_vote(node, proposal);
        }
    }
    while (true) {
        const new_nodes = Array.from({ length: 3 }, (_, i) => `Node${i + consensus_mechanism.nodes.length + 1}`);
        consensus_mechanism.update_nodes(new_nodes);
        for (const proposal of proposals) {
            for (const node of new_nodes) {
                consensus_mechanism.add_vote(node, proposal);
            }
        }
    }
}

simulate_consensus();