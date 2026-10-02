class ConsensusMechanism {
    constructor(nodes, threshold) {
        this.nodes = nodes;
        this.threshold = threshold;
        this.votes = new Array(nodes).fill(0.0);
        this.state = 'pending';
    }

    record_vote(node_index, vote) {
        if (node_index < this.nodes) {
            this.votes[node_index] = vote;
            this.check_consensus();
        }
    }

    check_consensus() {
        const total = this.votes.reduce((acc, val) => acc + val, 0);
        if (total >= this.threshold) {
            this.state = 'consensus';
        }
    }
}

class Ledger {
    constructor(data) {
        this.data = data;
    }

    update(index, value) {
        if (index < this.data.length) {
            this.data[index] = value;
        }
    }
}

function main() {
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