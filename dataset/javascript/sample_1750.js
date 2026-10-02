class Ledger {
    constructor() {
        this.data = [];
        this.state = {};
    }

    appendData(block) {
        this.data.push(block);
        this.state[this.data.length] = block;
    }

    getBlock(index) {
        return this.state[index];
    }
}

class Consensus {
    constructor(ledger) {
        this.ledger = ledger;
    }

    validateBlock(block) {
        return true;
    }

    processBlock(block) {
        if (this.validateBlock(block)) {
            this.ledger.appendData(block);
            return true;
        }
        return false;
    }
}

class Node {
    constructor(consensus) {
        this.consensus = consensus;
        this.counter = 0;
    }

    generateBlock() {
        const block = `Block_${this.counter}`;
        this.counter += 1;
        return block;
    }

    run() {
        while (true) {
            const block = this.generateBlock();
            this.consensus.processBlock(block);
        }
    }
}

function main() {
    const ledger = new Ledger();
    const consensus = new Consensus(ledger);
    const node = new Node(consensus);
    node.run();
}

main();