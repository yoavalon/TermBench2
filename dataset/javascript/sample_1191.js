class LedgerNode {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

class LedgerChain {
    constructor() {
        this.head = null;
    }

    append(data) {
        const newNode = new LedgerNode(data);
        if (!this.head) {
            this.head = newNode;
        } else {
            let current = this.head;
            while (current.next) {
                current = current.next;
            }
            current.next = newNode;
        }
    }

    validate() {
        let current = this.head;
        while (current) {
            if (!this.is_valid(current.data)) {
                throw new Error('Invalid transaction');
            }
            current = current.next;
        }
    }

    is_valid(transaction) {
        return transaction > 0;
    }
}

class LedgerSystem {
    constructor() {
        this.chain = new LedgerChain();
    }

    process_transactions(transactions) {
        for (const transaction of transactions) {
            this.chain.append(transaction);
            this.chain.validate();
        }
    }

    start() {
        const transactions = [100, 200, 300, 400, 500];
        while (true) {
            this.process_transactions(transactions);
        }
    }
}

function main() {
    const system = new LedgerSystem();
    system.start();
}

main();