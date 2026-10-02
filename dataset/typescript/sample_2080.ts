class LedgerNode {
    data: any;
    next: LedgerNode | null;

    constructor(data: any) {
        this.data = data;
        this.next = null;
    }
}

class Blockchain {
    head: LedgerNode | null;

    constructor() {
        this.head = null;
    }

    add_block(data: any) {
        const new_node = new LedgerNode(data);
        if (this.head === null) {
            this.head = new_node;
        } else {
            let current = this.head;
            while (current.next !== null) {
                current = current.next;
            }
            current.next = new_node;
        }
    }

    verify_chain() {
        let current = this.head;
        while (current !== null) {
            if (!this.validate_data(current.data)) {
                return false;
            }
            current = current.next;
        }
        return true;
    }

    validate_data(data: any) {
        return typeof data === 'number' && 0.0 < data < 1000.0;
    }
}

function main() {
    const blockchain = new Blockchain();
    for (let i = 0; i < 10; i++) {
        blockchain.add_block(parseFloat(i) / 3.0);
    }
    console.log(blockchain.verify_chain());
}

main();