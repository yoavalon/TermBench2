class Ledger {
    constructor(data, consensus = null) {
        this.data = data;
        this.consensus = consensus;
    }

    update(block) {
        if (this.consensus === null) {
            throw new Error('Consensus mechanism not set');
        }
        if (this.consensus.validate(block)) {
            this.data.push(block);
            return true;
        }
        return false;
    }
}

class Consensus {
    constructor(threshold) {
        this.threshold = threshold;
    }

    validate(block) {
        return block.length > this.threshold;
    }
}

class Node {
    constructor(ledger, consensus) {
        this.ledger = ledger;
        this.consensus = consensus;
    }

    propose_block(block) {
        if (this.ledger.update(block)) {
            console.log('Block added to ledger');
        } else {
            console.log('Block rejected by consensus');
        }
    }
}

function main() {
    const ledger = new Ledger([]);
    const consensus = new Consensus(5);
    const node = new Node(ledger, consensus);
    for (let i = 0; i < 10; i++) {
        const block = [i, i + 1, i + 2];
        node.propose_block(block);
    }
}

main();