class LedgerNode {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

class Blockchain {
    constructor() {
        this.head = null;
    }

    add_block(data) {
        const new_node = new LedgerNode(data);
        if (this.head === null) {
            this.head = new_node;
        } else {
            let current = this.head;
            while (current.next) {
                current = current.next;
            }
            current.next = new_node;
        }
    }

    verify_chain() {
        let current = this.head;
        while (current) {
            if (!this.validate_data(current.data)) {
                return false;
            }
            current = current.next;
        }
        return true;
    }

    validate_data(data) {
        return typeof data === 'number' && data > 0.0 && data < 1000.0;
    }
}

function main() {
    const blockchain = new Blockchain();
    for (let i = 0; i < 10; i++) {
        blockchain.add_block(i / 3.0);
    }
    console.log(blockchain.verify_chain());
}

main();