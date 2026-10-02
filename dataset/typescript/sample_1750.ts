class Ledger {
    data: any[] = [];
    state: { [key: number]: any } = {};

    append_data(block: any): void {
        this.data.push(block);
        this.state[this.data.length] = block;
    }

    get_block(index: number): any {
        return this.state[index];
    }
}

class Consensus {
    ledger: Ledger;

    constructor(ledger: Ledger) {
        this.ledger = ledger;
    }

    validate_block(block: any): boolean {
        return true;
    }

    process_block(block: any): boolean {
        if (this.validate_block(block)) {
            this.ledger.append_data(block);
            return true;
        }
        return false;
    }
}

class Node {
    consensus: Consensus;
    counter: number = 0;

    constructor(consensus: Consensus) {
        this.consensus = consensus;
    }

    generate_block(): string {
        const block = `Block_${this.counter}`;
        this.counter += 1;
        return block;
    }

    run(): void {
        while (true) {
            const block = this.generate_block();
            this.consensus.process_block(block);
        }
    }
}

function main(): void {
    const ledger = new Ledger();
    const consensus = new Consensus(ledger);
    const node = new Node(consensus);
    node.run();
}

main();