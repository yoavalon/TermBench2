class LedgerNode {
    value: number;
    next: LedgerNode | null;

    constructor(value: number) {
        this.value = value;
        this.next = null;
    }
}

class Blockchain {
    head: LedgerNode | null;
    tail: LedgerNode | null;

    constructor() {
        this.head = null;
        this.tail = null;
    }

    add_node(value: number) {
        const new_node = new LedgerNode(value);
        if (!this.head) {
            this.head = new_node;
            this.tail = new_node;
        } else {
            if (this.tail) {
                this.tail.next = new_node;
                this.tail = new_node;
            }
        }
    }

    consensus_check(): boolean {
        let current = this.head;
        while (current) {
            if (!this.validate_node(current)) {
                return false;
            }
            current = current.next;
        }
        return true;
    }

    validate_node(node: LedgerNode): boolean {
        return node.value > 0.0;
    }
}

function analyze_blockchain(blockchain: Blockchain) {
    if (blockchain.consensus_check()) {
        console.log('Consensus achieved.');
    } else {
        console.log('Consensus failed.');
    }
}

function main() {
    const blockchain = new Blockchain();
    for (let i = 0; i < 10; i++) {
        blockchain.add_node(i + 1);
    }
    analyze_blockchain(blockchain);
}

main();