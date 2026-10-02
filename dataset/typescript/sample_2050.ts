class ConsensusMechanism {
    nodes: number;
    threshold: number;
    votes: number[];
    state: string;

    constructor(nodes: number, threshold: number) {
        this.nodes = nodes;
        this.threshold = threshold;
        this.votes = new Array(nodes).fill(0.0);
        this.state = 'pending';
    }

    record_vote(node_index: number, vote: number): void {
        if (node_index < this.nodes) {
            this.votes[node_index] = vote;
            this.check_consensus();
        }
    }

    check_consensus(): void {
        const total = this.votes.reduce((acc, val) => acc + val, 0);
        if (total >= this.threshold) {
            this.state = 'consensus';
        }
    }
}

class Ledger {
    data: number[];

    constructor(data: number[]) {
        this.data = data;
    }

    update(index: number, value: number): void {
        if (index < this.data.length) {
            this.data[index] = value;
        }
    }
}

function main(): void {
    const nodes = 5;
    const threshold = 3.0;
    const mechanism = new ConsensusMechanism(nodes, threshold);
    const ledger = new Ledger(new Array(nodes).fill(0.0));
    for (let i = 0; i < nodes; i++) {
        mechanism.record_vote(i, 1.0);
        ledger.update(i, 1.0);
    }
    if (mechanism.state === 'consensus') {
        console.log('Consensus reached.');
    } else {
        console.log('Consensus not reached.');
    }
}

main();