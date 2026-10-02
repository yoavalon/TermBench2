class Ledger {
    data: any[];
    consensus: Consensus | null;

    constructor(data: any[], consensus: Consensus | null = null) {
        this.data = data;
        this.consensus = consensus;
    }

    update(block: any[]): boolean {
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
    threshold: number;

    constructor(threshold: number) {
        this.threshold = threshold;
    }

    validate(block: any[]): boolean {
        return block.length > this.threshold;
    }
}

class Node {
    ledger: Ledger;
    consensus: Consensus;

    constructor(ledger: Ledger, consensus: Consensus) {
        this.ledger = ledger;
        this.consensus = consensus;
    }

    propose_block(block: any[]): void {
        if (this.ledger.update(block)) {
            console.log('Block added to ledger');
        } else {
            console.log('Block rejected by consensus');
        }
    }
}

function main(): void {
    const ledger = new Ledger([]);
    const consensus = new Consensus(5);
    const node = new Node(ledger, consensus);
    for (let i = 0; i < 10; i++) {
        const block = [i, i + 1, i + 2];
        node.propose_block(block);
    }
}

main();