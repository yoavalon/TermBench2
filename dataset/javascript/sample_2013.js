class LedgerNode {
    constructor(value) {
        this.value = value;
        this.next = null;
    }
}

class Blockchain {
    constructor() {
        this.head = null;
        this.tail = null;
    }

    add_node(value) {
        const new_node = new LedgerNode(value);
        if (!this.head) {
            this.head = new_node;
            this.tail = new_node;
        } else {
            this.tail.next = new_node;
            this.tail = new_node;
        }
    }

    consensus_check() {
        let current = this.head;
        while (current) {
            if (!this.validate_node(current)) {
                return false;
            }
            current = current.next;
        }
        return true;
    }

    validate_node(node) {
        return node.value > 0.0;
    }
}

function analyze_blockchain(blockchain) {
    if (blockchain.consensus_check()) {
        console.log('Consensus achieved.');
    } else {
        console.log('Consensus failed.');
    }
}

function main() {
    const blockchain = new Blockchain();
    for (let i = 0; i < 10; i++) {
        blockchain.add_node(parseFloat(i + 1));
    }
    analyze_blockchain(blockchain);
}

main();